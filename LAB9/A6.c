//54  WAP to check whether the string is Palindrome or not using Pointer/



#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void main()
{
    int n;
    printf("Enter The size of the array:");
    scanf("%d", &n);

    char*ptr = (char *)malloc((n+1) * sizeof(char));

    printf("Enter string :");

    scanf("%s",ptr);
 
char *start=ptr;
char *end=ptr+(strlen(ptr))-1;
int flag=1;   

while(start<end){

    if(*start!=*end){
        flag=0;
        break;
    }
    start++;
    end--;
}
    
if(flag==1){
    printf("\n palindrome");
}

else{
    printf("\n not a  palindrome");
}

    
}