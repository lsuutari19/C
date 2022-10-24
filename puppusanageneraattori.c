#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX_SIZE 5

int main(){
    char substantiivit[MAX_SIZE][20];
    char verbit[MAX_SIZE][20];
    char buffer[20];

    srand(time(NULL));

    for(int i=0; i < MAX_SIZE; i++) 
    {
        printf("Anna substantiivi (max 100 merkkia) >");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(substantiivit[i], buffer);

        printf("Anna verbi (max 100 merkkia) >");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(verbit[i], buffer);
    } 
    int count;
    printf("Montako puppulausetta generoidaan? ");
    scanf("%d", &count);

    printf("---Puppulauseet---\n");
    // Ohjelma tuottaa käyttäjän haluaman määrän innovatiivisia puppulauseita
    // Lauseet alkavat aina isolla kirjaimella ja loppuvat pisteeseen.
    char subst[20];
    char verb[20]; 
    char sub[20];
    char veb[20];
    
    for(int j=0; j < count; j++) 
    {

        int randNum = rand() % 4 + 1;
        printf("%d\n", j);
        int randSub = rand() % MAX_SIZE + 1;
        int randVerb = rand() % MAX_SIZE + 1;

//        printf("%s %d ", substantiivit[randSub-1], randSub);
        strcpy(subst, substantiivit[randSub-1]);
        strcpy(verb, verbit[randVerb-1]);

        strcpy(sub, substantiivit[rand() % 2 + 1 - 1]);
        strcpy(veb, verbit[rand() % 2 + 1 - 1]);

        subst[0] = toupper(subst[0]);

        if(randNum == 1) 
        {    
            printf("%s %s.\n", subst, verb);
        }
        else if(randNum == 2) 
        {
            printf("%s %s ja %s %s.\n", subst, verb, sub, veb);
        }
        else if(randNum == 3) {
            printf("%s %s tai %s %s.\n", subst, verb, sub, veb);

        }
        else if(randNum == 4) {
            subst[0] = tolower(subst[0]);
            printf("Jos %s %s, niin %s %s.\n",subst, verb, sub, veb);
        }
    }
    return 0;
}