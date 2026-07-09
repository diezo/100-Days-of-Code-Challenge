// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main() {
    int n;

    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);

    if (arr == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    int i = 0;
    int j = n - 1;

    int pair[] = {arr[0], arr[1]};
    int minSum = abs(arr[0] + arr[1]);

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (abs(sum) < minSum) {
            minSum = abs(sum);
            pair[0] = arr[i];
            pair[1] = arr[j];
        }

        if (sum < 0) i++;
        else j--;
    }

    printf("%d %d\n", pair[0], pair[1]);

    free(arr);

    return 0;
}

void mergeSort(int *arr, int left, int right) {
    if (left == right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void merge(int *arr, int left, int mid, int right) {
    int *temp = malloc(sizeof(int) * (right - left + 1));

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = 0; x < (right - left + 1); x++) {
        arr[left + x] = temp[x];
    }

    free(temp);
}