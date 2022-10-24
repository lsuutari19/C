#include <stdio.h>
#include <stdlib.h>


int main(){
    int userNum;
    int count=0;
    char words[6][20]= {"kymmenta", "sataa", "tuhat"};
    char numbers[8][10] = {"kaksi", "kolme", "nelja", "viisi", "kuusi", "seitseman", "kahdeksan", "yhdeksan"};
    int tempNum[4];

    printf("> ");
    scanf("%d", &userNum);

    while(userNum != 0) 
    {
        tempNum[count] = userNum % 10;
        userNum = userNum / 10;
        count++;
    }

    
    for(int i=3; i>=0;i--) {
        int flag = 0;
        if( (tempNum[i] == 1) && (i == 0) ) 
        {
            printf("yksi");
        } 
        else if ( (i == 3) && (tempNum[i] != 0) ) 
        {
            if (tempNum[i] != 1) {
                printf("%stuhatta", numbers[ tempNum[i] - 2]);
            } else {
                printf("tuhat");
            }
                
        } 
        else if ( (tempNum[i] != 0) && (i > 0) && (tempNum[i] != 1)) 
        {
            printf("%s%s", numbers[ tempNum[i] - 2], words[i-1]);
        } 
        else
        {
//            printf(" %d %d ", tempNum[i], i);
            if((tempNum[i] != 0) && (tempNum[1] == 1) && (i == 0)) {
                flag = 1;
                getchar();
                printf("%stoista", numbers[ tempNum[i] - 2]);
            }
            if( (tempNum[i] != 0) && (flag == 0) ){
                printf("%s", numbers[ tempNum[i] - 2]);
            }
        }   
    }
    return 0;
}
