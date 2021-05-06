%{
#include <stdio.h>    

/*
Por convencion de BISON
Los TERMINALES se encuentran en MAYUSCULA
Los *no-terminales* se encuentran en *minuscula*
*/

/*Explicacion tokens: 
DOT => '.' ; CSP => CONFIGURATION-SECTION-PARAGRAPHS; */

%}


%token DOT, NL
%token CONFIGURATION SECTION DOT
%token DIVISION ENVIROMENT DATA
%start cobol-source-program
%%
cobol-source-program: ENVIROMENT DIVISION DOT enviroment-division-content {};
                    | DATA DIVISION DOT data-division-content {};
                    | ENVIROMENT DIVISION DOT enviroment-division-content DATA DIVISION DOT data-division-content {};
                    | {/*En el caso de vacio. Pasa como valido*/};

enviroment: configuration-section {};
          | input-output-section {};
          | configuration-section input-output-section {};

enviroment-division-content: {};

data-division-content: {};

configuration-section: CONFIGURATION SECTION DOT configuration-section-paragraphs {};

input-output-section: {};

configuration-section-paragraphs: DATA DOT DATA {/*Ver si considero mas renglones de configuracion*/};
                                

%%
int yyerror(char *msg){

    printf("\n Error detectado\n %s", msg)
}

int main(int argc, char **argv){
    
    if (argc > 1)
    {
         yyin = fopen(argv[1], "rt")
    }else
    { 
        yyin = stdin};
    
    
    yyparse();
    
    return 0;
}