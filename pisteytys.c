#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_SIZE 200

typedef struct {
    char name[MAX_SIZE];
    double total;
} competitors;


void addteam(competitors *t);
void sortCompetitors(competitors data[MAX_SIZE], int n);



void addteam(competitors *t) {
    char buffer[MAX_SIZE];
    char name[MAX_SIZE];
    char minutes[MAX_SIZE];
    char seconds[MAX_SIZE];
    double sec;

    printf("Kilpailijan nimi > ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    strcpy(t->name, name);

    printf("Aika 500m > ");
    fgets(buffer, sizeof(buffer), stdin);
    char *ptr;
    ptr = strtok(buffer, ".");
    strcpy(minutes, ptr);
//    printf("%s ", minutes);
    ptr = strtok(NULL, " ");  
    strcpy(seconds, ptr);
//    printf("%s\n", seconds);


    sec = atoi(minutes) * 60 + strtod(seconds, &ptr);
//    printf("%lf rounded is %lf\n",sec,  round(sec/3 * 100) /100);
//    printf("total is at 1500m %lf\n", t->total + roundf(sec / 3 *100) / 100);
    t->total = t->total + roundf(sec * 1000) / 1000;

    
    printf("Aika 1500m > ");
    fgets(buffer, sizeof(buffer), stdin); 

    ptr = strtok(buffer, ".");
    strcpy(minutes, ptr);
//    printf("%s ", minutes);
    ptr = strtok(NULL, " ");  
    strcpy(seconds, ptr);
//    printf("%s\n", seconds);


    sec = atoi(minutes) * 60 + strtod(seconds, &ptr);
//    printf("%lf rounded is %lf\n",sec,  round(sec/3 * 100) /100);
//    printf("total is at 1500m %lf\n", t->total + roundf(sec / 3 *100) / 100);
    t->total = t->total + roundf(sec / 3 * 1000) / 1000;
//    printf("%lf", t->total);
    
    printf("Aika 5000m > ");
    fgets(buffer, sizeof(buffer), stdin);

    ptr = strtok(buffer, ".");
    strcpy(minutes, ptr);
    ptr = strtok(NULL, " ");  
    strcpy(seconds, ptr);

    sec = atoi(minutes) * 60 + strtod(seconds, &ptr);
    t->total = t->total +  roundf(sec / 10 * 1000) / 1000;

    printf("Aika 10000m > ");
    fgets(buffer, sizeof(buffer), stdin);

    ptr = strtok(buffer, ".");
    strcpy(minutes, ptr);
    ptr = strtok(NULL, " ");  
    strcpy(seconds, ptr);

    sec = atoi(minutes) *60 + strtod(seconds, &ptr);
    t->total = t->total +  roundf(sec / 20 * 1000) / 1000;

}


void sortCompetitors(competitors data[MAX_SIZE], int n) {
    int i, j;
    competitors temp;

    for(i = 0; i < n - 1 ; i++) 
    {
        for(j=0; j < n - 1 - i; j++) 
        {
            if( data[j].total > data[j+1].total) 
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}


int main() {
    int numOfComp;
    char array[MAX_SIZE];
    char * Ptr;

    printf("Joukkueiden lkm > ");
    fgets(array, MAX_SIZE, stdin);

    numOfComp = strtol(array, &Ptr, 10);

    competitors comp[MAX_SIZE] = {{ .name = ""}}; 
    for(int i=0; i < numOfComp; i++) 
    {
        addteam( &comp[i] );
    }

    sortCompetitors( comp, numOfComp); 
    printf("\n");

    for(int j=0; j < numOfComp; j++) 
    {
        printf("%d. %s %.3lf \n",j, comp[j].name, comp[j].total);
    } 
}

