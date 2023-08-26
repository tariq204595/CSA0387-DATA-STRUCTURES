#include <stdio.h>
int mostFrequent(int arr[], int len) {
  int maxCount = 0, element = arr[0];
  int i, j;
  for (i = 0; i < len; i++) {
    int count = 1;
    for (j = i + 1; j < len; j++) {
      if (arr[j] == arr[i]) {
        count++;
      }
    }
    if (count > maxCount) {
      maxCount = count;
      element = arr[i];
    }
  }

  return element;
}

int main() {
  int arr[] = {1, 2, 3, 2, 1, 4, 2, 5};
  int len = sizeof(arr) / sizeof(arr[0]);
  int mostFrequentElement = mostFrequent(arr, len);
  printf("The most frequently repeated element is %d\n", mostFrequentElement);

  return 0;
}

