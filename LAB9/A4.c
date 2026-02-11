//  WAP to find the largest element in the array using Pointer.


#include <stdio.h>
#include<stdlib.h>

int main() {
    int n, i;
    int max;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *ptr= (int *)malloc(n*sizeof(int));
    
     for(int i=0;i<n;i++)
      {
            scanf("%d",ptr + i);
      }

        
    max = *ptr;     
    for(i = 0; i < n; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }

   printf("MAX is : %d",max);

    return 0;
}
