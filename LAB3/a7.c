     #include <stdio.h>

int main() {
    int rows, i, j, num;
  
    printf("Enter  rows: ");
    scanf("%d", &rows);
    // for(i = 5;i<5;i++){
    //     for(j = 0;j<=i;j++){
    //         printf("  ");
    //     }
    //     printf("\n");
    // }
    for(i = 0; i < rows; i++) {
        
        for(j = 0; j < rows - i - 1; j++) {
            printf("  ");
        }

        num = 1;
        for(j = 0; j <= i; j++) {
            printf("%4d", num);
            num = num * (i - j) / (j + 1); 
        }
        printf("\n");
    }

    return 0;
}


