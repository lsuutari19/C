#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20


void strremove(char *string, char *removeSubStr);


void strremove(char *string, char *removeSubStr) 
{
	char *found;
	int length = strlen(removeSubStr);

	while ((found = strstr(string, removeSubStr))) 
    {
		*found = '\0';
		strcat(string, found+length);
	}
}

int main() {
    FILE * File;
    int foundWord=0, wordLength;
    char temp[size], word[size], temp2[size] = "";
    char buffer[200];


    File = fopen("sanakirja.txt", "r");
    if(File == NULL) {
        printf("Could not open file \n");
    }
    printf("Anna sana suomeksi tai englanniksi > ");
    fgets(word, size, stdin);
    word[strcspn(word, "\n")] = 0;
    wordLength = strlen(word);

    strcpy(temp, word);
    while(fgets(buffer, 200, File)) {
        char *check = strstr( buffer, word );

        if( check != NULL ){
//            printf("buffer on %s \n", buffer);
            if(buffer[wordLength] == ';') {

                strcat(temp, ";");
                strremove(buffer, temp);
                printf("sana %s on englanniksi %s", word, buffer);
            } else {
                strcat(temp2, ";");
                strcat(temp2, word);
                strremove(buffer, temp2);
                printf("sana %s on suomeksi %s", word, buffer);          
            }
            foundWord = 1;
        }
    }
    if(foundWord == 0) {
        printf("Sanaa %s ei loytynyt sanakirjasta.", temp);
    }
}