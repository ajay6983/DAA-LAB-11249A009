#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) { int t=*a; *a=*b; *b=t; }

int partition(int arr[], int low, int high) {
    int r = low + rand() % (high - low);   // random pivot
    swap(&arr[r], &arr[high]);
    int pivot = arr[high], i = low;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot) swap(&arr[i++], &arr[j]);
    swap(&arr[i], &arr[high]);
    return i;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    srand(time(NULL));
    int arr[] = {6, 4, 12, 8, 15, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}
