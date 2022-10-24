#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256


FILE * src;
int linecount = 0;
int numLines = 5;
char ch[MAX];


src = fopen( "tiedosto.txt", "r" );
/*
if ( src == NULL ) {
    fputs( "Can't open input file.", stdout );
    exit(-1);
}*/

while(NULL != fgets(ch,MAX,src)) {
    linecount++;
    fputs(ch, stdout);

    if (linecount == numLines) {
        break;
    }
}