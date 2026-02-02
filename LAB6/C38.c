#include <stdio.h>
#include <string.h>

#define SIZE 100
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
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

// isEmpty
int isEmpty() {
    return top == -1;
}

// Peek 
char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

void display()
{
    int M = top;
    for(int i=0;i<=M;i++){
        printf("%c",stack[i]);
    }
}




     void removeStars(char str[]) {
         int len = strlen(str);
          for (int i = 0; i <len; i++) {
           char ch = str[i];
            
            if (ch == '*') {
                if (!isEmpty()) {
                    pop(); 
                }
            } else {
                push(ch); // Push 
            }
        }
        
       
         
    }


void main(){
//    removeStars("leet**cod*e");
//    display();

   removeStars("TejPatelDu**");
   display();

}