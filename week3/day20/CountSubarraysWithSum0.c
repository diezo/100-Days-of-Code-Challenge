// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3

// Output:
// 6

// Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main() {
    int n;

    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            int sum = arr[i] + arr[l] + arr[r];

            if (sum < 0) l++;
            else if (sum > 0) r--;
            else {
                count++;

                l++;
                r--;

                while (l < r && arr[l] == arr[l - 1]) l++;
                while (l < r && arr[r] == arr[r + 1]) r--;
            }
        }
    }

    printf("%d\n", count);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    puts("");

    free(arr);

    return 0;
}

void mergeSort(int *arr, int l, int r) {
    if (l == r) return;

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    return merge(arr, l, m, r);
}

void merge(int *arr, int l, int m, int r) {
    int *temp = malloc(sizeof(int) * (r - l + 1));

    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (int x = 0; x <= (r - l); x++) {
        arr[l + x] = temp[x];
    }

    free(temp);
}