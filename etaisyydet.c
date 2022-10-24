#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_SIZE 20
typedef struct {
    int x;
    int y;
} coordinates;



int addDistances(coordinates *c, int count);


int addDistances(coordinates *c, int count) {
    char buffer[100];
    char *ptr;

    printf("Anna x (%d) > ", count);
    fgets(buffer, sizeof(buffer), stdin);
    c->x = strtol(buffer, &ptr, 10);

    
    printf("Anna y (%d) > ", count);
    fgets(buffer, sizeof(buffer), stdin);
    c->y = strtol(buffer, &ptr, 10);
}

int main() {
    int i;
    coordinates coord[MAX_SIZE];
    double distance=0;
    for(i=0; i<5; i++) 
    {
        addDistances( &coord[i], i+1 );
    }

    for(int j=0; j<4;j++)
    {
        distance = distance + sqrt( (( coord[j].x - coord[j+1].x ) * ( coord[j].x-coord[j+1].x )) + (( coord[j].y - coord[j+1].y ) * (coord[j].y-coord[j+1].y)) );
    }
    printf("etaisyys mutkitellen on %.3f ", distance);
    printf("alku ja loppupisteiden valinen etaisyys on %.3f", sqrt( ( coord[0].x - coord[4].x ) * ( coord[0].x-coord[4].x ) + ( coord[0].y - coord[4].y ) * (coord[0].y-coord[4].y) ) );
    return 0;
}
