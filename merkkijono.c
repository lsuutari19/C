#include <stdio.h>
#include <string.h>


void etsiMerkkijonoAlusta(char * str1, char * str2, char * same);

int main(void) {
    
    char mjono1[100];
    char mjono2[100];
    char loydetty[10]={'\0'}; 
    
    printf("Anna merkkijono > ");
    scanf("%s", mjono1);

    printf("Anna merkkijono > ");
    scanf("%s", mjono2);

    etsiMerkkijonoAlusta(mjono1, mjono2, loydetty); 
    printf("%s", loydetty);
    
    return 0;
}

void etsiMerkkijonoAlusta(char * str1, char * str2, char * same) {
    
    for(int i=0; i < strlen(str1); i++) {
        if(str1[i] == str2[i]) {
            same[i] = str1[i];
        }else {
            break;
        }
    }
}