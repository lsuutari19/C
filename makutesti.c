#include <stdio.h>



#define MAX_SIZE 3
#define NUMDRINKS 2

typedef struct 
{
    int drinks[4][MAX_SIZE];
} drinkRatings;



int rateDrinks(drinkRatings *d, int num);
void clearBuffer();

int rateDrinks(drinkRatings *d, int num)
{
    int rating; 
    int count=0;
    do{
        printf("Anna arvosana (1-5) > ");
        scanf("%d", &rating);

        if(rating < 6 && rating > 0) {
            d->drinks[num][count] = rating;
            printf("se oli %d rivilta %d : %d\n", num, count, rating);
            count++;        
        } else {
            printf("ARVOSANAN TULEE OLLA VALILTA 1 - 5 !\n");
            clearBuffer();
        }
    } while(count < MAX_SIZE);
    return 0;
}

int main() {
    int num=0;
    drinkRatings drink[NUMDRINKS][MAX_SIZE];
    do
    {
        printf("Anna juoma numero %d. pisteet\n", num+1);
        rateDrinks( &drink[num][0], num );
        num ++;
    }while(num < NUMDRINKS);

    for(int i=0; i<NUMDRINKS; i++){
        for(int j=0;i<MAX_SIZE;j++) {
            printf("%d\n", drink[i][j].drinks);
            getchar();
        }
    }

    return 0;
}


void clearBuffer()
{
    char c;
    while ( (c = getchar()) != '\n' && c != EOF);
}
