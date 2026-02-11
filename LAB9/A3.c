//  WAP to calculate the sum of n numbers using Pointer. 



#include<stdio.h>
#include<stdlib.h>
void main()
{
      int size,i,sum = 0;

    printf("Enter Size: ");
    scanf("%d",&size);


      int *ptr= (int *)malloc(size*sizeof(int));
      
      for(int i=0;i<size;i++)
      {
            scanf("%d",ptr + i);
      }
      for(int i=0;i<size;i++)
      {
            sum = sum + *(ptr+1);
      }
      
        printf("SUM = %d",sum);
      


}