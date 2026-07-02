//------h file--------------
#include<stdio.h>
#include <stdlib.h>
struct node{
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
    temp->data = element;
    temp->next = NULL;

    if(*head == NULL){ 
        *head = temp;
    }
    else
    {
        while( t1->next != NULL){
        t1 = t1->next; 
        }
    
    
    t1->next = temp;
    }
}
int display_linklist(struct node *head){
    struct node *t1;
    t1=head;
    if(head != NULL){
        while(t1 != NULL){
            printf("%d-->",t1->data);
            t1 =  t1->next;
        }
        printf("\n");
    }
    else{
        printf("all node delete\n");
    }
}

// int delete_from_end(){

//     struct node *t1;
//     struct node *t2;
//     t1 = head;
//     t2 = NULL;


//     while(t1->next != NULL){
//         t2 = t1;
//         t1 = t1->next;
//         printf("in\n");
//     }
    
//     if(t2 != NULL){
//         free(t1);
//         t2->next = NULL;
//         printf("successfully delete\n");
//     }
//     else{
//         free(t1);
//         head =NULL;
//         printf("successfully delete first and last node of linklist\n");
//     }

    
// }



// //-------------------------------------