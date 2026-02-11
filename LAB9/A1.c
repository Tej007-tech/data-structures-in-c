// WAP to allocate and de-allocate memory for int, char and float variable at 
// runtime. 


#include<stdio.h>
#include<stdlib.h>
void main()
{
    
    int *ptri =  (int *)malloc(sizeof(int));
    float *ptrf = (float *)malloc(sizeof(float));
    char *ptrc =  (char *)malloc(sizeof(char));
   
    if((ptri) && (ptrf) && (ptrc))
    {
        int a = 4;
        float b = 20.3;
        char c = 'A';

        ptri = &a;
        ptrf = &b;
        ptrc = &c;

        printf("%d\n",*ptri);
        printf("%f\n",*ptrf);
        printf("%c\n",*ptrc);

        free(ptri);
        free(ptrf);
        free(ptrc);
    }
    else
    {
       printf(" memory allocation filed. ");
    }
}