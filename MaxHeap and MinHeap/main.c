#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void diziyiYazdir(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%3d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

int main() {
    int maxHeapDizisi[BOYUT];
    int minHeapDizisi[BOYUT];

    srand(time(NULL));

    for (int i = 0; i < BOYUT; i++) {
        int r = rand() % 1000;
        maxHeapDizisi[i] = r;
        minHeapDizisi[i] = r;
    }

    buildMaxHeap(maxHeapDizisi, BOYUT);
    printf("MAX HEAP:\n");
    diziyiYazdir(maxHeapDizisi, BOYUT);

    printf("\n----------------------------------\n\n");

    buildMinHeap(minHeapDizisi, BOYUT);
    printf("MIN HEAP:\n");
    diziyiYazdir(minHeapDizisi, BOYUT);

    return 0;
}
