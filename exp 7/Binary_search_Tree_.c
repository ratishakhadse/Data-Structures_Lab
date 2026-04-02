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
    if (!root) return false;
    if (root->val == v) return true;
    if (v < root->val) return findNode(root->lc, v);
    return findNode(root->rc, v);
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

    return 0;
}
