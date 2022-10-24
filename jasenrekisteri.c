#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 200

typedef struct {
    char name[MAX_SIZE];
    char family[MAX_SIZE];
    int id;
    int join_date;
    int last_dues[MAX_SIZE];
    int not_paid;
} members;


void add_members(members *m);
void remove_member(int num, members *m);
void change_member(int num, members *m);
void search_member(int num, members *m);


void add_members(members *m){
    // pitää erotella etu ja sukunimi!
    char fullname[MAX_SIZE];
    char buffer[MAX_SIZE];

    printf("\nAnna Jasenen Etu- ja Sukunimi  > ");
    getchar();
    fgets(fullname, MAX_SIZE, stdin);
    fullname[strcspn(fullname, "\n")] = 0;
//    printf("\nfull name: %s", fullname);

    char *ptr = strtok(fullname, " ");
    strcpy(m->name, ptr);
    ptr = strtok(NULL, " ");
    strcpy(m->family, ptr);


    printf("\nAnna jasennumero > ");
    fgets(buffer, sizeof(buffer), stdin);
    m->id = atoi(buffer);
//    printf("\n: %s", buffer);

    printf("\nAnna liittymisvuosi > ");
    fgets(buffer, sizeof(buffer), stdin);
    m->join_date = atoi(buffer);
//    printf("\n: %s", buffer);


    for(int i = 0; i<5; i++) 
    {
        printf("\nAnna vuoden %d jasenmaksu > ", i+2016);
        fgets(buffer, sizeof(buffer), stdin);
        m->last_dues[i] = atoi(buffer);
        if(atoi(buffer) == 0) {
            m->not_paid = m->not_paid + 1;
        }
//        printf("\n: %s", buffer);
    }
}

void remove_member(int num, members *m){
    int idnum;
    
    printf("Anna poistettavan jasenen jasennumero > ");
    scanf("%d", &idnum);
    for(int i=0; i<num;i++) 
    {
        if(m[i].id == idnum) {
            m[i].id = 0;
        }
    }
}

void change_member(int num, members *m){
    char choices[5][20] = {"etunimi", "sukunimi", "jasennumero", "liittymisvuosi", "jasenmaksutietoja"};
    int idnum;
    int c_choice;
    char buffer[MAX_SIZE];
    
    printf("Anna muutettavan jasenen jasennumero > ");
    scanf("%d", &idnum);

    printf("1 Muuta etunimi\n2 Muuta sukunimi\n3 Muuta jasennumero\n4 Muuta liittymisvuosi\n5 Muuta jasenmaksutietoja\n\nValintasi >");
    scanf("%d", &c_choice);

    printf("Anna uusi %s >", choices[c_choice-1]);
    getchar();
    fgets(buffer, MAX_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    if(c_choice == 1) 
    {
        for(int i=0; i<num;i++) 
        {
            if(m[i].id == idnum) {
                strcpy(m[i].name, buffer);
            }
        }
    }
    if(c_choice == 2)
    {
        for(int i=0; i<num;i++) 
        {
            if(m[i].id == idnum) {
                strcpy(m[i].family, buffer);
            }
        }
    }
    if(c_choice == 3)
    {
        for(int i=0; i<num;i++) 
        {
            if(m[i].id == idnum) {
                m[i].id = atoi(buffer);
            }
        }
    }
    if(c_choice == 4)
    {
        for(int i=0; i<num;i++) 
        {
            if(m[i].id == idnum) {
                m[i].join_date = atoi(buffer);
            }
        }
    }
    if(c_choice == 5)
    {
        for(int i=0; i<num;i++) 
        {
            if(m[i].id == idnum) {
                continue; // tee tahan se vaa jos tarkistin vaatiii...
            }
        }
    }
}

void search_member(int num, members *m){
    char buffer[MAX_SIZE];
    int s_choice;

    printf("1 Haku etunimella\n2 Haku sukunimella\n3 Haku jasennumerolla\n4 Haku liittymisvuodella\n5 Haku jasenmaksurastien perusteella\n\nValintasi > ");
    scanf("%d", &s_choice);

    fgets(buffer, MAX_SIZE, stdin);


    for(int i=0; i<num;i++) 
    {
        if(s_choice == 1) 
        {
            continue; //toteuta   
        }
    }

}

int main() {

    int choice = 0;
    int number = 0;
    int id;

    members mem[MAX_SIZE] = {{ .name = ""}}; 

    do{
        printf("1 Uuden jasenen lisaaminen\n2 Jasenen tietojen poisto\n3 Jasenen tietojen muuttaminen\n4 Tulosta jasen\n5 Tulosta rekisteri\n6 Haku\n7 Lopetus\n\n Valintasi > ");
        scanf("%d", &choice);
        if(choice == 1) {
            add_members( &mem[number] );
            number++;
        } else if (choice == 2) 
        {
            remove_member(number, mem);
        }
        else if (choice == 3)
        {
            change_member(number, mem);
        }
        else if (choice == 4) 
        {
            printf("\nAnna jasennumero >");
            scanf("%d", &id);
            
            for(int i=0; i < number; i++) 
            {
                if(mem[i].id == id) {
                    printf("\nETUNIMI: %s\n SUKUNIMI: %s\n JASENNRO: %d\nLIITTVUOSI: %d\n",mem[i].name, mem[i].family,mem[i].id,mem[i].join_date);
                }
            }
        }
        else if ( choice == 5) 
        {
            printf("***************************\n");
            for(int i=0; i < number; i++) 
            {
                if(mem[i].id == 0) {
                    continue;
                } else {
                    printf("ETUNIMI: %s\nSUKUNIMI: %s\nJASENNRO: %d\n LIITTVUOSI:%d\n", mem[i].name, mem[i].family, mem[i].id, mem[i].join_date);
                }   
            }
        }
        else if( choice == 6)
        {
  //          search_member()
            continue;
        }
    } while (choice != 7);

}

