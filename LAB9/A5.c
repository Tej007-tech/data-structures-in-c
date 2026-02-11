//  WAP to sort the array elements using Pointer. 



#include <stdio.h>
#include<stdlib.h>

int main() {
    int n, i,temp;
    int max;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *ptr= (int *)malloc(n*sizeof(int));
    
     for(int i=0;i<n;i++)
    {
            scanf("%d",ptr + i);
    }

        
       
    for(i = 0; i < n; i++) {
      for(int j=0;j<n-i-1;j++)
      
    {
        if (*(ptr + j) > *(ptr + j + 1)) 
        {
           temp = *(ptr + j);
          *(ptr + j) = *(ptr + j + 1);
            *(ptr + j + 1) = temp;

        }
    }
   }
    
    for(int i=0;i<n;i++)
    {
      {
            printf("%d ",*(ptr + i));
      }
    }
    
     free(ptr);
    return 0;
}

