/* question 
Q1. Write a C program to implement single circular linked list 
with below metioned functionality. 
a) insertAtEnd   --done
b) insertAtBeg      --done
c) insertAtPos      --done
d) display          --done
e) listNodeCount    --done
f) deleteFromEnd    --done
g) deleteFromBeg    --done
h) deleteFromPos    --done


*/
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
//------------------------------
struct node{
    int data;
    struct node *next;
};
//----------function------
int insert_linklist(struct node **,int);
void insertAtBeg(struct node **ptr, int element);
void insertAtPos(struct node **ptr,int position, int element);
int display_linklist(struct node *);
void listNodeCount(struct node *ptr);
void deleteFromEnd(struct node **ptr);
void deleteFromPos(struct node **ptr, int position);
void deleteFromBeg(struct node **ptr);
//-------------------
int main()
{
    int choice,position,element;
    struct node *head;
    head = NULL;
    while(1)
    {
        printf("enter choice\n1-insertAtEnd\t2-insertAtBeg\t3-insertAtPos\t4-display\
 5-listNodeCount\t 6-deleteFromEnd\t 7- deleteFromBeg\t 8-deleteFromPos\t9-exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    printf("enter number\n");
                    scanf("%d",&element);
                    insert_linklist(&head,element);
                    break;
            case 2:  
                    printf("enter number\n");
                    scanf("%d",&element);
                    insertAtBeg(&head, element);
                    break;
            case 3: 
                    printf("enter your number\n");
                    scanf("%d",&element);
                    printf("enter your position\n");
                    scanf("%d",&position);        
                    insertAtPos(&head,position,element);
                    break;
            case 4: 
                    display_linklist(head);
                    break;
            case 5: 
                    listNodeCount(head);
                    break;
            case 6: 
                    deleteFromEnd(&head);
                    break;
                    
            case 7:
                    deleteFromBeg(&head);
                    break;
            case 8:
                    
                    printf("enter your position\n");
                    scanf("%d",&position);        
                    deleteFromPos(&head,position);
                    break;
            case 9: 
                    exit(-1);
                    break;
            default : 
                    printf("Enter valid menu\n");

        }

    
    }
}
 
//---------fucnction-------------------


int insert_linklist(struct node **ptr,int element){

    struct node *temp;
    struct node *t1;
    t1 = *ptr;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = element;
    temp->next = NULL;

    if(*ptr == NULL){ 
        *ptr = temp;
        temp->next = temp;
    }
    else
    {
        while( t1->next != *ptr){
        t1 = t1->next; 
        }

        t1->next = temp;
        temp->next = *ptr;

    }
}
int display_linklist(struct node *ptr){
    struct node *t1;
    t1 = ptr;
    
    if(ptr != NULL){
        printf("head=[%p]--->",ptr);
        do{
            // printf("in\n");
            printf("[%d][%p]-->",t1->data,t1->next);
            // printf("head=[%p]--->",ptr);
            t1 =  t1->next;
        }while(t1 != ptr);
        // printf("[%d][%p]-->",t1->data,t1->next);
        printf("\n");
    }
    else{
        printf("all node delete\n");
    }
}

void insertAtBeg(struct node **ptr, int element){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = element;
    // printf("temp->data=[%d][%p] --[%p]--->",temp->data,temp->next,temp);

    struct node *t1;
    t1  = *ptr;
    if(*ptr == NULL){ 
        *ptr = temp;
        temp->next = temp;
        return;
    }
    // temp = *ptr;
    while(t1->next != *ptr){
        t1 = t1->next;
    }
    // t1->next->next = *ptr;
     temp->next = *ptr;
     t1->next = temp;
    //  printf("temp-next")
    *ptr = temp;
    // temp->next = NULL;
    //head=[00B42F68]--->[10][00B42F78]-->[20][00B42F68]-->
    //head=[00852F68]--->[10][00852F78]-->head=[00852F68]--->[20][00852F68]-->

    // head=[00CD2F68]--->[10][00CD2F78]-->head=[00CD2F68]--->[20][00CD2F68]-->2   
    // temp->data=[30][00CD2F88]--->e
    
    // head=[00BF2F48]--->[10][00BF2F58]-->head=[00BF2F48]--->[20][00BF2F48]-->
    // temp->data=[30][00BF00C0] --[00BF2F68]--->enter choice

    // head=[00CA2F48]--->[10][00CA2F58]-->head=[00CA2F48]--->[20][00CA2F48]-->
    // temp->data=[30][00CA00C0] --[00CA2F68]--->enter choice
}
 
void insertAtPos(struct node **ptr,int position, int element){
    struct node *t1;
    struct node *t2;
    struct node *temp;
    int count = 1;

    t2 = NULL;
    t1 = *ptr;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = element;
    temp->next = NULL;

    if(position == 1){
        insertAtBeg(ptr, element);
        return ;
    }
    // else if(position == )
    while(t1->next != *ptr && count < position){ 
        t2 = t1;
        t1 = t1->next;
        // printf("count = %d",count);
        count++;
    }
    if(t1 != *ptr){
    temp->next = t1;
    t2->next = temp;
    }else {
        printf("Position out of bounds!\n");
        free(temp);
        free(t1);
        free(t2); 
    }
}

void listNodeCount(struct node *ptr){
    struct node *t1;
    t1 = ptr;
    int count = 0;
   
    do{
        t1 = t1->next;
        count++;
    }while(t1 != ptr);
    printf("count = %d\n ",count);
    
}

void deleteFromEnd(struct node **ptr){
    struct node *t1;
    struct node *t2;
    t1 = *ptr;
    t2 = NULL;

    if ((*ptr)->next == *ptr) {
        free(*ptr);
        *ptr = NULL;
        printf("Deleted the first last node.\n");
        return;
    }

    do{
        t2 = t1;
        t1 = t1->next;
        printf("in\n");
    }while(t1->next != *ptr);
    printf("t1-data = %d",t1->data);
    if(t2->next != *ptr){
        free(t1);
        t2->next = *ptr;
        printf("successfully delete\n");
    }
    // else{
    //     free(t1);
    //     *ptr =NULL;
    //     printf("successfully delete first and last node of linklist\n");
    // }
}

void deleteFromPos(struct node **ptr, int position){
    struct node *t1;
    struct node *t2;
    int count =1;
    t1 = *ptr;
    t2 = NULL;
    if(position == 1){
        return;
    }
    do{
        t2 = t1;
        t1 = t1->next;
        count++;
    }while(t1->next != *ptr && count < position );
    t2->next = t1->next;
    free(t1);
}

void deleteFromBeg(struct node **ptr){
    struct node *t1;
    struct node *t2;
    t1 = *ptr;
    t2 = *ptr;
    // t2 = t2->next;

    do{
        t1 = t1->next;
    }while(t1->next != *ptr);

        *ptr = t2->next;
        t1->next = t2->next; 
        free(t2);
}

//-------------------------------------
