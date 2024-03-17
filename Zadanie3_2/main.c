#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja do alokacji pamięci dla macierzy dwuwymiarowej
int** alokujMacierz(int wiersze, int kolumny) {
    int** macierz = (int**)malloc(wiersze * sizeof(int*));
    if (macierz == NULL) {
        printf("Błąd alokacji pamięci dla wierszy.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < wiersze; i++) {
        macierz[i] = (int*)malloc(kolumny * sizeof(int));
        if (macierz[i] == NULL) {
            printf("Błąd alokacji pamięci dla kolumn.\n");
            exit(EXIT_FAILURE);
        }
    }

    return macierz;
}

// Funkcja do generowania losowych liczb w macierzy
void wypelnijMacierzLosowymi(int** macierz, int wiersze, int kolumny) {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = rand() % 100; // Losowa liczba z zakresu 0-99
        }
    }
}

// Funkcja do wyświetlania zawartości macierzy
void wyswietlMacierz(int** macierz, int wiersze, int kolumny) {
    printf("Zawartość macierzy:\n");
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }
}

// Funkcja do zwalniania zaalokowanej pamięci dla macierzy
void zwolnijMacierz(int** macierz, int wiersze) {
    for (int i = 0; i < wiersze; i++) {
        free(macierz[i]);
    }
    free(macierz);
}

int main() {
    int wiersze, kolumny;

    // Wczytywanie rozmiarów macierzy od użytkownika
    printf("Podaj liczbe wierszy macierzy: ");
    scanf("%d", &wiersze);
    printf("Podaj liczbe kolumn macierzy: ");
    scanf("%d", &kolumny);

    // Inicjalizacja generatora liczb pseudolosowych
    srand(time(NULL));

    // Alokacja pamięci dla macierzy
    int** macierz = alokujMacierz(wiersze, kolumny);

    // Wypełnienie macierzy losowymi liczbami
    wypelnijMacierzLosowymi(macierz, wiersze, kolumny);

    // Wyświetlenie zawartości macierzy
    wyswietlMacierz(macierz, wiersze, kolumny);

    // Zwolnienie zaalokowanej pamięci
    zwolnijMacierz(macierz, wiersze);

    return 0;
}
