/*Write a C program to implement a binary search tree with the following functionalities:

 1. Insert(): Insert a node into the binary search tree (BST).
 2. Inorder(): Perform inorder traversal of the BST.
 3. Preorder(): Perform preorder traversal of the BST.
 4. Postorder(): Perform postorder traversal of the BST.
 5. Delete(): Delete a node from the BST.
 6. Exit(): Terminate the program.*/

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int main() {
    struct TreeNode* root = NULL;
    int choice, data;
    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Data: ");
            scanf("%d", &data);
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->val = data;
            newNode->left = NULL;
            newNode->right = NULL;
            if (root == NULL) {
                root = newNode;
            } else {
                struct TreeNode* curr = root;
                struct TreeNode* parent = NULL;

                while (curr != NULL) {
                    parent = curr;
                    if (data < curr->val)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }
                if (data < parent->val)
                    parent->left = newNode;
                else
                    parent->right = newNode;
            }
        }
        else if (choice == 2) {
            if (root == NULL) {
                printf("The tree is empty\n");
            } else {
                struct TreeNode* stack[100];
                int top = -1;
                struct TreeNode* curr = root;
                while (curr != NULL || top != -1) {
                    while (curr != NULL) {
                        stack[++top] = curr;
                        curr = curr->left;
                    }
                    curr = stack[top--];
                    printf("%d ", curr->val);
                    curr = curr->right;
                }
                printf("\n");
            }
        }
        else if (choice == 3) {
            if (root == NULL) {
                printf("The tree is empty\n");
            } else {
                struct TreeNode* stack[100];
                int top = -1;
                stack[++top] = root;
                while (top != -1) {
                    struct TreeNode* temp = stack[top--];
                    printf("%d ", temp->val);
                    if (temp->right)
                        stack[++top] = temp->right;
                    if (temp->left)
                        stack[++top] = temp->left;
                }
                printf("\n");
            }
        }
        else if (choice == 4) {
            if (root == NULL) {
                printf("The tree is empty\n");
            } else {
                struct TreeNode* stack1[100], *stack2[100];
                int top1 = -1, top2 = -1;
                stack1[++top1] = root;
                while (top1 != -1) {
                    struct TreeNode* temp = stack1[top1--];
                    stack2[++top2] = temp;
                    if (temp->left)
                        stack1[++top1] = temp->left;
                    if (temp->right)
                        stack1[++top1] = temp->right;
                }
                while (top2 != -1) {
                    printf("%d ", stack2[top2--]->val);
                }
                printf("\n");
            }
        }
        else if (choice == 5) {
            printf("Delete: ");
            scanf("%d", &data);
            struct TreeNode* curr = root;
            struct TreeNode* parent = NULL;
            while (curr != NULL && curr->val != data) {
                parent = curr;
                if (data < curr->val)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
            if (curr == NULL) {
                printf("Value not found\n");
            } else {
                if (curr->left == NULL || curr->right == NULL) {
                    struct TreeNode* newCurr;
                    if (curr->left == NULL)
                        newCurr = curr->right;
                    else
                        newCurr = curr->left;
                    if (parent == NULL)
                        root = newCurr;
                    else if (parent->left == curr)
                        parent->left = newCurr;
                    else
                        parent->right = newCurr;
                    free(curr);
                }
                else {
                    struct TreeNode* temp = curr->right;
                    struct TreeNode* tempParent = curr;

                    while (temp->left != NULL) {
                        tempParent = temp;
                        temp = temp->left;
                    }
                    curr->val = temp->val;
                    if (tempParent->left == temp)
                        tempParent->left = temp->right;
                    else
                        tempParent->right = temp->right;

                    free(temp);
                }
            }
        }
        else if (choice == 6) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
