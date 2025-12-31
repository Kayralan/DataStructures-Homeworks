#include <stdio.h>

#define MAX_SIZE 15

char tree[MAX_SIZE];

void init_tree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = '\0';
    }
}

void set_root(char key) {
    if (tree[0] != '\0') {
        printf("Hata: Kok zaten mevcut.\n");
    } else {
        tree[0] = key;
    }
}

void set_left(char key, int parent_index) {
    int child_index = (parent_index * 2) + 1;

    if (tree[parent_index] == '\0') {
        printf("Hata: Ebeveyn bulunamadi.\n");
    } else if (child_index >= MAX_SIZE) {
        printf("Hata: Dizi siniri asildi.\n");
    } else {
        tree[child_index] = key;
    }
}

void set_right(char key, int parent_index) {
    int child_index = (parent_index * 2) + 2;

    if (tree[parent_index] == '\0') {
        printf("Hata: Ebeveyn bulunamadi.\n");
    } else if (child_index >= MAX_SIZE) {
        printf("Hata: Dizi siniri asildi.\n");
    } else {
        tree[child_index] = key;
    }
}

void print_tree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] != '\0')
            printf("Index %d: %c\n", i, tree[i]);
        else
            printf("Index %d: -\n", i);
    }
}

int main() {
    init_tree();

    set_root('A');
    set_left('B', 0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);

    print_tree();

    return 0;
}
