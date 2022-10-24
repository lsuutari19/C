#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// muuta näitä jos haluat enemmän rivejä/numeroita per rivi/suurentaa numeroiden arvoa
#define MAX_ROWS 5
#define NUM_PER_ROW 7
#define MAX_NUM 40


int printRows(int m[MAX_ROWS][NUM_PER_ROW]);
int doStuff(int count);


int doStuff(int count) 
{
    int matrix[MAX_ROWS][NUM_PER_ROW], jackpot[NUM_PER_ROW + 3];
    int num=0, i, j, cnt=0, flag, temp=0;
    
    // täytetään käyttäjän valitsemat rivit
    for(i=0; i < count; i++)
    {
        for(j=0; j < NUM_PER_ROW; j++) 
        {
            printf(" > ");
            scanf("%d", &num);
            matrix[i][j] = num;
        }
    }
    for(i=count; i<MAX_ROWS;i++)
    {
        for(j=0; j<NUM_PER_ROW; j++)
        {
            matrix[i][j] = rand() % 40 + 1;
        }
    }
    
    // luodaan voittorivi uniikeilla luvuilla
    while(cnt < 10) { 
		int randNum = rand() % 40 +1;
        jackpot[cnt] = randNum;
        cnt++;
	}     
    
    // tulostetaan rivit
    printf("\nLottorivit: \n");
    for(i=0; i < MAX_ROWS; i++)
    {
        for(j=0; j < NUM_PER_ROW; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    } 
    
    printf("Oikea rivi: %d %d %d %d %d %d %d lisanumerot: %d %d %d\n", jackpot[0], jackpot[1], jackpot[2], jackpot[3], jackpot[4], jackpot[5], jackpot[6],jackpot[7], jackpot[8], jackpot[9]);

    // tarkistetaan montako jokaisella rivilla on oikein.
     for(i=0; i<MAX_ROWS; i++) 
    {
        int correct = 0;
        int extra = 0;
        for(j=0; j<NUM_PER_ROW;j++)
        {

            int prevCorr[7] = {0,0,0,0,0,0,0};
            int prevExtr[7] = {0,0,0};

            for(int k=0; k<NUM_PER_ROW+3; k++) 
            {
                if(matrix[i][j] == jackpot[k]) 
                {
                    for(int z=0; z<NUM_PER_ROW;z++) 
                    {
                        if( (prevCorr[z] == matrix[i][j]) && (k <= 6)) 
                        {
                            correct -=1;
                            break;
                        }
                        else if( (prevExtr[z] == matrix[i][j]) && (k > 6)) 
                        {
                            extra -=1;
                            break;
                        }
                    }
                    if(k <= 6) 
                    {                       
                        correct += 1;
                        prevCorr[j] = matrix[i][j];
                    } 
                    else 
                    {
                        prevExtr[j] = matrix[i][j];
                        extra += 1;

                    }
                }
            }
        }
        printf("Rivilla %d. on %d oikein ja %d lisanumeroa \n", i+1, correct, extra);
    }
    return 0;
}

int main()
{
    int num;
    srand(time(NULL));

    printf("Montako rivia haluat syottaa (max 5 rivia ) > ");
    scanf("%d", &num);

    if( (num <6) ) {
        doStuff(num);
    }

    return 0;
}

