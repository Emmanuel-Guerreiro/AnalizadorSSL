%{
#include <stdio.h>    
extern FILE  *yyin;

/*
Por convencion de BISON
Los TERMINALES se encuentran en MAYUSCULA
Los *no-terminales* se encuentran en *minuscula*
*/

/*
Las reglas de COBOL estan simplificadas. En casos como data-division-content o
configuration-section-paragraphs solo se contemplan ciertos casos posibles,
para simplificar el analisis sintactico (contemplando menor numero de errores y 
tokens posibles)
*/


/*Explicacion tokens: 
DOT => '.' ; CSP => CONFIGURATION-SECTION-PARAGRAPHS; */
/*
FCTRL, FCENT son tokens que surgen a partir de la estructura del codigo COBOL
*/

int i = 0, nlines = 0;

%}

%union{
    int digitos;
    char *letras;
    char *fileeId;
}
%token <letras> ID_COMPUTER
%token <fileeId> ID_FILE
%token NL SOURCE COMPUTER OBJECT
%token CONFIGURATION SECTION DOT
%token DIVISION ENVIROMENT DATA CONTROL
%token FCTRL FCENT FILEM CTRL
%token FILEDESC
%start cobol-source-program
%%
cobol-source-program: {/*En el caso de vacio. Pasa como valido*/}
                    | ENVIROMENT DIVISION DOT enviroment-division-content  
                    | DATA DIVISION DOT data-division-content  
                    | ENVIROMENT DIVISION DOT enviroment-division-content DATA DIVISION DOT data-division-content  
;
enviroment-division-content: configuration-section  
          | input-output-section  
          | configuration-section input-output-section  
;
configuration-section: CONFIGURATION SECTION DOT configuration-section-paragraphs  
;
data-division-content:  
                     | FILEM  SECTION DOT FILEDESC {/*Este ultimo es provisional*/}
                     | error SECTION DOT FILEDESC {printf("\n--> Error lexico en linea %d, Se esperaban <<>>, luego de primer expression\n",++nlines);} 
                     | FILEM  error DOT FILEDESC {printf("\n--> Error lexico en linea %d, Se esperaban <<>> luego de primer expression\n",++nlines);} 
                     | FILEM  SECTION error FILEDESC {printf("\n--> Error lexico en linea %d, Se esperaban <<>> luego de primer expression\n",++nlines);} 
                     | FILEM  SECTION DOT error {printf("\n--> Error lexico en linea %d, Se esperaban <<>> luego de primer expression\n",++nlines);} 
;
input-output-section:  
                    | FILEM  CONTROL DOT ID_FILE {printf("Ta todo gucci");}
                    | error CONTROL DOT ID_FILE {printf("\n--> Error lexico en linea %d, Se esperaban <<>> luego de primer expression\n",++nlines);}
                    | FILEM  error DOT ID_FILE {printf("\n--> Error lexico en linea %d, Se esperaban <<>> luego de primer expression\n",++nlines);}
                    | FILEM  CONTROL error ID_FILE {printf("\n--> Error lexico en linea %d, Se esperaban <<>> luego de primer expression\n",++nlines);}
                    | FILEM  CONTROL DOT error {printf("\n--> Error lexico en linea %d, Se esperaban <<>> luego de primer expression\n",++nlines);}
;
configuration-section-paragraphs: DATA DOT DATA {/*Ver si considero mas renglones de configuracion*/}
                                
%%
int yyerror(char *msg){

    printf("\n Error detectado\n %s", msg);
}

int main(int argc, char **argv){
    
    if (argc > 1)
    {
         yyin = fopen(argv[1], "rt");
    }else
    { 
        yyin = stdin;
    
    
    yyparse();
    
    return 0;
}
int yywrap() {return 1;}