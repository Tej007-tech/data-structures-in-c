#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Stack 
Interval stack[100];
int top = -1;

// Push 
void push(Interval i) {
    stack[++top] = i;
}

// Pop 
Interval pop() {
    return stack[top--];
}


Interval peek() {
    return stack[top];
}


int compare(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->start - i2->start;
}


void mergeIntervals(Interval* intervals, int n) {
   
    qsort(intervals, n, sizeof(Interval), compare);

    
    push(intervals[0]);

   
    for (int i = 1; i < n; i++) {
        Interval topInterval = peek();
        
      
        if (intervals[i].start <= topInterval.end) {
            if (intervals[i].end > topInterval.end) {
                topInterval.end = intervals[i].end;
            }
            pop(); 
            push(topInterval); 
        } else {
            push(intervals[i]); 
        }
    }

    
    for (int i = 0; i <= top; i++) {
        printf("{%d, %d} ", stack[i].start, stack[i].end);
    }
}

void main() {
    Interval intervals1[] = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    int n1 = sizeof(intervals1) / sizeof(intervals1[0]);

    
    mergeIntervals(intervals1, n1);
    printf("\n");

    
    // top = -1;
    // Interval intervals2[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    // int n2 = sizeof(intervals2) / sizeof(intervals2[0]);

    
    // mergeIntervals(intervals2, n2);
    printf("\n");

   
}
