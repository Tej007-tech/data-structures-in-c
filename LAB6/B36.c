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

void check(char str[]) {
    int len = strlen(str);
    char ch;
    int count = 0;  

    for (int i = 0; i < len; i++) {
        ch = str[i];
        if (ch == 'a') {
            push(ch);
        } 
        else if (ch == 'b') {
            count++;
        }
    }

    
    if (top + 1 == count) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
}

int main() {  
    check("aaabbb");
    return 0;
}
