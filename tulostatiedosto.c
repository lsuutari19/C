#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>



int main() {
    FILE * infile;
    char ch;
    int rows=0;
    int chars=0;
    

    infile = fopen("nimet.txt", "r");

    while((ch = fgetc(infile)) != EOF) 
    {
        chars++;
        if(ch == '\n') 
        {
            rows++;
        }
    }
    fclose(infile);

    infile = fopen("nimet.txt", "r");
    char words[rows+1][100];

    for(int i=0; i < rows+1; i++) 
    {
        fscanf(infile, "%s", words[i]);
//        printf("%s    ", words[i]);
    }
    for(int i=0;i<rows+1;i++) 
    {
//        printf("\n%s \n", words[i]);
        for(int j=0; j<chars;j++) 
        {
            if(words[i][j] == ';') 
            {
                words[i][j] = ' ';
            }
        }
        if(i==2) {
           strcpy(words[i], "Hessu 23");
        }
        printf("%s \n", words[i]);
    }

    return 0;
}