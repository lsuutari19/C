#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void printWrongs(int num);


void printWrongs(int num) {
    printf("Vaarien vastausten maara    Kuvallinen esitys:\n");
    int temp = num;
    if(temp == 1)
    {
        printf("%d                          -------     \n", num);
    }
    else if(temp == 2)
    {
        printf("%d                              |        \n", num);
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                            -------     \n");
    }
    else if(temp == 3)
    {
        printf("%d                              ______   \n", num);
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                            -------     \n");
    }
    else if(temp == 4)
    {
        printf("%d                              ______   \n", num);
        printf("                               |    |   \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                            -------     \n");
    }
    else if(temp == 5)
    {
        printf("%d                              ______   \n", num);
        printf("                               |    |   \n");
        printf("                               |    O   \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                            -------     \n");
    }
    else if(temp == 6)
    {
        printf("%d                              ______   \n", num);
        printf("                               |    |   \n");
        printf("                               |    O   \n");
        printf("                               |    |   \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                            -------     \n");
    }
    else if(temp == 7)
    {
        printf("%d                              ______   \n", num);
        printf("                               |    |   \n");
        printf("                               |    O   \n");
        printf("                               |   /|\\ \n");
        printf("                               |        \n");
        printf("                               |        \n");
        printf("                            -------     \n");
    }
    else if(temp == 8)
    {
        printf("%d                              ______   \n", num);
        printf("                               |    |   \n");
        printf("                               |    O   \n");
        printf("                               |   /|\\ \n");
        printf("                               |   / \\ \n");
        printf("                               |        \n");
        printf("                            -------     \n"); 
    }
}


int main () {

    FILE * infile;
    char ch;
    int rows=0;


    infile = fopen("sanat.txt", "r");
    srand(time(NULL));
    
    // lasketaan rivien lkm (jos olisikin erilaisia tiedostoja)
    while( (ch = fgetc(infile)) != EOF ) 
    {
        if(ch == '\n')
        {
            rows++;
        }
    }
    fclose(infile);

    infile = fopen("sanat.txt", "r");


    char words[rows][100];
    // kopioidaan rivit arrayhyn words
    for(int i=0; i < rows; i++)
    {
        fscanf(infile, "%s", words[i]);
    }

    int randNum = rand() % rows;
    char correctWord[50];
    strcpy(correctWord, words[randNum]);
    int wordLen = strlen(correctWord);

    // taytetaan 0 merkeillä piilotetut kirjaimet
    int hidden[wordLen];
    for(int i=0;i<wordLen;i++) {
        hidden[i] = 0;
    }

//    printf("%s\n", correctWord);
    
    int wrong=0;
    int won = 0;
    while(1) 
    {
        int flag = 0;
        char arvaus;
        printf("Anna kirjain > ");
        fflush(stdout);
        scanf("%c%*c", &arvaus);


        for( int i=0; i < wordLen; i++ ) 
        {
            if(correctWord[i] == arvaus) 
            {
                hidden[i] = 1;
                flag = 1;
            }
        }
        if(flag == 0) {
            wrong++;
            printWrongs(wrong);

        }
        printf("\n");
        for( int j=0; j < wordLen; j++ )
        {
            if( hidden[j] == 1 ) 
            {
                printf("%c", correctWord[j]);
            }
            else 
            {
                printf("_");
            }
        }
        printf("\n");
        //tsekataan voittiko pelaaja :)
        won = 1;
        for(int k=0; k<wordLen;k++)
        {
            if( hidden[k] == 0 ) 
            {
                won = 0;
            }
        }
        if( won == 1 ) {
            printf("Hienoa, arvasit oikein!");
            break;
        }
        if( wrong == 8 ) {
            printf("Arvattava sana oli: %s", correctWord);
            break;
        }

    }
    return 0;
}

