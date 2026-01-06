#include<stdio.h>
void main(){
    int size;
    printf("Enter Size: ");
    scanf("%d",&size);
    int A[size][size] , B[size][size] , C[size][size];
     printf("Enter Frist Array: ");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter second Array: ");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&B[i][j]);
        }
    }
     
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Sum of matrix: \n");
     for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

}