#include <stdio.h>
#include <string.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

// push
void push(char ch) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

// pop 
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}


void recognize(char str[]) {
    int len = strlen(str);
    
    
    int i;
    for (i = 0; i < len / 2; i++) {
        push(str[i]);
    }

    
    if (len % 2 != 0) {
        i++;
    }

    
    while (i < len) {
        char ch = pop();
        if (ch != str[i]) {
            printf("Invalid: \n");
            return;
        }
        i++;
    }

    printf("Valid:\n");
}

int main() {
    recognize("aabcb");   // Valid
    //recognize("abcba");   // Invalid
    return 0;
}
