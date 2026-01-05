// Write a program to insert a number in an array that is already sorted in an 
// ascending order. 

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
   
    for(i = 0; i <size; i--) {
        arr[i] > arr[i - 1];
    }

    
    arr[size] = num;
    size++; 

    
    
//    int max = arr[0];
//    for(i=0;i<size;i++){
//        if(arr[i]>max){
//          max = arr[i];
//        }
//    }

   printf(" New Array: \n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
