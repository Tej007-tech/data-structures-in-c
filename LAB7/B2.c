#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int stack[100];
int top = -1;

void push(int c) {
    stack[++top] = c;
}

int pop() {
    return stack[top--];
}

void reverse(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void evaluate_prefix(char prefix[]) {
    for(int i = 0; i < strlen(prefix); i++) {
        if (isdigit(prefix[i])) {
            push(prefix[i] - '0');
        } else {
            int operand1 = pop();  // right
            int operand2 = pop();  // left
            switch(prefix[i]) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
                case '^': push(pow(operand1, operand2)); break;
            }
        }
    }
}

int main() {
    char prefix[100];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    reverse(prefix);  // replace strrev with manual reverse
    evaluate_prefix(prefix);

    printf("Answer: %d\n", pop());
    return 0;
}
