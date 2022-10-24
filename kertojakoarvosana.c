

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int randomize();

int main()
{
    srand(time(NULL));
    int num1, num2, user=0, answer, correct=0, wrong=0;
    char grade[20] = "\"Hyvaksytty\"";
    do {
        num1=randomize();
        num2=randomize();

        if( num1 % num2 != 0 ) {
            answer=num1 * num2;
            printf("Paljonko on %d kertaa %d? ", num1, num2);  
        } else {
            answer=num1/num2;
            printf("Paljonko on %d jaettuna %d? ", num1, num2); 
        }
    
        while(1) {
            scanf("%d", &user);
            
            if(user == -1 || user == 1) 
            {
//                wrong += 1;
                break;
            }
            if(user==answer) 
            {
                printf("Oikein! %d\n", correct+1);
                user = 1;
                correct += 1;
                break;
            } 
            else 
            {
                printf("%d wrong ", wrong+1);
                printf("Vaarin yrita uudelleen > ");
                wrong += 1;
            }
        }
    } while(user != -1);
    
    if(correct - wrong < 0) {
        strcpy(grade, "\"Hylatty\"");
    }
        
    printf("Sait %d oikein, ja %d meni pikkuisen pieleen \nArvosanasi on : %s", correct, wrong, grade); 
    return 0;
}

int randomize()
{
    int random;
    random = rand()%(9-1) + 1;
    return random;
}