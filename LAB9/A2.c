// WAP to get and print the array elements using Pointer. 

#include<stdio.h>
void main()
{
      int size,i;

    printf("Enter Size: ");
    scanf("%d",&size);


      int A[size];
      int *ptr = &A[0];
      for(int i=0;i<size;i++)
      {
            scanf("%d",ptr + i);
      }
      for(int i=0;i<size;i++)
      {
            printf("%d ",*(ptr + i));
      }


}