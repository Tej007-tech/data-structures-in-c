#include<stdio.h>
void main(){
    int size;
    // printf("Enter Size: ");
    // scanf("%d",&size);
    int A[3][2] , B[2][3] , C[3][3],i,j,m;
     printf("Enter Frist Array element: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&A[i][j]);
        }
    }
    
    printf("Enter second Array element: \n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&B[i][j]);
        }
         
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            printf("%d ",A[i][j]);
        }
         printf("\n");
    }
     printf("\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
     
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
             C[i][j] = 0;

            for(int m = 0; m < 2; m++) {
                C[i][j] += A[i][m] * B[m][j];
            }

           
        }
    }
     printf("multiplication of matrix: \n");
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
}