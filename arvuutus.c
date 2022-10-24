#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int randomize();
void clearBuffer();

int randomize()
{
    int random;
    random = rand()%(100-1) + 1;
    return random;
}

void clearBuffer()
{
    char c;
    while ( (c = getchar()) != '\n' && c != EOF);
}


int main()
{
    srand(time(NULL));
    int randNum=randomize(), userNum;
    char choice;

    do {
        userNum = 0;

        printf("Anna luku (vastaus on %d) > ", randNum);
        scanf("%d", &userNum);

        if(userNum == randNum) {
            randNum = randomize();

            printf("OIKEIN! \nHaluatko yrittaa uudelleen (vastaa k, jos haluat jatkaa ja e jos et halua jatkaa pelia)? ");
            do {
                scanf(" %c", &choice);
                if(!(isdigit(choice))) {
                    if( choice == 'e') {
                        break;
                    }
                } else {
                    clearBuffer();
                }

            } while(choice != 'k');

        } else {
            if(userNum < randNum) {
                printf("Liian pieni luku, yrita uudelleen.\n");
            } else {
                printf("Liian suuri luku, yrita uudelleen.\n");
            }
        }
        
    } while(choice != 'e');
    return 0;
}

