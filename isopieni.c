#include <stdio.h>
#include <string.h>
#include <ctype.h> 


/* 

    Kirjoita ohjelma, joka lukee rivin tekstiä funktiolla
    fgets merkkijonomuuttujaan, johon sopii enintään 100 merkkiä.
    Ohjelma tulostaa merkkijonon sekä pienillä kirjaimilla että 
    suurilla kirjaimilla. 

*/


#define MAX_SIZE 101


void cleanBuffer(void);



int main() {
    char string[MAX_SIZE]; 

    printf("Write something: ");
    fgets(string, MAX_SIZE, stdin);
    

    if( string[strlen(string)-1] == '\n')
        string[strlen(string)-1] = '\0';
    else
        cleanBuffer();

    // Tulostetaan aluksi merkkijono pienillä kirjaimilla.
    for( int i = 0; string[i] != '\0'; i++) {
        if( string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32;
        }
    }
    printf("\n");
    printf("%s\n", string);

    // Tulostetaan isoilla kirjaimilla.
    for( int i = 0; string[i] != '\0'; i++) {
        if( string[i] >= 'a' && string[i] <= 'z'){
            string[i] = string[i] - 32;
        }
    }
    printf("%s", string);

    return 0;
}



void cleanBuffer(void) {
    while( getc(stdin) != '\n' );
}