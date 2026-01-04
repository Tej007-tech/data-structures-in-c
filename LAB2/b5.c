#include<stdio.h>
void main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int temp = 1;
    for(int i=2;i<n/2;i++){
        if((n%i == 0)){
           temp = 0;
        }
        
    }
    if(temp == 1){
        printf("prime number");

    }
    else{
        printf("not prime number");
    }
}

