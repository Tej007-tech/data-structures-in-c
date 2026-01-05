//  Write a program to insert a number at a given location in an array.

#include <stdio.h>
int main() {
    int arr[10], size, i, num, a;

    
    printf("Enter size of array: ");
    scanf("%d", &size);

    
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter number to insert: ");
    scanf("%d", &num);

    printf("Enter indext ");
    scanf("%d", &a);

    

   
    for(i = size; i > a; i--) {
        arr[i] = arr[i - 1];
    }

    
    arr[a] = num;
    size++; 

    
    printf(" New Array: \n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
