#include <stdio.h>
#include <time.h>
#include <stdlib.h>


// tehty ja testattu otto -> muu summa, testaa vielä ne valmiit summat
// saldo ja summat testattu



int mainScreen();
int withdraw(int option, int money);
int functionHandle(int checkings);
void clearBuffer();




int main() {
    // alustetaan random integer ihan vain otto kohtaa varten
    int start = 0, saldo = 1000;
    while(1) {
        start = 1;
        do
        {
            printf("\n\n        Tervetuloa! \n");
            printf("\nSyota kortti, ole hyva (any key)  \n\n");
            getchar();
            printf("\n  Anna tunnusluku (any key)  \n\n");
            getchar();

            // siirry käsittelijäfunktioon
            saldo = functionHandle(saldo);

        } while(start == 1);
    }
    return 0;
}


int functionHandle(int checkings) {
    // käsittelee eri funktioista palautettuja arvoja.
    // käytännössä hoitaa koko ohjelman sujuvan suorituksen.
    int mainChoice;

    do{
        mainChoice = mainScreen();

        // jos valinta 1 mennään nosto valikkoon
        if(mainChoice == 1) 
        {
            do 
            {    
                int withChoice = withdraw(1, checkings);

                if(withChoice == -1)
                {
                    break;
                }
                checkings = checkings - withChoice;
                mainChoice = 100;
            } while(mainChoice == 1);
        }
        
        // jos valinta 2 mennään saldo valikkoon
        else if(mainChoice == 2)
        {
            
            printf("Tilin saldo:                %.2d+\n", checkings);
            printf("Tililta nostettavissa:      %.2d+\n", checkings - 100);
            printf("Kortin kateisnostovara:     %.2d+\n\n", checkings - 200);
            printf("Lopeta (enter) >");
            getchar();
            getchar();
            printf("\n\n");
        }
        // jos valinta 3 mennään tapahtumat valikkoon
        else if( mainChoice == 3 )
        {
            printf("Haluatko tiedot?\n\n\n");
            printf("(1) Naytolle > \n");
            printf("(2) Kuitille > ");
            getchar();
            getchar();
        }
        // jos valinta 4 mennään liittymänlataus valikkoon
        else if( mainChoice == 4 ) 
        {
            int phoneCarrier=99;
            do
            {
                printf("\n\n\n        Liittyman lataus\n");
                printf("         Valitse palvelu\n");
                printf("                         saunalahti(1)\n");
                printf("                                dna(2)\n");
                printf("(4) Alkuun                Go Mobile(3)\n");
                printf("\n\n\n");
                printf(">");
                if(scanf("%d", &phoneCarrier) == 1) {
                    continue;
                } else {
                    printf("Tarkista syote. (kokonaisluku)\n");
                    clearBuffer();
                }
            } while ( phoneCarrier < 1 || phoneCarrier > 4 );

            if(phoneCarrier != 4) 
            {
                int phonePlan = withdraw(0, checkings);
                if(phonePlan == -1)
                {
                    break;
                }
                printf("        Hyvaksy maksu\n");
                printf("puhelin numero      0504648451\n");
                printf("Ladattava summa         %d+\n", phonePlan);
                printf("Otto tililta            %d-\n", phonePlan);
                printf("                        Hyvaksy>\n");
                printf("(paina enter)\n ");
                checkings = checkings - phonePlan;
                getchar();
                getchar();
                mainChoice = 102;
                break;
                
            }
        }

    } while( mainChoice < 99 );
    printf("\n\n\nOta kortti, ole hyva!\n\n");

    if(mainChoice == 100)
    {
        printf("Rahat tulossa (paina enter jatkaaksesi)");
        getchar();
        getchar();
    } 
    else 
    {
        printf("Latausvahvistus tekstiviestilla.\n");
        printf(" (paina enter) ");
        getchar();

    }
    return checkings;
}


int mainScreen() {
    // täällä tapahtuu ainoastaan alustus
    int choice=0, condition = 0;

    do
    {
        printf("\n\n            Valitse yksi: \n");
        printf("\n\n1.Otto  2.Saldo  3.Tapahtumat  4.Liittymanlataus \n");
        printf("\n\n        > ");
        if(scanf("%d", &choice) == 1) {
            continue;
        } else {
            printf("Tarkista syote. (kokonaisluku)\n");
            clearBuffer();
        }
    } while ( choice < 1 || choice > 4 );


    return ( choice );

}



int withdraw(int option, int money) {
    // käsittelee noston ja liittymän latauksen
    // erillisten taulujen avulla riippuen option muuttujan arvosta
    int withCond = 0, wChoice, withdrawAmount;
    int withTable[8] = {20, 40, 60, 90, 140, 240};
    int phonePlan[8] = {10, 15, 20, 225, 30, 50};
    int tempTable[8] = {};
    char *tempChar[20] = {"Muu summa", "100", "Otto", "Liittyman lataus", "Alkuun"};

    if(option == 1){
        for(int i = 0; i < 7; i++) 
        {
            tempTable[i] = withTable[i];
        }
    } 
    else 
    {
        for(int j = 0; j < 7; j++) {
            tempTable[j] = phonePlan[j];
            tempChar[0] = tempChar[1];
            tempChar[2] = tempChar[3];
        }
    }

    do
    {
        printf("                %s\n", tempChar[2]);
        printf("(1) %-10d        |          %d(2)\n", tempTable[0], tempTable[1]);
        printf("(3) %-10d        |          %d(4)\n", tempTable[2], tempTable[3]);
        printf("(5) %-10d        |          %d(6)\n", tempTable[4], tempTable[5]);
        printf("(7) %-10s        |          %s(8)\n", tempChar[4], tempChar[0]);
        printf("\n\n\n");
        printf("Tee valinta (1-8) > ");
        if(scanf("%d", &wChoice) == 1) {
            continue;
        } else {
            printf("Tarkista syote. (kokonaisluku)\n");
            clearBuffer();
        }

    } while(  wChoice < 1 || wChoice > 8 );

    if( wChoice == 7 ) {
        withdrawAmount = -1;
    }

    if (option==1)
    {   
        // jos valinta oli otto niin returnataan siita poydasta arvo
        withdrawAmount = withTable[wChoice-1];
    } 
    else 
    {
        // tai sitten phoneplan jos liittyman lataus
        withdrawAmount = phonePlan[wChoice-1];
    }

    return withdrawAmount;

}

void clearBuffer()
{
    char c;
    while ( (c = getchar()) != '\n' && c != EOF);
}


