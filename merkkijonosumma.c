#include <stdio.h>
#include <string.h>

int main() {
    char mjono1[100], mjono2[100];
    int value1, value2;
    printf("Anna merkkijono > ");
    fgets(mjono1, 100, stdin);

    printf("Anna merkkijono > ");
    fgets(mjono2, 100, stdin);

    sscanf(mjono1, "%d", &value1);
    sscanf(mjono2, "%d", &value2);
    printf("Lukujen %d ja %d summa on %d", value1, value2, value1+value2);
    return 0;
}

