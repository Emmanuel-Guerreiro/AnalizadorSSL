%{
#include <stdio.h>
#include <stdlib.h>
#include "proyect.tab.h" //Esto es para unirlo a Bison

/*Hay una variable por cada token, CUando aparece una 
palabra, que devuelve un token, tambien aumenta en uno la 
cantidad de su variable correspondiente*/
int ntok = 0, ndot = 0, nenv = 0, ndiv = 0, ndata = 0;
int nsec = 0, nconf = 0;

%}

/*HAy que agregar las regex que faltan, y ver como darle forma a las partes  de conf-section*/
digito [0-9]
digitos {digito}+
letras [a-zA-Z]
palabras {letras}+
cadena {palabras}+


%%

"."     {ntok++; ndot++; return DOT}
"\n"    {return NL}
"enviroment" | "ENVIROMENT" {ntok++; nenv++; return ENVIROMENT};
"division" | "DIVISION" {ntok++; ndiv++; return DIVISION};
"data" | "DATA" {ntok++; ndata++; return DATA}
"section" | "SECTION" {ntok++; nsec++; return SECTION };
"configuration" | "CONFIGURATION" {ntok++; nconf++, return CONFIGURATION};
"END PROGRAM" | "END" | "TERMINAR" {
    //Es para salir del programa, y mostrar la tabla 
    /*aca me dedico a mostrar toda la tabla de tokens*/
    printf("Soy la salida");
    exit(0);
};
%%