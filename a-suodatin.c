#include <stdio.h>
#include <string.h>


int main() 
{
    char string[5][20];
    char firstLetter;

    for( int i = 0; i < 5; i++ )
    {
        printf("Anna merkkijono > ");
        scanf("%s", string[i]);
    }



    for( int j = 0; j < 5; j++ )
    {
        firstLetter = string[j][0];
        if( firstLetter == 'a' ){
            printf("a merkilla alkava merkkijono: %s \n", string[j]);
        }
    }

    return 0;
}

