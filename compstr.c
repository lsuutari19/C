#include <stdio.h>
#include <string.h>


char omaStrcmp(char * str1, char * str2);

int main() {
    char mjono1[100], mjono2[100];
    int big;
    printf("Anna merkkijono > ");
    fgets(mjono1, 100, stdin);

    printf("Anna merkkijono > ");
    fgets(mjono2, 100, stdin);

    big = omaStrcmp(mjono1, mjono2);
    
    if( mjono1[strlen(mjono1)-1] == '\n') 
    {
        mjono1[strlen(mjono1)-1] = '\0';         
    }

    if(big == 1) 
    {
        printf("%s > %s", mjono1, mjono2);
    } else if (big == 0) 
    {
        printf("%s == %s", mjono1, mjono2);
    } else 
    {
        printf("%s < %s", mjono1, mjono2);
    }
}

char omaStrcmp(char * str1, char * str2) {
    int bigger;

    for(int i=0; i<strlen(str1); i++) {
        bigger = 0;
        printf("%c %c \n", str1[i], str2[i]);
        if(str1[i] > str2[i]) {
            bigger = 1;
            break;
        } else if (str2[i] > str1[i]) {
            bigger = 2;
            break;
        }
        
    }
    return bigger;
}