// Design anagram game using array.  
// • Allow a user to enter N words and store it in an array.  
// • Generate a random number between 0 to N-1.  
// • Based on the random number generated display the word stored at that 
// index of an array and allow user to enter its anagram.  
// • Check whether the word entered by the user is an anagram of displayed 
// number or not and display an appropriate message.  
// • Given a word A and word B. B is said to be an anagram of A if and only if 
// the characters present in B is same as characters present in A, 
// irrespective of their sequence. For ex: “LISTEN” == “SILENT”



#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
void main(){
    int N,i,j,k;
    printf("Enter N words: ");
    scanf("%d",&N);
    char words[N][100];
    for(int i=0;i<N;i++){
        
        scanf("%s",&words[i]);
       
    }
    for(int i=0;i<N;i++){
       
        printf("%s ",words[i]);
        
    }
    printf("\n");
    srand(time(0));
    int A = rand() % N;
    printf("%d",A);

     printf("\n");

    char new_word[100];
    printf("Enter new word: \n");
    
    scanf("%s",&new_word);
    
    
    printf("%s",new_word);
    
    for(i=0;i<N;i++){
        if(new_word == words[A][100]){
            printf("hello");
        }
    }
    
}