#include<stdio.h>
void main(){
    int m,n,sum = 0,size;
     
    printf("Enter starting point: ");
    scanf("%d",&m);

    printf("Enter ending point: ");
    scanf("%d",&n);
    for(int i=m;i<=n;i++){
        scanf("%d",&m);
    }
    
    for(int i=m;i<=n;i++){
        sum += m;
    }
    printf("%d",sum);


    

}