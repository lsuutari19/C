#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void printWrongs(int num);


void printWrongs(int num){
    printf("\n");
    if(num == 1)
    {
        printf("-------     \n");
    }
    if(num == 2)
    {
        printf("   |        \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("-------     \n");
    }
    if(num == 3)
    {
        printf("   ______   \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("-------     \n");
    }
    if(num == 4)
    {
        printf("   ______   \n");
        printf("   |    |   \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("-------     \n");
    }
    if(num == 5)
    {
        printf("   ______   \n");
        printf("   |    |   \n");
        printf("   |    O   \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("-------     \n");
    }
    if(num == 6)
    {
        printf("   ______   \n");
        printf("   |    |   \n");
        printf("   |    O   \n");
        printf("   |    |   \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("-------     \n");
    }
    if(num == 7)
    {
        printf("   ______   \n");
        printf("   |    |   \n");
        printf("   |    O   \n");
        printf("   |   /|\\ \n");
        printf("   |        \n");
        printf("   |        \n");
        printf("-------     \n");
    }
    if(num == 8)
    {
        printf("   ______   \n");
        printf("   |    |   \n");
        printf("   |    O   \n");
        printf("   |   /|\\ \n");
        printf("   |   / \\ \n");
        printf("   |        \n");
        printf("-------     \n"); 
    }
}


int main () {

    FILE * infile;
    char ch;
    int rows=0;
    int dead = 9;


    infile = fopen("sanat.txt", "r");
    srand(time(NULL));
    

    while((ch = fgetc(infile)) != EOF) 
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
    while(wrong < dead) 
    {
        int flag = 0;
        char arvaus;
        printf("Arvaa kirjain: > ");
        fflush(stdout);
        scanf("%c%*c", &arvaus);


        for(int i=0; i < wordLen; i++) 
        {
            if(correctWord[i] == arvaus) 
            {
                hidden[i] = 1;
                flag = 1;
            }
        }
        if(flag == 0) {
            wrong ++;
//            printf("wrong number: %d", wrong);
            printWrongs(wrong);

        }
        printf("\n");
        for(int j=0; j < wordLen; j++)
        {
            if(hidden[j]) 
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
            if(!(hidden[k])) 
            {
                won = 0;
            }
        }
        if(won == 1) {
            printf("Hienoa, arvasit oikein!");
            break;
        }
        if(wrong == 9) {
            printf("Arvattava sana oli: %s", correctWord);
        }

    }
    return 0;
}