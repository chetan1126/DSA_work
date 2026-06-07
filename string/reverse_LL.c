#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// Function Prototypes
void insert_linklist(struct node **head, int element);
void display_linklist(struct node *head);
void reverse_linklist(struct node **head);
void free_linklist(struct node **head);

int main()
{
    int choice, element;
    struct node *head;

    head = NULL;

    while(1)
    {
        printf("\n1) Insert");
        printf("\n2) Display");
        printf("\n3) Reverse");
        printf("\n4) Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Number : ");
                scanf("%d",&element);
                insert_linklist(&head, element);
                break;

            case 2:
                display_linklist(head);
                break;

            case 3:
                reverse_linklist(&head);
                printf("Linked List Reversed\n");
                break;

            case 4:
                free_linklist(&head);
                printf("All Nodes Freed\n");
                exit(0);

            default:
                printf("Enter Valid Choice\n");
        }
    }
}

// Insert at End
void insert_linklist(struct node **head, int element)
{
    struct node *temp;
    struct node *t1;

    temp = (struct node *)malloc(sizeof(struct node));

    if(temp == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    temp->data = element;
    temp->next = NULL;

    if(*head == NULL)
    {
        *head = temp;
    }
    else
    {
        t1 = *head;

        while(t1->next != NULL)
        {
            t1 = t1->next;
        }

        t1->next = temp;
    }
}

// Display
void display_linklist(struct node *head)
{
    struct node *t1;

    t1 = head;

    if(head == NULL)
    {
        printf("Linked List Empty\n");
        return;
    }

    while(t1 != NULL)
    {
        printf("%d --> ", t1->data);
        t1 = t1->next;
    }

    printf("NULL\n");
}

// Reverse
void reverse_linklist(struct node **head)
{
    struct node *prev;
    struct node *t1;
    struct node *temp;

    prev = NULL;
    t1 = *head;

    while(t1 != NULL)
    {
        temp = t1->next;
        t1->next = prev;
        prev = t1;
        t1 = temp;
    }

    *head = prev;
}

// Free All Nodes
void free_linklist(struct node **head)
{
    struct node *t1;
    struct node *temp;

    t1 = *head;

    while(t1 != NULL)
    {
        temp = t1;
        t1 = t1->next;
        free(temp);
    }

    *head = NULL;
}


/*
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// Function Prototypes
void insert_linklist(struct node **head, int element);
void display_linklist(struct node *head);
void reverse_linklist(struct node **head);
void free_linklist(struct node **head);

int main()
{
    int choice, element;
    struct node *head;

    head = NULL;

    while(1)
    {
        printf("\n1) Insert");
        printf("\n2) Display");
        printf("\n3) Reverse");
        printf("\n4) Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Number : ");
                scanf("%d",&element);
                insert_linklist(&head, element);
                break;

            case 2:
                display_linklist(head);
                break;

            case 3:
                reverse_linklist(&head);
                printf("Linked List Reversed\n");
                break;

            case 4:
                free_linklist(&head);
                printf("All Nodes Freed\n");
                exit(0);

            default:
                printf("Enter Valid Choice\n");
        }
    }
}

// Insert at End
void insert_linklist(struct node **head, int element)
{
    struct node *temp;
    struct node *t1;

    temp = (struct node *)malloc(sizeof(struct node));

    if(temp == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    temp->data = element;
    temp->next = NULL;

    if(*head == NULL)
    {
        *head = temp;
    }
    else
    {
        t1 = *head;

        while(t1->next != NULL)
        {
            t1 = t1->next;
        }

        t1->next = temp;
    }
}

// Display
void display_linklist(struct node *head)
{
    struct node *t1;

    t1 = head;

    if(head == NULL)
    {
        printf("Linked List Empty\n");
        return;
    }

    while(t1 != NULL)
    {
        printf("%d --> ", t1->data);
        t1 = t1->next;
    }

    printf("NULL\n");
}

// Reverse
void reverse_linklist(struct node **head)
{
    struct node *prev;
    struct node *t1;
    struct node *temp;

    prev = NULL;
    t1 = *head;

    while(t1 != NULL)
    {
        temp = t1->next;
        t1->next = prev;
        prev = t1;
        t1 = temp;
    }

    *head = prev;
}

// Free All Nodes
void free_linklist(struct node **head)
{
    struct node *t1;
    struct node *temp;

    t1 = *head;

    while(t1 != NULL)
    {
        temp = t1;
        t1 = t1->next;
        free(temp);
    }

    *head = NULL;
}
*/