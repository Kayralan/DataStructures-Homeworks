#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum *sonraki;
};

struct Dugum* dugumOlustur(int veri) {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    if (yeniDugum == NULL) {
        printf("Bellek hatasi!\n");
        exit(1);
    }
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

void listeyiTemizle(struct Dugum** baslangic) {
    struct Dugum* mevcut = *baslangic;
    struct Dugum* sonraki;
    while (mevcut != NULL) {
        sonraki = mevcut->sonraki;
        free(mevcut);
        mevcut = sonraki;
    }
    *baslangic = NULL;
}

void listeyiYazdir(struct Dugum* baslangic) {
    if (baslangic == NULL) {
        printf("Liste su anda bos.\n");
        return;
    }
    struct Dugum* gecici = baslangic;
    printf("Liste: ");
    while (gecici != NULL) {
        printf("%d -> ", gecici->veri);
        gecici = gecici->sonraki;
    }
    printf("NULL\n");
}

void sonaEkle(struct Dugum** baslangic, int veri) {
    struct Dugum* yeniDugum = dugumOlustur(veri);
    if (*baslangic == NULL) {
        *baslangic = yeniDugum;
        return;
    }
    struct Dugum* son = *baslangic;
    while (son->sonraki != NULL) {
        son = son->sonraki;
    }
    son->sonraki = yeniDugum;
}

void bastanSil(struct Dugum** baslangic) {
    if (*baslangic == NULL) {
        printf("Liste zaten bos, silinecek eleman yok.\n");
        return;
    }
    struct Dugum* silinecek = *baslangic;
    *baslangic = (*baslangic)->sonraki;
    printf("%d degeri bastan silindi.\n", silinecek->veri);
    free(silinecek);
}

void sondanSil(struct Dugum** baslangic) {
    if (*baslangic == NULL) {
        printf("Liste zaten bos, silinecek eleman yok.\n");
        return;
    }
    if ((*baslangic)->sonraki == NULL) {
        printf("%d degeri sondan silindi.\n", (*baslangic)->veri);
        free(*baslangic);
        *baslangic = NULL;
        return;
    }
    struct Dugum* onceki = NULL;
    struct Dugum* gecici = *baslangic;
    while (gecici->sonraki != NULL) {
        onceki = gecici;
        gecici = gecici->sonraki;
    }
    onceki->sonraki = NULL;
    printf("%d degeri sondan silindi.\n", gecici->veri);
    free(gecici);
}

void ortadanSil(struct Dugum** baslangic, int pozisyon) {
    if (*baslangic == NULL) {
        printf("Liste bos.\n");
        return;
    }
    struct Dugum* gecici = *baslangic;
    if (pozisyon == 1) {
        bastanSil(baslangic);
        return;
    }
    for (int i = 1; gecici != NULL && i < pozisyon - 1; i++) {
        gecici = gecici->sonraki;
    }
    if (gecici == NULL || gecici->sonraki == NULL) {
        printf("Gecersiz pozisyon!\n");
        return;
    }
    struct Dugum* silinecek = gecici->sonraki;
    gecici->sonraki = silinecek->sonraki;
    printf("%d pozisyonundaki %d degeri silindi.\n", pozisyon, silinecek->veri);
    free(silinecek);
}

void basaEkle(struct Dugum** baslangic, int veri) {
    struct Dugum* yeniDugum = dugumOlustur(veri);
    yeniDugum->sonraki = *baslangic;
    *baslangic = yeniDugum;
}

void menuyuGoster() {

    printf("1. Yeni Liste Olustur\n");
    printf("2. Basa Eleman Ekle\n");
    printf("3. Sona Eleman Ekle\n");
    printf("4. Bastan Eleman Sil\n");
    printf("5. Sondan Eleman Sil\n");
    printf("6. Ortadan Eleman Sil\n");
    printf("7. Listeyi Goster\n");
    printf("0. Cikis\n");
    printf("Seciminiz: ");
}

int main() {
    struct Dugum* bas = NULL;
    int secim, veri, adet, pozisyon;

    do {
        menuyuGoster();
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                listeyiTemizle(&bas);
                printf("Listeye kac eleman eklemek istersiniz? ");
                scanf("%d", &adet);
                for (int i = 0; i < adet; i++) {
                    printf("%d. elemani girin: ", i + 1);
                    scanf("%d", &veri);
                    sonaEkle(&bas, veri);
                }
                printf("Yeni liste olusturuldu.\n");
                listeyiYazdir(bas);
                break;
            case 2:
                printf("Basa eklenecek veriyi girin: ");
                scanf("%d", &veri);
                basaEkle(&bas, veri);
                listeyiYazdir(bas);
                break;
            case 3:
                printf("Sona eklenecek veriyi girin: ");
                scanf("%d", &veri);
                sonaEkle(&bas, veri);
                listeyiYazdir(bas);
                break;
            case 4:
                bastanSil(&bas);
                listeyiYazdir(bas);
                break;
            case 5:
                sondanSil(&bas);
                listeyiYazdir(bas);
                break;
            case 6:
                printf("Kacinci pozisyondaki elemani silmek istersiniz? ");
                scanf("%d", &pozisyon);
                ortadanSil(&bas, pozisyon);
                listeyiYazdir(bas);
                break;
            case 7:
                listeyiYazdir(bas);
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
                break;
        }

    } while (secim != 0);

    listeyiTemizle(&bas);

    return 0;
}
