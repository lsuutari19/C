#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE * theFile;
    int rows=1, signs=0;
    char ch;
    theFile = fopen("teksti.txt", "r");
    if(theFile == NULL) {
        printf("Could not open file \n");
        return 1;
    }
    
    while(1) {
        ch = fgetc(theFile);

        if(ch == EOF)
            break;
        if (ch == '\n'){
            rows = rows + 1;
        }
//            printf("%c\n",ch);
        signs = signs + 1;
        
    } 
    fclose(theFile);
    printf("Rivit: %d \nMerkit: %d", rows, signs);
    return 0;
}