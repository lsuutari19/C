#include <stdio.h>
int laskeKertoma( int luku );
int main(void){

 int luku = 0;
 int kertoma = 1; //nollan kertoma on yksi

 do {
 printf("Anna positiivinen kokonaisluku > ");
 scanf("%d", &luku);

 if( luku < 0 )
 printf("Kertomaa ei ole maaritelty negatiivisille luvuille!\n");

 }while( luku < 0);

 kertoma = laskeKertoma(luku);

 printf("\nLuvun %d kertoma on %d\n", luku, kertoma);

 return 0;
}
// kertomaa ei ole määritelty negatiivisille luvuille
// funktiolle ei saa välittää negatiivisia arvoja
//
int laskeKertoma( int luku ){

 if( luku <= 1 ) //päättymisehto
 return 1;
 else
 return luku * laskeKertoma(luku -1 );

}