#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char data[20];
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

ASTNode* create_node(char* data, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    strcpy(node->data, data);
    node->left = left;
    node->right = right;
    return node;
}

void print_ast(ASTNode* node, int level) {
    if (node == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("|-- %s\n", node->data);

    print_ast(node->left, level + 1);
    print_ast(node->right, level + 1);
}

int main() {
    ASTNode* n3 = create_node("3", NULL, NULL);
    ASTNode* n4 = create_node("4", NULL, NULL);
    ASTNode* mul = create_node("*", n3, n4);

    ASTNode* n5 = create_node("5", NULL, NULL);
    ASTNode* add = create_node("+", n5, mul);

    ASTNode* x = create_node("x", NULL, NULL);
    ASTNode* root = create_node("=", x, add);

    print_ast(root, 0);

    return 0;
}
