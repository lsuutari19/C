#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_ROWS 5
#define NUM_PER_ROW 7
#define MAX_NUM 40


int doStuff();


int doStuff() 
{
    int matrix[MAX_ROWS][NUM_PER_ROW] = { {1,2,3,4,5,6,7}, {30,38,6,34,4,39,30},{9,37,32,27,9,39,17}, {8,26,6,31,28,29,16}, {33,21,19,7,9,19,30} };
    int jackpot[NUM_PER_ROW + 3] = { 20,37,22,9,34,28,34,24,26,29 };
    int num=0, i, j, cnt=0, temp=0;
    
    printf("Lottorivit: \n");
    for(i=0; i < MAX_ROWS; i++)
    {
        for(j=0; j < NUM_PER_ROW; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    } 
    
    printf("Oikea rivi: %d %d %d %d %d %d %d lisanumerot: %d %d %d\n", jackpot[0], jackpot[1], jackpot[2], jackpot[3], jackpot[4], jackpot[5], jackpot[6],jackpot[7], jackpot[8], jackpot[9]);

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
                        if( (prevCorr[z] == jackpot[k]) && (k <= 6)) 
                        {
                            correct -=1;
                            break;
                        }
                        else if( (prevExtr[z] == jackpot[k]) && (k > 6)) 
                        {
                            extra -=1;
                            break;
                        }
                    }
                    if(k <= 6) 
                    {                       
                        correct += 1;
                        prevCorr[j] = jackpot[k];
                    } 
                    else 
                    {
                        prevExtr[j] = jackpot[k];
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

    doStuff(num);

    return 0;
}

