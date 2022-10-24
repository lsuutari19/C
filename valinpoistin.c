#include <stdio.h>
#include <string.h>

char* removeSpaces(char* origString, char *cleanedString);
void luepois(void);

int main() {
    char * string;
    char * cleanString;
    char allCleanStrings[1024] = {};
    int j;



    for(int i = 0; i < 3; i++) 
    {
        printf("Input string > ");
        fgets(string, 100, stdin);

        if( string[strlen(string)-1] == '\n') 
        {
   //         string[strlen(string)-1] = '\0';
            strcat(allCleanStrings, removeSpaces(string, cleanString));
        }
        else 
        {
            luepois(); 
        }
    }

    printf("%s", allCleanStrings);

    return 0;
}


char* removeSpaces(char * origString, char *cleanedString) {

    int j = 0;
    for(int i = 0; i < strlen(origString); i++) 
    {
        if(origString[i] != ' ')
        {
            origString[j++] = origString[i];
        }
    
    }
    origString[j] = '\0';
    cleanedString = origString;

    return(cleanedString);
}

void luepois(void){
    while( getc(stdin) != '\n');
}