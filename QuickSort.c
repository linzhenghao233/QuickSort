#include <stdio.h>
#include <stdlib.h>

void QuickSort(int*, int, int);
void ShowArr(int*, int);
int FindPos(int*, int, int);

int main(void) {
    int a[6] = { 2, 1, 0, 5, 4, 3 };
    ShowArr(a, 6);
    QuickSort(a, 0, 5);
    ShowArr(a, 6);

    exit(0);
}

int FindPos(int* arr, int left, int right) {
    int temp = arr[left];

    while (left < right) {
        while (left < right && arr[right] > temp)
            right--;
        arr[left] = arr[right];
        while (left < right && arr[left] < temp)
            left++;
        arr[right] = arr[left];
    }
    arr[right] = temp;

    return right;
}

void QuickSort(int* arr, int left, int right) {
    int pos;

    if (left < right) {
        pos = FindPos(arr, left, right);
        QuickSort(arr, left, pos - 1);
        QuickSort(arr, pos + 1, right);
    }
}

void ShowArr(int* arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
