%{
#include <stdio.h>    
#include <string.h>
extern FILE  *yyin;

int yylex (void);
int yyerror(char *msg);

void prueba();


int Dibujar=0, Recursion=0,MaxRecursion;
char *Lexema[100], *Token[100];
int SubIndice=0, SubIndiceMax, NumLineas=1, EstadoScanner=0;
%}

%union{
    int digitos;
    char *letras;
    char *fileeId;
}
%token <letras> ID_COMPUTER
%token <fileeId> ID_FILE
%token NL SOURCE COMPUTER OBJECT
%token CONFIGURATION SECTION DOT TAB
%token DIVISION ENVIROMENT DATA CONTROL
%token FCTRL FCENT FILEM CTRL
%token DESCRIPTION FD WORKSTGSEC
%start mi_axioma
%%

mi_axioma: cobol-source-program | mi_axioma cobol-source-program
;
cobol-source-program: 
                    | ENVIROMENT DIVISION DOT NL enviroment-division-content  {/*DibujarTodo(1);*/}                 
                    | DATA DIVISION DOT NL data-division-content {DibujarTodo(2);}
                    
;
enviroment-division-content: NL
                           | configuration-section 
                           | input-output-section  
                           | configuration-section input-output-section                       
;
configuration-section: CONFIGURATION SECTION DOT NL configuration-section-paragraphs 
                     | CONFIGURATION SECTION DOT NL error 
;
data-division-content: NL {/*Esto me permite obviar el dar el contenido de data division*/}
                     | FILEM  SECTION DOT file-description-entry 
;

file-description-entry: {/*Esta vacio por prueba*/}
                      | FILEM SECTION DOT NL FD ID_FILE WORKSTGSEC
;
input-output-section: FILEM  CONTROL DOT file-control-entry 
;

file-control-entry: ID_FILE DOT ID_FILE
;

configuration-section-paragraphs: 
                                | SOURCE COMPUTER DOT ID_COMPUTER DOT
                                | OBJECT COMPUTER DOT ID_COMPUTER DOT
                                | SOURCE COMPUTER DOT ID_COMPUTER DOT NL OBJECT COMPUTER DOT ID_COMPUTER DOT
;

%%

void prueba(){ 
    printf("Esta todo en orden \n");
}

int yyerror(char *msg){
    
    char *messageP;
    if(msg == "Syntax error"){
        printf("\n ASDASD \n");
    }
    
    printf("\n Error encontrado!"); 
    printf("\n Error tipo: %s \n", msg);
    // yyparse();
}

int main(int argc, char **argv){
    
    if (argc > 1) yyin = fopen(argv[1], "rt");
    else {
        yyin = stdin;
        printf("\n Para respetar correctamente el formato de input de COBOL. Lea el documento LEER.txt \n");
        printf("Si no se respecta correctamente, va a fallar, sin importar que tan correcta sea la estructura.\n");
        printf("\n\n.............................................\n\n");
        }

    
    yyparse();
    
    return 0;
}
int yywrap() {
	EstadoScanner=2;
	printf("El analisis ha concluido\n");
	return 1;
}

int DibujarTodo(int SubParam){
	// DibujarTablaDeTokens();
	DibujarArbolDeDerivacion(SubParam);
	return 0;
}

int DibujarArbolDeDerivacion(int SubTipo){
	int ContAuxT,ContAuxK;
	int LargoPalabra;

/* la pantalla tiene un maximo de 1-79 caracteres */
	printf("-----------------------------ARBOL DE DERIVACIONES-----------------------------\n\n");
	printf("                          discriminant_specification\n");
	printf("                                       |\n");

	switch (SubTipo){
		case 1:
			printf("                              ---------+--------------\n");
			printf("                              |              |       |\n");
			printf("                   defining_identifier_list \":\" subtype_mark\n");
			printf("                              |                      |\n");
			if (SubIndiceMax==3){
				EscribirCentrado(31,"def_id",54,Token[2],0);
				printf("                              |                      |\n");
				EscribirCentrado(31,Token[0],54,Lexema[2],0);
				printf("                              |\n");
				EscribirCentrado(31,Lexema[0],0);}
			else{
				printf("              ----------------+-----           IDENTIFICADOR\n");
				printf("              |              |     |                 |\n");
				printf("   defining_identifier_list \",\" def_id");
				EscribirCentrado(16,Lexema[SubIndiceMax-1],0);
				printf("              |                    |\n");
				printf("              |              IDENTIFICADOR\n");
				printf("              |                    |\n");
				EscribirCentrado(15,"|",36,Lexema[SubIndiceMax-3],0);
				printf("              |\n");
				printf("              -----------------\n");
				printf("                              |\n");
				for (ContAuxK=(SubIndiceMax-5);ContAuxK>=0;ContAuxK-=2){
					if (ContAuxK==0){
						EscribirCentrado(31,"def_id",0);
						printf("                              |\n");
						EscribirCentrado(31,Token[0],0);
						printf("                              |\n");
						EscribirCentrado(31,Lexema[0],0);}
					else{
						printf("              ----------------+-----\n");
						printf("              |              |     |\n");
						printf("   defining_identifier_list \",\" def_id\n");
						printf("              |                    |\n");
						printf("              |              IDENTIFICADOR\n");
						printf("              |                    |\n");
						EscribirCentrado(15,"|",36,Lexema[ContAuxK],0);
						printf("              |\n");
						printf("              -----------------\n");
						printf("                              |\n");}
				}
			}
			break;
		case 2:
			printf("                  ---------------------+------------------------\n");
			printf("                  |              |       |        |            |\n");
			printf("       defining_identifier_list \":\" subtype_mark \":=\" default_expression\n");
			printf("                  |                      |                     |\n");
			if (SubIndiceMax==5){
				EscribirCentrado(19,"def_id",42,Token[2],64,Token[4]);
				printf("                  |                      |                     |\n");
				EscribirCentrado(19,Token[0],42,Lexema[2],64,Lexema[4]);
				printf("                  |\n");
				EscribirCentrado(19,Lexema[0],0);}
			else{
				printf("           -------+--------------  IDENTIFICADOR");
				EscribirCentrado(16,Token[SubIndiceMax-1],0);
				printf("           |              |     |        |                     |\n");
				printf("defining_identifier_list \",\" def_id");
				EscribirCentrado(7,Lexema[SubIndiceMax-3],29,Lexema[SubIndiceMax-1],0);
				printf("           |                    |\n");
				printf("           |              IDENTIFICADOR\n");
				printf("           |                    |\n");
				EscribirCentrado(12,"|",33,Lexema[SubIndiceMax-5]);
				printf("           --------\n");
				printf("                  |\n");
				for (ContAuxK=(SubIndiceMax-7);ContAuxK>=0;ContAuxK-=2){
					if (ContAuxK==0){
						EscribirCentrado(19,"def_id",0);
						printf("                  |\n");
						EscribirCentrado(19,Token[0],0);
						printf("                  |\n");
						EscribirCentrado(19,Lexema[0],0);}
					else{
						printf("           -------+--------------\n");
						printf("           |              |     |\n");
						printf("defining_identifier_list \",\" def_id\n");
						printf("           |                    |\n");
						printf("           |              IDENTIFICADOR\n");
						printf("           |                    |\n");
						EscribirCentrado(12,"|",33,Lexema[ContAuxK]);
						printf("           -------\n");
						printf("                 |\n");}
					}
				}
			break;
		case 3:
			printf("                           ------------+--------------\n");
			printf("                           |              |          |\n");
			printf("                defining_identifier_list \":\" access_definition\n");
			printf("                           |                         |\n");
			if (SubIndiceMax==3){
				EscribirCentrado(28,"def_id",54,Token[2],0);
				printf("                           |                         |\n");
				EscribirCentrado(28,Token[0],54,Lexema[2],0);
				printf("                           |\n");
				EscribirCentrado(28,Lexema[0],0);}
			else{
				printf("                 ----------+-----------          EXPRESION\n");
				printf("                 |              |     |              |\n");
				printf("      defining_identifier_list \",\" def_id");
				EscribirCentrado(13,Lexema[SubIndiceMax-1],0);
				printf("                 |                    |\n");
				printf("                 |              IDENTIFICADOR\n");
				printf("                 |                    |\n");
				EscribirCentrado(18,"|",39,Lexema[SubIndiceMax-3],0);
				printf("                 -----------\n");
				printf("                           |\n");
				for (ContAuxK=(SubIndiceMax-5);ContAuxK>=0;ContAuxK-=2){
					if (ContAuxK==0){
						EscribirCentrado(28,"def_id",0);
						printf("                           |\n");
						EscribirCentrado(28,Token[0],0);
						printf("                           |\n");
						EscribirCentrado(28,Lexema[0],0);}
					else{
						printf("                 ----------+-----------\n");
						printf("                 |              |     |\n");
						printf("      defining_identifier_list \",\" def_id\n");
						printf("                 |                    |\n");
						printf("                 |              IDENTIFICADOR\n");
						printf("                 |                    |\n");
						EscribirCentrado(18,"|",39,Lexema[ContAuxK],0);
						printf("                 -----------\n");
						printf("                           |\n");}
				}
			}
			break;
		case 4:
			printf("               ------------------------+--------------------------\n");
			printf("               |              |          |          |            |\n");
			printf("    defining_identifier_list \":\" access_definition \":=\" default_expressionn\n");
			printf("               |                         |                       |\n");
			if (SubIndiceMax==5){
				EscribirCentrado(16,"def_id",42,Token[2],66,Token[4]);
				printf("               |                         |                       |\n");
				EscribirCentrado(16,Token[0],42,Lexema[2],66,Lexema[4]);
				printf("               |\n");
				EscribirCentrado(16,Lexema[0],0);}
			else{
				printf("           ----+-----------------    EXPRESION");
				EscribirCentrado(20,Token[SubIndiceMax-1],0);
				printf("           |              |     |        |                       |\n");
				printf("defining_identifier_list \",\" def_id");
				EscribirCentrado(7,Lexema[SubIndiceMax-3],31,Lexema[SubIndiceMax-1],0);
				printf("           |                    |\n");
				printf("           |              IDENTIFICADOR\n");
				printf("           |                    |\n");
				EscribirCentrado(12,"|",33,Lexema[SubIndiceMax-5]);
				printf("           -----\n");
				printf("               |\n");
				for (ContAuxK=(SubIndiceMax-7);ContAuxK>=0;ContAuxK-=2){
					if (ContAuxK==0){
						EscribirCentrado(16,"def_id",0);
						printf("               |\n");
						EscribirCentrado(16,Token[0],0);
						printf("               |\n");
						EscribirCentrado(16,Lexema[0],0);}
					else{
						printf("           ----+-----------------\n");
						printf("           |              |     |\n");
						printf("defining_identifier_list \",\" def_id\n");
						printf("           |                    |\n");
						printf("           |              IDENTIFICADOR\n");
						printf("           |                    |\n");
						EscribirCentrado(12,"|",33,Lexema[ContAuxK]);
						printf("           -----\n");
						printf("               |\n");}
					}
				}
			break;
	}
	return 0;
}

int EscribirCentrado(int CenUno, char* CadUno, int CenDos, char* CadDos, int CenTres, char* CadTres){
	int Longitud, MaxLineas, MaxEspacios, K;

	Longitud=strlen(CadUno);
	MaxEspacios=CenUno-(Longitud/2)-1;
	for (K=0;K<MaxEspacios;K++){
		printf(" ");
	}
	printf("%s",CadUno);

	if (CenDos==0){
		printf("\n");
		return 0;}

	MaxLineas=MaxEspacios+Longitud;

	Longitud=strlen(CadDos);
	MaxEspacios=CenDos-(Longitud/2)-MaxLineas-1;
	for (K=0;K<MaxEspacios;K++){
		printf(" ");
	}
	printf("%s",CadDos);

	if (CenTres==0){
		printf("\n");
		return 0;}

	MaxLineas+=MaxEspacios+Longitud;

	Longitud=strlen(CadTres);
	MaxEspacios=CenTres-(Longitud/2)-MaxLineas-1;
	for (K=0;K<MaxEspacios;K++){
		printf(" ");
	}
	printf("%s\n",CadTres);

	return 0;
}