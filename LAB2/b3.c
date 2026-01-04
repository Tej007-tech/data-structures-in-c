#include<stdio.h>
void main(){
    int n,i;
    printf("Enter number: ");
    scanf("%d",&n);
    int temp = 0;
    while (n>0){
       temp = n % 10 + temp * 10;
       n /= 10;

    }
    printf("%d",temp);
    
    
}