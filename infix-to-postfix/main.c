#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KAPASITE 100

struct Yigin {
    char elemanlar[KAPASITE];
    int tepe;
};

void baslat(struct Yigin *y) {
    y->tepe = -1;
}

int bosmu(struct Yigin *y) {
    return y->tepe == -1;
}

int dolumu(struct Yigin *y) {
    return y->tepe == KAPASITE - 1;
}

void ekle(struct Yigin *y, char karakter) {
    if (dolumu(y)) {
        printf("Yigin dolu!");
        return;
    }
    y->elemanlar[++(y->tepe)] = karakter;
}

char cikar(struct Yigin *y) {
    if (bosmu(y)) {
        printf("Yigin bos!");
        return '\0';
    }
    return y->elemanlar[(y->tepe)--];
}

char gozat(struct Yigin *y) {
    if (bosmu(y)) {
        return '\0';
    }
    return y->elemanlar[y->tepe];
}

int ilk(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

void donustur(char *infix, char *postfix) {
    struct Yigin yigin;
    baslat(&yigin);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char karakter = infix[i];

        if (karakter == ' ') {
            continue;
        }

        if (isalpha(karakter) || isdigit(karakter)) {
            postfix[j++] = karakter;
        }
        else if (karakter == '(') {
            ekle(&yigin, karakter);
        }
        else if (karakter == ')') {
            while (!bosmu(&yigin) && gozat(&yigin) != '(') {
                postfix[j++] = cikar(&yigin);
            }
            cikar(&yigin);
        }
        else {
            while (!bosmu(&yigin) && ilk(gozat(&yigin)) >= ilk(karakter)) {
                postfix[j++] = cikar(&yigin);
            }
            ekle(&yigin, karakter);
        }
    }

    while (!bosmu(&yigin)) {
        postfix[j++] = cikar(&yigin);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[KAPASITE];
    char postfix[KAPASITE];

    printf("Infix ifadeyi giriniz:\n");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    donustur(infix, postfix);

    printf("\nPostfix degeri: %s\n", postfix);

    return 0;
}
