/*Write a program to sort the elements of an array in descending order using the Selection Sort algorithm.*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int sml = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[sml]) {
                sml = j;
            }
        }
        int temp = arr[sml];
        arr[sml] = arr[i];
        arr[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


