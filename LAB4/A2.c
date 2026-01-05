// Write a program to delete a number from a given location in an array.

#include <stdio.h>

int main() {
    int arr[10], size, i, num, a;

   
    printf("Enter size of array: ");
    scanf("%d", &size);

    
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    

    printf("Enter indext ");
    scanf("%d", &a);

    for(i = a; i < size-1; i++) {
        arr[i] = arr[i + 1];
    }

    
    
    size--;

     printf(" New Array: \n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

}