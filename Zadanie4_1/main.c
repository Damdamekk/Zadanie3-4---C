#include <stdio.h>

// Funkcja obliczająca silnię liczby
int factorial(int n) {
    // Warunek kończący rekurencję
    if (n == 0) {
        return 1; // 0! = 1
    } else {
        return n * factorial(n - 1); // Wywołanie rekurencyjne
    }
}

int main() {
    int liczba;


    printf("Podaj liczbe: ");
    scanf("%d", &liczba);


    printf("%d! = %d\n", liczba, factorial(liczba));

    return 0;
}