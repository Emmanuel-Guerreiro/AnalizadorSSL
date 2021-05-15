%{
#include <stdio.h>
#include <stdlib.h>
#include "proyecto.tab.h" //Esto es para unirlo a Bison

/*Hay una variable por cada token, CUando aparece una 
palabra, que devuelve un token, tambien aumenta en uno la 
cantidad de su variable correspondiente*/
int totLine = 1; //ESta contabiliza la cantidad total de lineas de la entrada (contando espacios)
int ntok = 0, ndot = 0, nenv = 0, ndiv = 0, ndata = 0;
int nsec = 0, nconf = 0, nidcomp = 0;
int nidfile = 0, nfile = 0, nctrl = 0;
int nsrce = 0, ncomp = 0, nobj = 0;
int ndesc = 0, nfd = 0;
%}

digito [0-9]
digitos {digito}+
letras [a-z]
palabras {letras}+

%%

{palabras} {ntok++; nidcomp++;
          yylval.letras=yytext;
          return ID; 
          }

"\t" {return TAB;}
"\n" {totLine++;return NL;}
"." {ntok++; ndot++; return DOT;}
"CONFIGURATION" {ntok++; nconf++; return CONFIGURATION;}
"ENVIROMENT" {ntok++; nenv++; return ENVIROMENT;}
"SECTION" {ntok++; nsec++; return SECTION;}
"FILE" {ntok++; nfile++; return FILEM;}
"CONTROL" {ntok++; nctrl++; return CONTROL;}
"SOURCE" {ntok++; nsrce; return SOURCE;}
"COMPUTER" {ntok++; ncomp++; return COMPUTER;}
"DIVISION" {ntok++; ndiv++; return DIVISION;}
"DATA" {ntok++; ndata++; return DATA;}
"OBJECT" {ntok++; nobj++; return OBJECT;}
"DESCRIPTION" {ntok++; ndesc++; return DESCRIPTION;}
"FD" {ntok++; nfd++;return FD;}


"TERMINAR" {
    int i=0;
    printf("\n");
    for (i=0;i<=70;i++) printf("-");printf("\n");
    for (i=0;i<=70;i++) printf("-");printf("\n");
    
    printf("Se han reconocido %d tokens, en %d lineas (contanto saltos de linea) \n", ntok, totLine);
    printf( "====================RECUENTO TOTAL DE TOKENS====================\n\n");
    if(ntok > 0){
        printf("\n Tokens reconocidos: %d \n", ntok);
        printf("\n Lista de tokens y sus cantidades: \n");

        if(ndot > 0) printf("\n TOKEN *DOT* -> se ha reconocido %d veces", ndot);
        if(nenv > 0) printf("\n TOKEN *ENVIROMENT* -> se ha reconocido %d veces", nenv);
        if(ndiv > 0) printf("\n TOKEN *DIVISION* -> se ha reconocido %d veces", ndiv);
        if(ndata > 0) printf("\n TOKEN *DATA* -> se ha reconocido %d veces", ndata);
        if(nsec > 0) printf("\n TOKEN *SECTION* -> se ha reconocido %d veces", nsec);
        if(nconf > 0) printf("\n TOKEN *CONFIGURATION* -> se ha reconocido %d veces", nconf);
        if(nfile > 0) printf("\n TOKEN *FILEM* -> se ha reconocido %d veces", nfile);
        if(nctrl > 0) printf("\n TOKEN *CONTROL* -> se ha reconocido %d veces", nctrl);
        if(nsrce > 0) printf("\n TOKEN *SOURCE* -> se ha reconocido %d veces", nsrce);
        if(ncomp > 0) printf("\n TOKEN *COMPUTER* -> se ha reconocido %d veces", ncomp);
        if(nobj > 0) printf("\n TOKEN *OBJECT* -> se ha reconocido %d veces", nobj);
        if(ndesc > 0) printf("\n TOKEN *DESCRIPTION* -> se ha reconocido %d veces", ndesc);
        if(nfd > 0) printf("\n TOKEN *FD* -> se ha reconocido %d veces", nfd);
    }else {
        printf("\n *** Se ha ingresado la cadena vacia. Esta es valida. Aunque trivial *** \n");
    };


    printf("\n\n------------ Hemos llegado al final del analisis. Saliendo ------------\n");
    exit(0);
}



%%




