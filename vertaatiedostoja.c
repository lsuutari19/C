#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100



void readFiles(char *fileName);

void readFiles(char *fileName) {

    char arr[MAX_SIZE];
    printf("Anna tiedoston nimi > ");
    fgets(arr, MAX_SIZE, stdin);
    arr[strcspn(arr, "\n")] = 0;
    strcpy(fileName, arr);
}

int main() {
    int i, identical=0;
    FILE * File1;
    FILE * File2;
    char ch1, ch2;
    char array[ MAX_SIZE ];

    readFiles(array);
    File1 = fopen(array, "r");

    readFiles(array);
    File2 = fopen(array, "r");

    ch1 = getc(File1);
    ch2 = getc(File2);


    for(i = 0; i < MAX_SIZE; i++) {
        if(ch1 != ch2){
            identical = 1;
        }   
        ch1 = getc(File1);
        ch2 = getc(File2);
    }

    if(identical == 0) {
        printf("Tiedostot ovat sisalloltaan identtiset.");
    } else if (identical == 1) {
        printf("Tiedostot eivat ole identtisia.");
    }
         
    return 0;
}