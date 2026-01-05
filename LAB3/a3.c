#include<stdio.h>
void main(){
    int size,i;
    int sum = 0;
    printf("Enter number: ");
    scanf("%d",&size);
    int A[size];
    for(i=0;i<size;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<=size;i++){
        sum = sum + A[i];
    }
    printf("%d\n",sum);
    float avg = sum/size;
    printf("%f",avg);
}