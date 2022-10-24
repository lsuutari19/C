#include <stdio.h>
#include <string.h>

char* mystrcpy(char* kohde, const char* lahde);
char* mystrcat(char* kohde, char* lahde);

// älä palauta mainin kanssa!

int main() {
    char mjono1[1000] = "This is a test.";
    char mjono2[1000] = "This is still a test.";
    char mjono3[1000] = "A new test.";


//    printf(mystrcpy(mjono1, mjono2));


    printf(mystrcat ( mystrcat(mjono1, mjono2), mjono3));
}

char* mystrcpy(char* kohde, const char* lahde){
    kohde[0] = '\0';
    for(int i=0; i<strlen(lahde); i++) 
    {
        kohde[i] = lahde[i];
    }
    return kohde;
}

char* mystrcat(char* kohde, char* lahde) {
    int j = 0;
    int i = 0;

    while( kohde[i] != '\0'){
        i++;
    }

//    kohde[strlen(kohde)] = ' ';
//    kohde[strlen(kohde) + 1] = '\0';

    for(i, j; j < strlen(lahde); i++, j++) {
        if(kohde[i] == ' ') {
            i++;
        }
        kohde[i] = lahde[j];       
    }
    kohde[i] = '\0';

    return kohde;
}
