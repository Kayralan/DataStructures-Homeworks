#include <stdlib.h>
#include <stdio.h>

void boslukBirak(int n) {
    for (int i = 0; i < n; i++) {
        printf("  ");
    }
}

void hanoiCallTree(int n, char kaynak_cubuk, char hedef_cubuk, char yardimci_cubuk, int derinlik) {

    boslukBirak(derinlik);
    printf("Hanoi(%d, '%c', '%c', '%c') cagrisi basladi.\n", n, kaynak_cubuk, hedef_cubuk, yardimci_cubuk);

    if (n == 1) {
        boslukBirak(derinlik + 1);
        printf("Disk 1'i %c'den %c'e tasi.\n", kaynak_cubuk, hedef_cubuk);
        boslukBirak(derinlik);
        printf("Hanoi(%d, '%c', '%c', '%c') cagrisi bitti.\n", n, kaynak_cubuk, hedef_cubuk, yardimci_cubuk);
        return;
    }

    hanoiCallTree(n - 1, kaynak_cubuk, yardimci_cubuk, hedef_cubuk, derinlik + 1);

    boslukBirak(derinlik + 1);
    printf("Disk %d'i %c'den %c'e tasi.\n", n, kaynak_cubuk, hedef_cubuk);

    hanoiCallTree(n - 1, yardimci_cubuk, hedef_cubuk, kaynak_cubuk, derinlik + 1);

    boslukBirak(derinlik);
    printf("Hanoi(%d, '%c', '%c', '%c') cagrisi bitti.\n", n, kaynak_cubuk, hedef_cubuk, yardimci_cubuk);
}

int main() {
    int disk_sayisi;

    printf("Hanoi Kuleleri icin disk sayisini giriniz: ");
    scanf("%d", &disk_sayisi);

    if (disk_sayisi < 1) {
        printf("Disk sayisi en az 1 olmalidir.\n");
        return 1;
    }

    printf("\nHanoi Kuleleri Cagri Agaci\n");
    hanoiCallTree(disk_sayisi, 'A', 'C', 'B', 0);

    return 0;
}
