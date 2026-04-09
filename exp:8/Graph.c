/*Write a C program to represent a Directed Graph using an adjacency list.*/

#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *next;
    int vertex;
};
typedef struct node *GNODE;
GNODE graph[20];
int main() {
    int N = 0, choice;
    while (1) {
        printf("1. Insert Vertex\n");
        printf("2. Insert Edge\n");
        printf("3. Delete Edge\n");
        printf("4. Delete Vertex\n");
        printf("5. Print Graph\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int edges, v;
            N++;
            graph[N] = NULL;
            scanf("%d", &edges);
            for (int i = 0; i < edges; i++) {
                scanf("%d", &v);
                if (v < 1 || v > N) continue;
                GNODE newnode = (GNODE)malloc(sizeof(struct node));
                newnode->vertex = N;
                newnode->next = NULL;
                if (graph[v] == NULL) {
                    graph[v] = newnode;
                } else {
                    GNODE temp = graph[v];
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newnode;
                }
            }
            scanf("%d", &edges);
            for (int i = 0; i < edges; i++) {
                scanf("%d", &v);

                if (v < 1 || v > N) continue;
                GNODE newnode = (GNODE)malloc(sizeof(struct node));
                newnode->vertex = v;
                newnode->next = NULL;
                if (graph[N] == NULL) {
                    graph[N] = newnode;
                } else {
                    GNODE temp = graph[N];
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newnode;
                }
            }
            printf("After inserting vertex the adjacency list is : \n");
            for (int i = 1; i <= N; i++) {
                if (graph[i] != NULL) {
                    printf("%d=>", i);
                    GNODE p = graph[i];
                    while (p != NULL) {
                        printf("%d\t", p->vertex);
                        p = p->next;
                    }
                    printf("\n");
                }
            }
        }
        else if (choice == 2) {
            int src, dest;
            printf("Enter the source vertex of the edge : ");
            scanf("%d", &src);
            printf("Enter the destination vertex of the edge : ");
            scanf("%d", &dest);
            if (src < 1 || src > N || dest < 1 || dest > N) {
                printf("Invalid vertex.\n");
                continue;
            }
            GNODE newnode = (GNODE)malloc(sizeof(struct node));
            newnode->vertex = dest;
            newnode->next = NULL;
            if (graph[src] == NULL) {
                graph[src] = newnode;
            } else {
                GNODE temp = graph[src];
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newnode;
            }
            printf("After inserting edge the adjacency list is : \n");
            for (int i = 1; i <= N; i++) {
                if (graph[i] != NULL) {
                    printf("%d=>", i);
                    GNODE p = graph[i];
                    while (p != NULL) {
                        printf("%d\t", p->vertex);
                        p = p->next;
                    }
                    printf("\n");
                }
            }
        }
        else if (choice == 3) {
            int src, dest;
            printf("Enter the source vertex of the edge : ");
            scanf("%d", &src);
            printf("Enter the destination vertex of the edge : ");
            scanf("%d", &dest);
            if (src < 1 || src > N || dest < 1 || dest > N) {
                printf("Invalid vertex.\n");
                continue;
            }
            GNODE curr = graph[src];
            GNODE prev = NULL;
            while (curr != NULL) {
                if (curr->vertex == dest) {
                    if (prev == NULL)
                        graph[src] = curr->next;
                    else
                        prev->next = curr->next;
                    free(curr);
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            printf("After deleting edge the adjacency list is : \n");
            for (int i = 1; i <= N; i++) {
                if (graph[i] != NULL) {
                    printf("%d=>", i);
                    GNODE p = graph[i];
                    while (p != NULL) {
                        printf("%d\t", p->vertex);
                        p = p->next;
                    }
                    printf("\n");
                }
            }
        }
        else if (choice == 4) {
            int v;
            if (N == 0) {
                printf("Graph is empty.\n");
                continue;
            }
            printf("Enter the vertex to be deleted : ");
            scanf("%d", &v);

            if (v < 1 || v > N) {
                printf("Invalid vertex.\n");
                continue;
            }
            GNODE temp = graph[v];
            while (temp != NULL) {
                GNODE t = temp;
                temp = temp->next;
                free(t);
            }
            graph[v] = NULL;
            for (int i = 1; i <= N; i++) {
                GNODE curr = graph[i];
                GNODE prev = NULL;
                while (curr != NULL) {
                    if (curr->vertex == v) {
                        if (prev == NULL)
                            graph[i] = curr->next;
                        else
                            prev->next = curr->next;
                        GNODE t = curr;
                        curr = curr->next;
                        free(t);
                    } else {
                        prev = curr;
                        curr = curr->next;
                    }
                }
            }
            for (int i = v; i < N; i++) {
                graph[i] = graph[i + 1];
            }
            graph[N] = NULL;
            N--;
            for (int i = 1; i <= N; i++) {
                GNODE temp2 = graph[i];
                while (temp2 != NULL) {
                    if (temp2->vertex > v)
                        temp2->vertex--;
                    temp2 = temp2->next;
                }
            }
            printf("After deleting vertex the adjacency list is : \n");
            for (int i = 1; i <= N; i++) {
                if (graph[i] != NULL) {
                    printf("%d=>", i);
                    GNODE p = graph[i];
                    while (p != NULL) {
                        printf("%d\t", p->vertex);
                        p = p->next;
                    }
                    printf("\n");
                }
            }
        }
        else if (choice == 5) {
            for (int i = 1; i <= N; i++) {
                if (graph[i] != NULL) {
                    printf("%d=>", i);
                    GNODE p = graph[i];
                    while (p != NULL) {
                        printf("%d\t", p->vertex);
                        p = p->next;
                    }
                    printf("\n");
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
