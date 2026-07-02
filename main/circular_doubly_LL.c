//------h file--------------
#include<stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
//------------------------------
//----------function------
int insert_linklist(struct node **,int);
int display_linklist(struct node *);
// int delete_from_end();

//-------------------
//---------struct-----------
//---------linklist---------

//------------------------------

int main()
{
    
int choice,position,element;
struct node *head;
    head = NULL;
    while(1)
    {
        printf("enter choice\n1)insertAtEnd\t2)display\t3)delete\t4)exit\n");
        
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    printf("enter number\n");
                    scanf("%d",&element);
                    insert_linklist(&head,element);
                    break;
            case 2:  
                    display_linklist(head);
                    break;
            case 3: 
                    // insert_at_pos();
                    break;
            case 4:
                    exit(-1);
                    break;
            default : 
                    printf("Enter valid menu\n");
        }
    }
}
 
//---------fucnction-------------------

int insert_linklist(struct node **head,int element){

    struct node *temp;
    struct node *t1;
    t1 = *head;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = element;
    temp->next = *head;

    if(*head == NULL){ 
        *head = temp;
        temp->next = temp;
    }
    else
    {
        while( t1->next != *head){
        t1 = t1->next; 
        }
    
    
    t1->next = temp;
        temp->next = *head;
        temp->prev = t1;

    }
}
int display_linklist(struct node *head){
    struct node *t1;
    t1 = head;
    printf("head=[%p]--->",head);
    if(head != NULL){
        while(t1->next != head){
            // printf("in\n");
            printf("[%p][%d][%p]-->",t1->prev,t1->data,t1->next);
            t1 =  t1->next;
        }
        printf("[%p][%d][%p]-->",t1->prev,t1->data,t1->next);
        printf("\n");
    }
    else{
        printf("all node delete\n");
    }
}
