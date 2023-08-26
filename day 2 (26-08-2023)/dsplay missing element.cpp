#include <stdio.h>

int findMissingElement(int arr[], int size) {
    int total = (size + 1) * (size + 2) / 2; 
    for (int i = 0; i < size; i++) {
        total -= arr[i]; 
    }
    return total;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements (consecutive integers with one element missing):\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int missingElement = findMissingElement(arr, size);
    printf("The missing element is: %d\n", missingElement);

    return 0;
}

