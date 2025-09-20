#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;
NODE start = NULL, cur, temp;

void insert(int data)
{
    if (start == NULL)
    {
        start = (NODE)malloc(sizeof(struct node));
        start->data = data;
        start->link = NULL;
    }
    else
    {
        cur = start;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        temp = (NODE)malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;
        cur->link = temp;
    }
}

void deleten()
{
    if (start == NULL)
    {
        printf(" Linked list does not have any nodes!\n");
    }
    else if (start->link == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        cur = start;
        while (cur->link != NULL)
        {
            temp = cur;
            cur = cur->link;
        }
        free(cur);
        temp->link = NULL;
    }
}

void display()
{
    if (start == NULL)
    {
        printf(" Linked list does not have any nodes!\n");
    }
    else
    {
        cur = start;
        while (cur!= NULL)
        {
            printf("--> %d\n", cur->data);
            cur = cur->link;
        }
    }
}

int main()
{
    int choice, data;
    while (1)
    {
        printf(" Linked list operations:\n 1. Create Node\n 2. Delete Node\n 3. Display \n 4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Enter data to insert : ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            deleten();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf(" Invalid Choice!\n");
        }
    }
    return 0;
}
