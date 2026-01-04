#include<stdio.h>
void main(){
     int n,temp = 1,sum=0;
     printf("Enter number: ");
     scanf("%d",&n);
    for(int j = 1; j<=n;j++){
        for(int i = 1;i<=j;i++){
            sum = sum + i ;
        }
    }
    printf("%d",sum);
     

}