#include<stdio.h>
void main(){
    int pow ,n;
    printf("Enter number: ");
    scanf("%d",&n);
    printf("Enter power: ");
    scanf("%d",&pow);
    int temp = n;
    for(int i=1;i<pow;i++){
        n = temp*n;
    }
    printf("%d",n);

}