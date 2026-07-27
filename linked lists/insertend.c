//Insertion at the end of a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *second, *third;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    struct node *newNode;
    newNode = malloc(sizeof(struct node));

    newNode->data = 40;
    newNode->next = NULL;

    struct node *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    temp = head;

    while(temp!=NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    free(head);
    free(second);
    free(third);
    free(newNode);

    return 0;
}