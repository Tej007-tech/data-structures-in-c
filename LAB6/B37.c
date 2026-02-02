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

// Peek / Top element
char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

// Validation function
void valid(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                printf("Invalid\n");
                return;
            }

            char topChar = peek();
            if ((topChar == '(' && ch == ')') ||
                (topChar == '{' && ch == '}') ||
                (topChar == '[' && ch == ']')) {
                pop();
            } else {
                printf("Invalid\n");
                return;
            }
        }
    }

    if (isEmpty()) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
}

void main() {
    valid("{{6}}");
}
