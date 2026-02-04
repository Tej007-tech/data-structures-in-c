// #include <stdio.h>

// #define SIZE 1000

// int S[SIZE];
// int top = -1;

// void push(int val) {
//     if (top >= SIZE - 1) {
//         printf("Stack Overflow\n");
//         return;
//     }
//     S[++top] = val;
// }

// int pop() {
//     if (top == -1) {
//         return -1;
//     }
//     return S[top--];
// }

// void Sorted(int A[], int A_size) {
//     int B[A_size];
//      push(A[0]);
//     for (int i = 0; i < A_size; i++) {
        
//         if (S[top] < A[i + 1]) {
//              push(A[i+1]);
//             B[i] = pop();
//         } else {
//             push(A[i + 1]);
//         }
//     }

//     for (int i = 0; i < A_size; i++) {
//         printf("%d ", B[i]);
//     }
// }

// int main() {
//     int A_size = 4;
//     int A[A_size];

//     for (int i = 0; i < A_size; i++) {
//         scanf("%d", &A[i]);
//     }

//     Sorted(A, A_size);
//     return 0;
// }


#include <stdio.h>

#define MAX 1000

int T, N;
int A[MAX], S[MAX];
int top;

int isPossible(int A[], int N) {
    top = -1;  // Reset stack
    int expected = 1;
    int index = 0;

    while (index < N || top >= 0) {
        if (top >= 0 && S[top] == expected) {
            // Pop from stack to B
            top--;
            expected++;
        } else if (index < N) {
            // Push from A to stack
            S[++top] = A[index++];
        } else {
            // Can't move expected value
            return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        if (isPossible(A, N))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

