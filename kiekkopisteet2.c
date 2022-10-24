#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 20

typedef struct {
    char name[MAX_SIZE];
    int wins;
    int losses;
    int difference;
} teams;


int addteam(teams data[MAX_SIZE]);
void sortTeams(teams data[MAX_SIZE], int n);



int addteam(teams data[MAX_SIZE]) {
    char buffer[100];

    printf("Name of team > ");
    fgets(data.name, sizeof(buffer), stdin);

    printf("Wins of team > ");      
    fgets(buffer, sizeof(buffer), stdin);
    t->wins = atoi(buffer);
    t->difference = atoi(buffer);   

    printf("Losses of team > ");
    fgets(buffer, sizeof(buffer), stdin);
    t->losses = atoi(buffer);

    t->difference = t->difference - atoi(buffer);

    return 0;
}


void sortTeams(teams data[MAX_SIZE], int n) {
    int i, j;
    teams temp;

    for(i = 0; i < n - 1 ; i++) 
    {
        for(j=0; j < n - 1 - i; j++) 
        {
            if( data[j].difference < data[j+1].difference) 
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}


int main() {
    int numOfTeams;
    char array[MAX_SIZE];
    char * Ptr;

    printf("Number of teams > ");
    fgets(array, MAX_SIZE, stdin);

    numOfTeams = strtol(array, &Ptr, 10);

    teams team[MAX_SIZE] = {{ .name = ""}}; 
    for(int i=0; i < numOfTeams; i++) 
    {
        addteam( &team[i] );
    }

    sortTeams(&team, numOfTeams); 

    for(int j=0; j<numOfTeams; j++) 
    {
        printf("team %d name is %s   %d   %d    %d\n",j+1, team[j].name, team[j].wins, team[j].losses, team[j].difference);
    }

}

