#include<stdio.h>
void main(){
    int size,i;
    printf("Enter number: ");
    scanf("%d",&size);
    int A[size];

    for(i=0;i<size;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<size;i++){
        if(A[i] == A[i+1]){
            printf("%d",i);
            break;
        }
    }
}