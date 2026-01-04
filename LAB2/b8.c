#include<stdio.h>
void main(){
    int n,i,j;
    // for(i = 5;i<5;i++){
    //     for(j = 0;j<=i;j++){
    //         printf("  ");
    //     }
    //     printf("\n");
    // }
    
    for(i = 5;i>=1;i--){
        for(j = 0;j<=i;j++){
            printf("  ");
        }
        printf("\n");
      
    
      int num = 1;
      
     for(j = 0; j <= i; j++) {
            num = num * (i - j) / (j + 1);
            printf("%4d", num);
            
    }
}

}