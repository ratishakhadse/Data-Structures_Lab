/*Write a menu-driven C program to perform operations on a Doubly Linked List.
The program should support insertion, deletion, display, reversal, concatenation of another list, and exit operations.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
int main() {
    struct Node* head = NULL;
    struct Node* temp;
    int choice, num;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &num);
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = num;
            newNode->next = NULL;
            newNode->prev = NULL;
            if (head == NULL) {
                head = newNode;
            } else {
                temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
            printf("Inserted\n");
        }
        else if (choice == 2) {
            scanf("%d", &num);

            if (head == NULL) {
                printf("List empty\n");
            } else {
                temp = head;

                while (temp != NULL && temp->data != num) {
                    temp = temp->next;
                }
                if (temp == NULL) {
                    printf("Not found\n");
                } else {
                    if (temp == head) {
                        head = temp->next;
                        if (head != NULL)
                            head->prev = NULL;
                    } else {
                        if (temp->prev != NULL)
                            temp->prev->next = temp->next;
                        if (temp->next != NULL)
                            temp->next->prev = temp->prev;
                    }
                    free(temp);
                    printf("Deleted\n");
                }
            }
        }
        else if (choice == 3) {
            if (head == NULL) {
                printf("List empty\n");
            } else {
                temp = head;
                while (temp != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
