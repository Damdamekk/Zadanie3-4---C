#include <stdio.h>

// Funkcja rekurencyjnego wyszukiwania binarnego
int binarySearchRecursive(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Jeśli znaleziono element w środku tablicy, zwróć indeks
        if (arr[mid] == x) {
            return mid;
        }

        // Jeśli element jest mniejszy niż środkowy, szukaj w lewej połowie
        if (arr[mid] > x) {
            return binarySearchRecursive(arr, left, mid - 1, x);
        }

        // W przeciwnym razie, szukaj w prawej połowie
        return binarySearchRecursive(arr, mid + 1, right, x);
    }

    // Element nie został znaleziony w tablicy
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearchRecursive(arr, 0, n - 1, x);
    if (result == -1) {
        printf("Element %d nie został znaleziony w tablicy.\n", x);
    } else {
        printf("Element %d został znaleziony pod indeksem %d.\n", x, result);
    }
    return 0;
}
