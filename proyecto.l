%{
#include <stdio.h>
#include <stdlib.h>
#include "proyecto.tab.c" //Esto es para unirlo a Bison

/*Hay una variable por cada token, CUando aparece una 
palabra, que devuelve un token, tambien aumenta en uno la 
cantidad de su variable correspondiente*/
int ntok = 0, ndot = 0, nenv = 0, ndiv = 0, ndata = 0;
int nsec = 0, nconf = 0, nidcomp = 0;
int nidfile = 0, nfile = 0, nctrl = 0;
int nsrce = 0, ncomp = 0, nobj = 0;
%}

digito [0-9]
digitos {digito}+
letras [a-z]
palabras {letras}+
cadena {palabras}+
cadenap ({cadena}[0-9])
%%

{cadena} {ntok++; nidcomp++;
          yylval.letras=yytext;
          return ID_COMPUTER; 
          }

{cadenap} {ntok++; nidfile++;
            yylval.fileeId=yytext;
            return ID_FILE; 
           }

"\n" {return NL;}
"." {ntok++; ndot++; return DOT;}
"ENVIROMENT" {ntok++; nenv++; return ENVIROMENT;}
"DIVISION" {ntok++; ndiv++; return DIVISION;}
"DATA" {ntok++; ndata++; return DATA;}
"SECTION" {ntok++; nsec++; return SECTION;}
"CONFIGURATION" {ntok++; nconf++; return CONFIGURATION;}
"FILE" {ntok++; nfile++; return FILE;}
"CONTROL" {ntok++; nctrl++; return CTRL;}
"SOURCE" {ntok++; nsrce; return SOURCE;}
"COMPUTER" {ntok++; ncomp++; return COMPUTER;}
"OBJECT" {ntok++; nobj++; return OBJECT;}
"file-description-entry" {ntok++; return FILEDESC;}
"TERMINAR"  {
     int i=0;
    printf("\n");
    for (i=0;i<=70;i++) printf("-");printf("\n");
    for (i=0;i<=70;i++) printf("-");printf("\n");
    printf( "TABLA DE TOKENS:\n\n");
    if(ntok > 0){
        printf("\n Tokens reconocidos: %d \n", ntok);
        printf("\n Lista de tokens y sus cantidades: \n");

        if( ndot > 0) printf("DOT: Asociado al lexema punto ( . ) => %d \n", ndot);
        if( nenv > 0) printf("ENVIROMENT: Asociado al lexema ENVIROMENT | enviroment => %d \n ", nenv);
        if( ndiv > 0) printf("DIVISION: Asociado al lexema DIVISION | division => %d \n", ndiv);
        if( ndata > 0) printf("DATA: Asociado al lexema DATA | data => %d \n", ndata );
        if( nconf > 0) printf("CONFIGURATION: Asociado al lexema CONFIGURATION | configuration => %d \n",nconf );
        if( nsec > 0) printf(" SECTION: Asociado al lexema SECTION | section=> %d \n", nsec );

    }else if(ntok = 0){
        printf("\n Se ha ingresado la cadena vacia. Esta es valida. Aunque trivial \n");
    };


    printf("Soy la salida");
    exit(0);
}

[\t];

%%