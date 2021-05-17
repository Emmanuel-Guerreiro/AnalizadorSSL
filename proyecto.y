%{
#include <stdio.h>    
#include <string.h>
extern FILE  *yyin;

int yylex (void);
int yyerror(char *msg);

void showLine(int line);
void printOnError(char *err);
void dibujoArbol(int caso);

char *derivaciones[30];
int i = 0, ntries = 0; //ntries cuenta que ejemplo de entrada es.
int nlines = 0; //Este cuenta las lineas dentro de un ejemplo, para dar un mejor error
/*Las siguientes constantes sirven para saber que mostrar en el arbol*/
int confSecParag=0; //Sirve para saber si mostrar el conf-sec-paragraphs en el arbol de derivacion
char *envDivCont[10];
char *showInTree[5]; //Este es el que se corre en la funcion de mostrar arbol
int j = 0; //me sirve para poder ir acomodando los items en el array de showInTree

//Estos dos son para servir hacer toggle a mostrar las derivaciones
int env = 0, dat = 0; 

short int errorC = 0;

short int proneToShow = 1; /*Permite que no salte muchas veces un mensaje en errores reiterados
(como si fuera el yyerror que solo se llama una vez)*/
%}

%union{
    int digitos;
    char *letras;
}
%token <letras> ID
%token TAB NL DOT 
%token ENVIROMENT DIVISION DATA
%token SECTION CONFIGURATION FILEM
%token CONTROL SOURCE COMPUTER
%token OBJECT DESCRIPTION FD
%start mi_axioma
%%



mi_axioma: cobol-source-program | mi_axioma cobol-source-program
;
cobol-source-program:NL {derivaciones[i]="<cobol-source-program> ==> ' ' \n"; i++; env++; dat++;}
                    | ENVIROMENT DIVISION DOT enviroment-division-content cobol-source-program {     //Lo cargo fuera del if para hacerlo sin importar recursion
                                                                                derivaciones[i] = "\n<cobol-source-program> ==>  ENVIROMENT DIVISION DOT NL <enviroment-division-content> <cobol-source-program>\n";
                                                                                showInTree[j] = "\n\t ENVIROMENT DIVISION DOT NL <enviroment-division-content>";
                                                                                ++j;
                                                                                ++i;
                                                                                
                                                                                
                                                                                if( env >= 1 && errorC == 0){
                                                                                //Esto corre al final, por lo tanto lo pone al ultimo
                                                                                showInTree[j] = "\n\t <cobol-source-program>";
                                                                                printf("\n\n________________________\nDERIVACION EJEMPLO: %d   ESTADO: LINEA ACEPTADA\n",++ntries);
                                                                                /*Decrementa, porque esto se corre al final*/
                                                                                for(i; i>=0; i--){
                                                                                    printf("%s", derivaciones[i]);
                                                                                }
                                                                                
                                                                                
                                                                                /*Limpio los array para el proximo ejemplo*/
                                                                                for (i=0;i<30;i++){
                                                                                  derivaciones[i]="";
                                                                                }
                                                                                //Reseteo para el proximo ejemplo.
                                                                                nlines = 0;
                                                                                dibujoArbol(1);
                                                                                printf("\n________________________\n");
                                                                                printf("\n Nuevo itento: \n");
                                                                                env = 0;
                                                                                dat = 0;
                                                                                errorC = 0;
                                                                            }
                                                                           }
                    | DATA DIVISION DOT data-division-content cobol-source-program {
                                                                                //Lo cargo afuera, para que se cargue siempre (sin importar recursion)
                                                                                derivaciones[i] = "\n<cobol-source-program> ==>  DATA DIVISION DOT NL <data-division-content> <cobol-source-program>\n";
                                                                                showInTree[j] = "\n\t DATA DIVISION DOT NL <data-division-content>";
                                                                                ++j;
                                                                                i++;
                                                                                
                                                                                
                                                                                if( dat >= 1 && errorC == 0 ){
                                                                                //Esto corre al final, por lo tanto lo pone al ultimo
                                                                                showInTree[j] = "<cobol-source-program>";
                                                                                printf("\n\n________________________\nDERIVACION EJEMPLO: %d   ESTADO: LINEA ACEPTADA\n",++ntries);
                                                                                /*Decrementa, porque esto se corre al final*/
                                                                                for(i; i>=0; i--){
                                                                                    printf("%s", derivaciones[i]);
                                                                                }   
                                                                                
                                                                                /*Limpio los array para el proximo ejemplo*/
                                                                                for (i=0;i<30;i++){
                                                                                  derivaciones[i]="";
                                                                                }
                                                                                dibujoArbol(2);
                                                                                printf("\n________________________\n");
                                                                                printf("\n Nuevo itento: \n");
                                                                                dat = 0;
                                                                                env = 0;
                                                                                errorC = 0;
                                                                             }
                                                                            }
                    | error DIVISION DOT NL enviroment-division-content {printOnError("Se esperaba 'ENVIROMENT' al iniciar la frase\n "); /*Si contemplo asi el error, no se para*/ errorC = 1;}
                    | ENVIROMENT error DOT NL enviroment-division-content {printOnError("Se esperaba 'DIVISION' en segundo lugar\n "); errorC = 1;}
                    | ENVIROMENT DIVISION error NL {printOnError("Al definir el titular de env division content. Se esperaba un punto ( . ) en tercer lugar\n "); errorC = 1;}
                    | ENVIROMENT error DOT error {printOnError("Se esperaba un salto de linea para entrar poder contemplar el input de enviroment-division-content\n "); errorC = 1;}
                    | error DIVISION DOT NL data-division-content {printOnError("Se esperaba 'DATA' al iniciar la oracion \n"); errorC = 1;}
                    | DATA error DOT NL data-division-content {printOnError("Se esperaba DIVISION en segundo lugar \n"); errorC = 1;}
                    | DATA DIVISION error NL data-division-content {printOnError("Al definir el titular de data division content. Se esperaba un punto ( . ) en tercer lugar\n"); errorC = 1;}
                    | DATA DIVISION DOT error data-division-content {printOnError("Se esperaba un salto de linea para poder analizar data-division-content \n"); errorC = 1;}
                    | DATA DIVISION DOT NL error {printOnError("Esta mal definido data-division-content. *REVISAR DOCUMENTACION* \n"); errorC = 1;}
                    | ENVIROMENT DIVISION DOT enviroment-division-content error {printOnError("Error en la recursion de <cobol-source-program>"); errorC = 1;}
                    | DATA DIVISION DOT data-division-content error {printOnError("Error en la recursion de <cobol-source-program>"); errorC = 1;}
;
enviroment-division-content:NL {derivaciones[i] = "<enviroment-division-content> ==> NL\n"; i++; env = 1; dat = 0;}
                           |configuration-section enviroment-division-content{/*Agrego al arbol el hijo de cobol-source-program*/
                                                    derivaciones[i]="<enviroment-division-content> ==> <configuration-section> NL <enviroment-division-content>\n";
                                                    i++;  
                                                    showInTree[j]="<configuration-section>"; 
                                                    j++;
                                                    env = 1;}
                           |input-output-section enviroment-division-content{/*Igual que en el de arriba, pero si se llegase a esta*/
                                                    derivaciones[i]="<enviroment-division-content> ==> <input-output-section> NL <enviroment-division-content>\n";
                                                    i++; 
                                                    showInTree[j]="<input-output-section>";
                                                    j++;
                                                    dat = 1;}
                           
;
configuration-section:NL CONFIGURATION SECTION DOT configuration-section-paragraphs {/*Misma dinamica con el arbol que arriba*/
                                                                                   derivaciones[i]="<configuration-section> ==> CONFIGURATION SECTION DOT NL <configuration-section-paragraphs> \n";
                                                                                    i++; 
                                                                                    showInTree[j]="CONFIGURATION SECTION DOT NL configuration-section-paragraphs";
                                                                                    j++;}
                     |NL error SECTION DOT NL configuration-section-paragraphs {printOnError("Se esperaba el token CONFIGURATION en la primera posicion."); errorC = 1;}
                     |NL CONFIGURATION error DOT NL configuration-section-paragraphs      {printOnError("Se esperaba el token SECTION en la segunda posicion."); errorC = 1;}
                     |NL CONFIGURATION SECTION error NL configuration-section-paragraphs  {printOnError("Se esperaba el token DOT (.) en la tercera posicion."); errorC = 1;}
                     |NL CONFIGURATION SECTION DOT error configuration-section-paragraphs {printOnError("Se esperaba el token  NL en la cuarta posicion."); errorC = 1;}
;

configuration-section-paragraphs:NL {derivaciones[i] = "<configuration-section-paragraphs> ==> NL \n"; i++;} 
                                |NL SOURCE COMPUTER DOT ID DOT configuration-section-paragraphs {derivaciones[i]="<configuration-section-paragraphs> ==> SOURCE COMPUTER DOT ID DOT NL <configuration-section-paragraphs>\n";
                                         i++;  confSecParag=1; /*Si se cuple este o el de abajo, se muestra en el arbol de deriv*/
                                         showInTree[j]="SOURCE COMPUTER DOT ID DOT";
                                         }
                                |NL OBJECT COMPUTER DOT ID DOT configuration-section-paragraphs {derivaciones[i]="<configuration-section-paragraphs> ==> OBJECT COMPUTER DOT ID DOT NL <configuration-section-paragraphs>\n";
                                         i++;  confSecParag=1;
                                         showInTree[j]="OBJECT COMPUTER DOT ID DOT";}
                                |NL error COMPUTER DOT ID DOT {printOnError("Se esperaba token SOURCE o OBJECT en configuration-section-paragraphs"); errorC = 1;}
                                |NL SOURCE error DOT ID DOT {printOnError("Se esperaba token COMPUTER en configuration-section-paragraphs"); errorC = 1;}
                                |NL SOURCE COMPUTER error ID DOT {printOnError("Se esperaba token DOT en configuration-section-paragraphs"); errorC = 1;}
                                |NL SOURCE COMPUTER DOT error DOT {printOnError("Se esperaba token ID en configuration-section-paragraphs"); errorC = 1;}
                                |NL SOURCE COMPUTER DOT ID error {printOnError("Se esperaba token DOT en configuration-section-paragraphs"); errorC = 1;}
                                |NL OBJECT error DOT ID DOT {printOnError("Se esperaba token COMPUTER en configuration-section-paragraphs"); errorC = 1;}
                                |NL OBJECT COMPUTER error ID DOT {printOnError("Se esperaba token DOT en configuration-section-paragraphs"); errorC = 1;}
                                |NL OBJECT COMPUTER DOT error DOT {printOnError("Se esperaba token ID en configuration-section-paragraphs"); errorC = 1;}
                                |NL OBJECT COMPUTER DOT ID error {printOnError("Se esperaba token DOT en configuration-section-paragraphs"); errorC = 1;}
;

data-division-content:NL {derivaciones[i]="<data-division-content> ==> NL \n"; i++;}
                     |NL FILEM SECTION DOT file-description-entry {
                                                                derivaciones[i]="<data-division-content> ==> FILEM SECTION DOT NL <file-description-entry> \n";
                                                                i++; 
                                                                showInTree[j]="FILEM SECTION DOT NL <file-description-entry>";
                                                                j++;
                                                                }
                     |NL error SECTION DOT NL file-description-entry {printOnError("Se esperaba el token FILEM en la definicion de data-division-content"); errorC = 1;}
                     |NL FILEM error DOT NL file-description-entry {printOnError("Se esperaba el token SECTION en la definicion de data-division-content"); errorC = 1;}
                     |NL FILEM SECTION error NL file-description-entry {printOnError("Se esperaba el token DOT en la definicion de data-division-content"); errorC = 1;}
                     |NL FILEM SECTION DOT error file-description-entry {printOnError("Se esperaba el token NL en la definicion de data-division-content"); errorC = 1;}
;

file-description-entry:NL FD ID NL{derivaciones[i]="<file-description-entry> ==> FILEM SECTION DOT NL FD ID \n";
                               i++; 
                               showInTree[j]="FD ID";
                               }
                      |NL error ID {printOnError("Se esperaba el token FD en file-description-entry"); errorC = 1;}
                      |NL FD error {printOnError("Se esperaba el token ID en file-description-entry"); errorC = 1;}
;

input-output-section:NL FILEM CONTROL DOT file-control-entry {derivaciones[i]="<input-output-section> ==> FILEM CONTROL DOT NL <file-control-entry> \n";
                                                                i++; 
                                                                showInTree[j]="FILEM CONTROL DOT NL <file-control-entry>";
                                                                j++;}
                    |NL error CONTROL DOT NL file-control-entry {printOnError("Se esperaba el token FILEM en input-output-section"); errorC = 1;}
                    |NL FILEM error DOT NL file-control-entry {printOnError("Se esperaba el CONTROL en input-output-section");  errorC = 1;}
                    |NL FILEM CONTROL error NL file-control-entry {printOnError("Se esperaba el token DOT en input-output-section"); errorC = 1;}
                    |NL FILEM CONTROL DOT error file-control-entry {printOnError("Se esperaba el token NL en input-output-section"); errorC = 1;}
;

file-control-entry:NL ID DOT NL {derivaciones[i]="<file-control-entry> ==> ID DOT ID \n";
                                         i++; 
                                         showInTree[j]="ID DOT ID";}
                  |NL error DOT NL {printOnError("Se esperaba token ID al definir file-control-entry");  errorC = 1;}
                  |NL ID error NL {printOnError("Se esperaba token DOT al definir file-control-entry");  errorC = 1;}
                  |NL ID DOT error {printOnError("Se esperaba token NL al definir file-control-entry");  errorC = 1;}
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
	
	return 1;
}

void dibujoArbol(int caso){
    printf("\t\n_____________-ARBOL DE DERIVACIONES-_____________ \n\n");
    
    for(j; j>=0; j--){
        printf("\t %s", showInTree[j]);
        printf("\n | \n");
    }

}