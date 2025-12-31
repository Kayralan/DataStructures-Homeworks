#include <stdio.h>
#include <stdlib.h>

void yazdir(int* dizi, int boyut) {
    printf("[");
    for (int i = 0; i < boyut; i++) {
        printf("%d", dizi[i]);
        if (i < boyut - 1) printf(", ");
    }
    printf("]\n");
}

void tersineCevir(int* dizi, int boyut) {
    int bas = 0;
    int son = boyut - 1;
    while (bas < son) {
        int temp = dizi[bas];
        dizi[bas] = dizi[son];
        dizi[son] = temp;
        bas++;
        son--;
    }
}

int* elemanEkle(int* eskiDizi, int boyut, int yeniEleman) {
    int* yeniDizi = (int*)malloc((boyut + 1) * sizeof(int));
    for (int i = 0; i < boyut; i++) {
        yeniDizi[i] = eskiDizi[i];
    }
    yeniDizi[boyut] = yeniEleman;
    return yeniDizi;
}

int* elemanCikar(int* eskiDizi, int boyut, int silinecekIndex) {
    if (silinecekIndex < 0 || silinecekIndex >= boyut) return NULL;

    int* yeniDizi = (int*)malloc((boyut - 1) * sizeof(int));
    int j = 0;

    for (int i = 0; i < boyut; i++) {
        if (i == silinecekIndex) continue;
        yeniDizi[j++] = eskiDizi[i];
    }
    return yeniDizi;
}

int main() {
    int dizi1[] = {1, 2, 3, 4, 5};
    int boyut1 = 5;

    printf("Orijinal Dizi 1: ");
    yazdir(dizi1, boyut1);

    tersineCevir(dizi1, boyut1);
    printf("Ters Cevrilmis : ");
    yazdir(dizi1, boyut1);

    printf("-------------------------\n");

    int dizi2[] = {10, 20, 30};
    int boyut2 = 3;

    printf("Orijinal Dizi 2: ");
    yazdir(dizi2, boyut2);

    int* eklenmisDizi = elemanEkle(dizi2, boyut2, 40);
    int yeniBoyut = boyut2 + 1;

    printf("40 Eklendikten Sonra: ");
    yazdir(eklenmisDizi, yeniBoyut);}
