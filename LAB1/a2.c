#include <stdio.h>

void main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);

    if(n%2 == 0){
        printf("Even number: ");
    }
    else{
        printf("odd number: ");
    }
}
