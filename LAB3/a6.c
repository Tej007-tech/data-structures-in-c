#include<stdio.h>
void main(){
      int size,i;
    printf("Enter number: ");
    scanf("%d",&size);
    int A[size];

    for(i=0;i<size;i++){
        scanf("%d",&A[i]);
    }
    int num1,num2;
    printf("Enter number: ");
    scanf("%d",&num1);
    printf("Enter number: ");
    scanf("%d",&num2);
    for(i=0;i<size;i++){
        if(A[i] == num1){
           A[i] = num2;
        }
    }
    for(i=0;i<size;i++){
        printf("%d ",A[i]);
    }

}