/*Write a menu-driven C program to implement the following operations on a Circular Linked List (CLL):
1. Create:-
    Create a circular linked list with nodes.
    Read n integers from the user and form the list in the given order.
2. Insert - Insert a new node with value x at the given 1-based indexing position pos.*/

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    struct node *first=NULL,*last=NULL,*temp,*newnode,*prev;
    int n,x,pos,choice;
    while(1){
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Reverse\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("How many nodes: ");
            scanf("%d",&n);
            first=NULL;
            last=NULL;
            for(int i=0;i<n;i++){
                scanf("%d",&x);
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->data=x;
                newnode->next=NULL;
                if(first==NULL){
                    first=newnode;
                    last=newnode;
                    last->next=first;
                }
                else{
                    last->next=newnode;
                    last=newnode;
                    last->next=first;
                }
            }
        }
        else if(choice==2){
            printf("Position: ");
            scanf("%d",&pos);
            printf("Element: ");
            scanf("%d",&x);
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=x;
            if(pos==1){
                if(first==NULL){
                    newnode->next=newnode;
                    first=newnode;
                }
                else{
                    temp=first;
                    while(temp->next!=first)
                        temp=temp->next;
                    newnode->next=first;
                    temp->next=newnode;
                    first=newnode;
                }
            }
            else{
                temp=first;
                for(int i=1;i<pos-1;i++)
                    temp=temp->next;
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
        else if(choice==3){
            printf("Position: ");
            scanf("%d",&pos);
            temp=first;
            if(pos==1){
                while(temp->next!=first)
                    temp=temp->next;
                prev=first;
                first=first->next;
                temp->next=first;
                printf("Deleted: %d\n",prev->data);
                free(prev);
            }
            else{
                for(int i=1;i<pos-1;i++)
                    temp=temp->next;
                prev=temp->next;
                temp->next=prev->next;
                printf("Deleted: %d\n",prev->data);
                free(prev);
            }
        }
        else if(choice==4){
            if(first==NULL){
                printf("CLL is empty\n");
            }
            else{
                temp=first;
                do{
                    printf("%d -> ",temp->data);
                    temp=temp->next;
                }while(temp!=first);
                printf("\n");
            }
        }
        else if(choice==5){
            struct node *prev=NULL,*curr=first,*next;
            struct node *lastnode=first;
            while(lastnode->next!=first)
                lastnode=lastnode->next;
            prev=lastnode;
            do{
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }while(curr!=first);
            first=prev;
            printf("CLL Reversed\n");
        }
        else if(choice==6){
            break;
        }
        else{
            printf("Invalid choice\n");
        }
    }
    return 0;
}
