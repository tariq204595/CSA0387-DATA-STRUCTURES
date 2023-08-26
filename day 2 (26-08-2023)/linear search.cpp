#include <stdio.h>

int ls(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;  
}

int main() {
    int arr[] = {10, 25, 3, 42, 17, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 17;
    
    int index = ls(arr, size, target);
    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

