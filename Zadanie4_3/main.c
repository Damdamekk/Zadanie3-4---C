#include <stdio.h>

// Funkcja zamieniająca dwa elementy w tablicy miejscami
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funkcja generująca wszystkie permutacje ciągu
void permute(int *array, int start, int end) {
    // Warunek końcowy rekurencji (gdy start i end są równe)
    if (start == end) {
        // Wyświetlenie permutacji
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        return;
    }

    // Rekurencyjne generowanie permutacji
    for (int i = start; i <= end; i++) {
        // Zamiana elementów miejscami
        swap(&array[start], &array[i]);
        // Wywołanie rekurencyjne dla pozostałych elementów
        permute(array, start + 1, end);
        // Przywrócenie pierwotnego porządku elementów
        swap(&array[start], &array[i]);
    }
}

int main() {
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Wszystkie permutacje ciagu:\n");
    permute(array, 0, n - 1);

    return 0;
}
