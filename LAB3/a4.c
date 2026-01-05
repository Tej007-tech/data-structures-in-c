#include<stdio.h>
void main(){
    int n,i;
    printf("Enter size");
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    int max = A[0];
    int min = A[0];

    for(i=0;i<n;i++){
        if(max<A[i]){
            max = A[i];
           
        }
       
    }
    printf("max = %d",max);
    printf("\n");
    for(i=0;i<n;i++){
        if(min>A[i]){
            min = A[i];
           
        }
       
    }
    printf("min = %d",min);

}