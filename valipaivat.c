#include <stdio.h>

int calculateDifference(int y1, int m1, int d1, int y2, int m2, int d2);
int compareDate(int y1, int m1, int d1, int y2, int m2, int d2 );
int getLeapYears(int start, int month, int end);
// leapyear is divisible by 4!


const int DaysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


int compareDate(int y1, int m1, int d1, int y2, int m2, int d2 ) {
    
    if(y1 > y2) {
        printf("**** Aloitusvuosi on myohempi kuin lopetusvuosi\n");
        return 1;
    }
    if( (y1+m1+d1) == (y2+m2+d2) ) {
        printf("Paivaykset ovat samat!\n");
        return 2;
    }
    if (y1 == y2) {
        if(m1 > m2) {
            printf("**** Koska aloitusvuosi on sama kuin lopetusvuosi\n");
            printf("**** niin, aloituskuukausi ei voi olla suurempi kuin lopetuskuukausi!\n");
            return 3;
        }
    }
    if(y1==y2) {
        if(m1 == m2) {
            if(d1 > d2) {
                printf("**** Koska aloitusvuosi on sama kuin lopetusvuosi\n**** ja aloituskuukausikin on sama kuin lopetuskuukausi\n**** niin aloituspaiva ei voi olla suurempi kuin lopetuspaiva!");
                return 4;
            }
        }
    }
    return 0;
}

int calculateDifference(int y1, int m1, int d1, int y2, int m2, int d2){
    int difference=0, leaps;
    int days1 = y1 * 365 + d1;
    int days2 = y2 * 365 + d2;

    for(int i = 0; i < m1 - 1; i++) {
        days1 = days1 + DaysInMonths[i];
    }
    for (int j = 0; j < m2 - 1; j++) {
        days2 = days2 + DaysInMonths[j];
    }

    difference = days2 - days1 + getLeapYears(y1, m1, y2);
    return difference;
}


int getLeapYears(int start, int month, int end) {

    int leapDays=0, years = end - start;
    if(month < 2) {
        leapDays = -1;
    }
    leapDays = leapDays + years / 4 + 1;
    leapDays = leapDays - years / 100;
    leapDays = leapDays + years / 400;
    return leapDays;
}


int main() {
    int year1, month1, day1, year2, month2, day2;
    int comparison, numDays;

    printf("Anna vuosi > ");
    scanf("%d", &year1);

    printf("Anna kuukausi > ");
    scanf("%d", &month1);

    printf("Anna paiva > ");
    scanf("%d", &day1);

    printf("Anna vuosi > ");
    scanf("%d", &year2);

    printf("Anna kuukausi > ");
    scanf("%d", &month2);

    printf("Anna paiva > ");
    scanf("%d", &day2);

    comparison = compareDate(year1, month1, day1, year2, month2, day2);
    if(comparison == 0) {
 
        numDays = calculateDifference(year1, month1, day1, year2, month2, day2);
        printf("%d", numDays);
    }

}