#include <stdio.h>

#define MAX_SIZE 10
#define NUMDRINKS 4





double rateDrinks();
void clearBuffer();

double rateDrinks()
{
    int ratings[MAX_SIZE];
    int rating; 
    int count=0;
    
    do{
        printf("Anna arvosana (1-5) > ");
        scanf("%d", &rating);

        if(rating < 6 && rating > 0) {
            ratings[count] = rating;
            count++;        
        } else {
            printf("ARVOSANAN TULEE OLLA VALILTA 1 - 5 !\n");
            clearBuffer();
        }
    } while(count < MAX_SIZE);
    
// Valintakriteerinä on: juoma, jonka yli puolet maistelijoista arvostaa arvosanalla 3 tai enemmän, pääsee jatkoon ja muut hylätään.
    int isGood=0;
    for(int i=0; i < MAX_SIZE; i++) {
        if(ratings[i] >= 3) {
            isGood++;
        }
    }
    printf("%d\n", isGood);
    return isGood;
}

int main() {
    int num=0;
    int drinkRatings[NUMDRINKS];
    do
    {
        printf("Anna juoma numero %d. pisteet\n", num+1);
        drinkRatings[num] = rateDrinks();
        num ++;
    }while(num < NUMDRINKS);

    for(int i=0; i < NUMDRINKS; i++) 
    {
        if( drinkRatings[i] >= 5 ) {
            printf("Juoma numero %d on kelvollista.\n", i+1);
        } else {
            printf("Juoma numero %d on kelvotonta\n", i+1);
        }
    }
    return 0;
}


void clearBuffer()
{
    char c;
    while ( (c = getchar()) != '\n' && c != EOF);
}
