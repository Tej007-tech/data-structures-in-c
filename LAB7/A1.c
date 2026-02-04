#include <stdio.h>
#include <string.h>


#define SIZE 1000

// Stack
char stack[SIZE];
int top = -1;

// Push 
void push(char ch) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

// Pop 
char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int SPF(char c){
        if(c == '+' || c == '-') return 2;
        else if(c == '/' || c == '*') return 4;
        else if(c == '^') return 5;
        else if(c == '(') return 0;
        else return 8;
}

int IPF(char c){
      if(c == '+' || c == '-') return 1;
        else if(c == '/' || c == '*') return 3;
        else if(c == '^') return 6;
        else if(c == '(') return 9;
        else if(c == ')') return 0;
        else return 7;
}
 int RF(char c){
   if(c == '+' || c == '-' || c == '*' || c == '/' || c =='^') return -1;    
    else  return 1;
 }

 void REVPOL(char infix[]){
        int i=0;
        char postfix[100];
        int j=0;
        int r=0;
        push('(');
        while(i != strlen(infix)){
            char next = infix[i];
            if(top<0){
                printf("Invalid: ");
                return;
            }
            while(SPF(stack[top])>IPF(next)){
                char temp =pop();
                postfix[j++] = temp;
                r += RF(temp);

                if(r < 1){
                    printf("INVALID: ");
                    return;
                }
            }
            if(SPF(stack[top]) != IPF(next)){
                push(next);
            }
            else{
               char temp = pop();
            }
            i++;
        }
        postfix[j] = '\0';
        if(top != -1 || r != 1){
           printf("\nINVALID: ");
           return;
        }
        else{
            printf("%s",postfix);
        }

 }
void main() {
         char infix[100];
    printf("Enter the infix expression: ");
   scanf("%s",infix);
   strcat(infix,")");
//    printf("Postfix expression is: %s ",infix);
   REVPOL(infix);
 
}
