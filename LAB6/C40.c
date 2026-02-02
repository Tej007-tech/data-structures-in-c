#include <stdio.h>
#include <string.h>
#include <ctype.h>

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


int isVowel(char ch) {
    ch = tolower(ch); 
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}


void processString(int n, char s[]) {
    
    top = -1;

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        if (isVowel(ch)) {
            
            char temp[SIZE];
            int tempTop = -1;

            while (top != -1) {
                temp[++tempTop] = pop();
            }

            
            for (int j = 0; j <= tempTop; j++) {
                push(temp[j]);
            }
        }

        
        push(ch);
    }

    
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}


int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        char s[SIZE];
        scanf("%d", &n);
        scanf("%s", s);

        processString(n, s);
    }

    return 0;
}
