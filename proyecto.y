%{
#include <stdio.h>    
#include <string.h>
extern FILE  *yyin;

int yylex (void);
int yyerror(char *msg);

void showLine(int line);
void printOnError(char *err);
void dibujoArbol(int caso);

char *arbol[30];
int i = 0, ntries = 0; //ntries cuenta que ejemplo de entrada es.
int nlines = 0; //Este cuenta las lineas dentro de un ejemplo, para dar un mejor error
/*Las siguientes constantes sirven para saber que mostrar en el arbol*/
int confSecParag=0; //Sirve para saber si mostrar el conf-sec-paragraphs en el arbol de derivacion
char *envDivCont;



short int estado=1, acepToken=1;
int nline = 0;
short int proneToShow = 1; /*Permite que no salte muchas veces un mensaje en errores reiterados
(como si fuera el yyerror que solo se llama una vez)*/
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
%token DESCRIPTION FD 
%start mi_axioma
%%



mi_axioma: cobol-source-program | mi_axioma cobol-source-program
;
cobol-source-program: NL {/*Si lo borro pierdo la posibilidad de agregar mas*/}
                    | ENVIROMENT DIVISION DOT NL enviroment-division-content {if(estado == 1 && acepToken == 1){
                                                                                //Esto corre al final, por lo tanto lo pone al ultimo
                                                                                arbol[i] = "\n\t<cobol-source-program> ==>  ENVIROMENT DIVISION DOT NL enviroment-division-content";
                                                                                
                                                                                printf("\n\n________________________\nDERIVACION EJEMPLO: %d   ESTADO: LINEA ACEPTADA\n",++ntries);
                                                                                /*Decrementa, porque esto se corre al final*/
                                                                                for(i; i>=0; i--){
                                                                                    printf("%s", arbol[i]);
                                                                                }
                                                                                printf("\n\n________________________\n Nuevo itento: \n");
                                                                                estado = 1;
                                                                                acepToken = 1;
                                                                                /*Limpio los array para el proximo ejemplo*/
                                                                                for (i=0;i<30;i++){
                                                                                  arbol[i]="";
                                                                                }
                                                                                //Reseteo para el proximo ejemplo.
                                                                                nlines = 0;
                                                                                dibujoArbol(1);
                                                                            }
                                                                           }
                    | DATA DIVISION DOT NL data-division-content {/*DibujarTodo(2); Esta es correcta*/ /*Aca tal vez tambien me sirve el proneToShow = 1*/}
                    | error DIVISION DOT NL enviroment-division-content {printOnError("Se esperaba 'ENVIROMENT' al iniciar la frase\n "); /*Si contemplo asi el error, no se para*/}
                    | ENVIROMENT error DOT NL enviroment-division-content {printOnError("Se esperaba 'DIVISION' en segundo lugar\n ");}
                    | ENVIROMENT DIVISION error NL {printOnError("Al definir el titular de env division content. Se esperaba un punto ( . ) en tercer lugar\n ");}
                    | ENVIROMENT error DOT error {printOnError("Se esperaba un salto de linea para entrar poder contemplar el input de enviroment-division-content\n ");}
                    | error DIVISION DOT NL data-division-content {printOnError("Se esperaba 'DATA' al iniciar la oracion \n");}
                    | DATA error DOT NL data-division-content {printOnError("Se esperaba DIVISION en segundo lugar \n");}
                    | DATA DIVISION error NL data-division-content {printOnError("Al definir el titular de data division content. Se esperaba un punto ( . ) en tercer lugar\n");}
                    | DATA DIVISION DOT error data-division-content {printOnError("Se esperaba un salto de linea para poder analizar data-division-content \n");}
                    | DATA DIVISION DOT NL error {printOnError("Esta mal definido data-division-content. *REVISAR DOCUMENTACION* \n");}
                    
;
enviroment-division-content:
                           |configuration-section {/*Agrego al arbol el hijo de cobol-source-program*/
                                                    arbol[i]=" enviroment-division-content ==> configuration-section";
                                                    i++;estado=1; envDivCont="configuration-section";}
                           |input-output-section {/*Igual que en el de arriba, pero si se llegase a esta*/
                                                    arbol[i]="  enviroment-division-content ==> input-output-section";
                                                    i++;estado=1; envDivCont="input-output-section";}
                           
;
configuration-section: CONFIGURATION SECTION DOT NL configuration-section-paragraphs {/*Misma dinamica con el arbol que arriba*/
                                                                                   arbol[i]="configuration-section ==> CONFIGURATION SECTION DOT NL configuration-section-paragraphs";
                                                                                    i++;estado=1;}
                     | error SECTION DOT NL configuration-section-paragraphs {printOnError("Se esperaba el token CONFIGURATION en la primera posicion.");}
                     | CONFIGURATION error DOT NL configuration-section-paragraphs      {printOnError("Se esperaba el token SECTION en la segunda posicion.");}
                     | CONFIGURATION SECTION error NL configuration-section-paragraphs  {printOnError("Se esperaba el token DOT (.) en la tercera posicion.");}
                     | CONFIGURATION SECTION DOT error configuration-section-paragraphs {printOnError("Se esperaba el token  NL en la cuarta posicion.");}
;
data-division-content:
                     | FILEM SECTION DOT NL file-description-entry {
                                                                arbol[i]="data-division-content ==> FILEM SECTION DOT NL file-description-entry ";
                                                                i++;estado=1;
                                                                }
                     | error SECTION DOT NL file-description-entry {printOnError("Se esperaba el token FILEM en la definicion de data-division-content");}
                     | FILEM error DOT NL file-description-entry {printOnError("Se esperaba el token SECTION en la definicion de data-division-content");}
                     | FILEM SECTION error NL file-description-entry {printOnError("Se esperaba el token DOT en la definicion de data-division-content");}
                     | FILEM SECTION DOT error file-description-entry {printOnError("Se esperaba el token NL en la definicion de data-division-content");}
;

file-description-entry: FILEM SECTION DOT NL FD ID_FILE {arbol[i]=" file-description-entry ==> FILEM SECTION DOT NL FD ID_FILE ";
                                                                    i++;estado=1;
                                                                   }
                      | error SECTION DOT NL FD ID_FILE  {printOnError("Se esperaba el token FILE en file-description-entry");}
                      | FILEM error DOT NL FD ID_FILE {printOnError("Se esperaba el token SECTION en file-description-entry");}
                      | FILEM SECTION error NL FD ID_FILE {printOnError("Se esperaba el token DOT en file-description-entry");}
                      | FILEM SECTION DOT error FD ID_FILE {printOnError("Se esperaba el token NL en file-description-entry");}
                      | FILEM SECTION DOT NL error ID_FILE {printOnError("Se esperaba el token FD en file-description-entry");}
                      | FILEM SECTION DOT NL FD error {printOnError("Se esperaba el token ID_FILE en file-description-entry");}               
;
input-output-section: FILEM CONTROL DOT NL file-control-entry {arbol[i]="input-output-section ==> FILEM CONTROL DOT NL file-control-entry ";
                                                                i++;estado=1;}
                    | error CONTROL DOT NL file-control-entry {printOnError("Se esperaba el token FILEM en input-output-section");}
                    | FILEM error DOT NL file-control-entry {printOnError("Se esperaba el CONTROL en input-output-section");}
                    | FILEM CONTROL error NL file-control-entry {printOnError("Se esperaba el token DOT en input-output-section");}
                    | FILEM CONTROL DOT error file-control-entry {printOnError("Se esperaba el token NL en input-output-section");}
;

file-control-entry: ID_FILE DOT ID_FILE {arbol[i]=" file-control-entry ==> ID_FILE DOT ID_FILE";
                                         i++;estado=1;}
;

configuration-section-paragraphs:
                                | SOURCE COMPUTER DOT ID_COMPUTER DOT {arbol[i]=" configuration-section-paragraphs ==> SOURCE COMPUTER DOT ID_COMPUTER DOT";
                                         i++;estado=1; confSecParag=1; /*Si se cuple este o el de abajo, se muestra en el arbol de deriv*/}
                                | OBJECT COMPUTER DOT ID_COMPUTER DOT {arbol[i]=" configuration-section-paragraphs ==> OBJECT COMPUTER DOT ID_COMPUTER DOT";
                                         i++;estado=1; confSecParag=1;}
                                
;

%%

void showLine(int line){
    printf("N linea: %d", line);
}

void printOnError(char *err){ 
    //Seteo para que sea mas facil pasar un mensaje de error, en los controlados
    printf("\033[0;31m "); //seteo a rojo para la palabra error
    printf("\n ERROR: ");
    //printf("\033[0;35m");
    printf("\033[0m "); //Vuelvo a blanco
    printf("%s \n", err);
}

int yyerror(char *msg){
    /*ESTA FUNCION SE LLAMA SIEMPRE QUE SURJA UN ERROR*/
    printf("\n Error encontrado!\n "); 
    //Ver si con esto logro lo de mostrar una sola vez mi mensaje personalizado
    proneToShow = 1;
}

int main(int argc, char **argv){
    
    if (argc > 1) yyin = fopen(argv[1], "rt\n ");
    else {
        yyin = stdin;
        printf("\n\nRecomiendo leer la documentacion para comprender como manejar los saltos de linea. \n");
        printf("Este analizador intenta emular codigo COBOL. Por lo que es importante considerarlos. \n");
        printf("----------------------------------------------------------\n\n");
        printf("Ingrese su cadena: \n");
        }

    
    yyparse();
    
    return 0;
}
int yywrap() {
	// EstadoScanner=2;
	printf("El analisis ha concluido\n\n ");
	return 1;
}

void dibujoArbol(int caso){
    printf("_____________-ARBOL DE DERIVACIONES-_____________");
    printf("           cobol-source-program\n");
    printf("                    |\n");

    switch(caso){
        case 1:
        printf("ENVIROMENT DIVISION DOT NL enviroment-division-content\n");
        printf("                                        |\n");
        printf("                                        --------\n");
        printf("                                                |\n");
        printf("                                          %s", envDivCont);
        
            break;
        
        case 2:
        
            break;
        
        case 3:

            break;
    }

}