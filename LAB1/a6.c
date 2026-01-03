#include<stdio.h>

int main(){

int seconds;

printf("Enter Time in Seconds:");
scanf("%d",&seconds);

int hour =seconds/3600;
seconds=seconds%3600;

int minute=seconds/60;
seconds=seconds%60;

if(minute>=60){
    hour++;
}
   
printf("%d hours: %d Minutes: %d Seconds",hour,minute,seconds);
    return 0;
}