#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LIMIT 100

struct treeNode {
    int val;
    struct treeNode *lc, *rc;
};

struct treeNode* makeNode(int v) {
    struct treeNode *n = (struct treeNode*)malloc(sizeof(struct treeNode));
    n->val = v;
    n->lc = n->rc = NULL;
    return n;
}

struct treeNode* addNode(struct treeNode *root, int v) {
    if (root == NULL)
        return makeNode(v);
    if (v < root->val)
        root->lc = addNode(root->lc, v);
    else if (v > root->val)
        root->rc = addNode(root->rc, v);
    return root;
}

struct treeNode* getMin(struct treeNode *node) {
    while (node && node->lc)
        node = node->lc;
    return node;
}

struct treeNode* removeNode(struct treeNode *root, int v) {
    if (!root) return NULL;

    if (v < root->val) {
        root->lc = removeNode(root->lc, v);
    } else if (v > root->val) {
        root->rc = removeNode(root->rc, v);
    } else {
        if (!root->lc && !root->rc) {
            free(root);
            return NULL;
        }
        if (!root->lc) {
            struct treeNode *tmp = root->rc;
            free(root);
            return tmp;
        }
        if (!root->rc) {
            struct treeNode *tmp = root->lc;
            free(root);
            return tmp;
        }
        struct treeNode *succ = getMin(root->rc);
        root->val = succ->val;
        root->rc = removeNode(root->rc, succ->val);
    }
    return root;
}

bool findNode(struct treeNode *root, int v) {
    while (root != NULL) {
        if (root->val == v)
            return true;
        else if (v < root->val)
            root = root->lc;
        else
            root = root->rc;
    }
    return false;
}

void inorder(struct treeNode *root) {
    if (!root) return;
    inorder(root->lc);
    printf("%d ", root->val);
    inorder(root->rc);
}

int countNodes(struct treeNode *root) {
    if (!root) return 0;
    return 1 + countNodes(root->lc) + countNodes(root->rc);
}

void freeTree(struct treeNode *root) {
    if (!root) return;
    freeTree(root->lc);
    freeTree(root->rc);
    free(root);
}

int main() {
    int t;
    scanf("%d", &t);

    struct treeNode *root = NULL;
    char res[LIMIT][50];
    int ri = 0;

    for (int i = 0; i < t; i++) {
        int op, key;
        scanf("%d", &op);
        if (op >= 1 && op <= 3)
            scanf("%d", &key);

        if (op == 1) {
            root = addNode(root, key);
        } else if (op == 2) {
            if (findNode(root, key))
                root = removeNode(root, key);
        } else if (op == 3) {
            if (findNode(root, key))
                strcpy(res[ri++], "found");
            else
                strcpy(res[ri++], "not found");
        }
    }

    for (int i = 0; i < ri; i++)
        printf("%s\n", res[i]);

    printf("\nTree has %d node(s)\n", countNodes(root));
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
