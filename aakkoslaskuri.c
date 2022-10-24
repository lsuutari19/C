#include <stdio.h>
#include <string.h>

/*
Kirjoita ohjelma, joka lukee 3 riviä tekstiä ja laskee tekstissä esiintyvien aakkosten lukumäärän 
ja tulostaa tulokset kuvaruudulle 
(skandeista ei tarvitse välittää). Tulosta vastaukset kahtena sarakkeena, allaolevan mukaisesti:

*/

int main() 
{
    int numbers[26] = { 0 };
    char alphabets[1024] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h','i', 'j','k', 'l','m','n','o','p','q','r', 's', 't', 'u', 'v','w','x', 'y', 'z'};
    char *string[1024] ={"abcd", "efgh", "ijkl"};
    char firstLetter;


/*
    for( int i = 0; i < 3; i++ )
    {
        printf("Anna merkkijono > ");
        scanf("%s", string[i]);
    }
*/
    
    for( int j = 0; j < 3; j++ )
    {
        for(int i = 0; i < strlen(string[j]); i++) 
        {
            printf("string: %c\n", string[j][i]);
            for(int k = 0; k < strlen(alphabets); k++)
            {
                if(string[j][i] == alphabets[k])
                {
                    printf("alphabet: %c\n", alphabets[k]);
                    numbers[k] = numbers[k] + 1;
                }
            }
        }
    }
    printf("Aakkonen    kpl \n");
    int lengthOfNum = sizeof(numbers) / sizeof(numbers[0]);
    for(int z=0; z < lengthOfNum; z++) {
        printf("%c           %d\n", alphabets[z], numbers[z]);
    }
    
 
    return 0;
}