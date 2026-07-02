/*
Q4. Count Duplicate Elements
Given an integer array, numbers, count the number of elements that occur more than once.
Example numbers = [1, 3, 3, 4, 4, 4]
There are two non-unique elements: 3 and 4.
Function Description:
Complete the function countDuplicate in the editor below.
countDuplicate has the following parameter(s):
int numbers[n]:  an array of integers
Returns:
int: an integer that denotes the number of non-unique values in the numbers array
*/

//------h file--------------
#include<stdio.h>
#include <stdlib.h>
//------------------------------
//------------linklist-------------
struct node{
    int data;
    struct node *next;
};
struct node *head;
//---------------------------------
//----------function------
void insert_linklist(int);
void display_linklist();
void duplicate();
void free_linklist();
//-------------------


int main(){

    int size,element;
    while(1){
        printf("enter size ");
        scanf("%d",&size);
        for(int i =0; i<size; i++){
            printf("%d th element = ", i);
            scanf("%d", &element);
            insert_linklist(element);
        }
        display_linklist();
        duplicate();
        free_linklist();
        display_linklist();
    }
}

void insert_linklist(int element){
    struct node *t1;
    struct node *temp;
    t1 = head;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
    }
    else{
        while(t1->next != NULL){
            t1 = t1->next;
        }
        t1->next = temp;
    }
}

void display_linklist(){
    struct node *t1;
    t1 = head;
    if(head != NULL){
        while(t1 != NULL){
            printf("%d->", t1->data);
            t1 = t1->next;

        }
        printf("\n");
    }
    else{
        printf("fee all node\n");
    }
}
void duplicate(){
    struct node *t1;
    struct node *t2;
    int count= 0;
    t1 =head;
    t2 =t1;

    if (head == NULL) return; // on empty list

    while(t1->next != NULL &&  t1 != NULL ){  //t1->next != NULL && //&& t2 != NULL
        // t2 = t1 ;
        t2 =t1->next;
        printf("1st- %d (==) %d ",t1->data,t2->data);
        // printf("1st loop t2data-%d and t1-data-%d\n", t2->data,t1->data);
        while(t2 != NULL ){     //&& t1->next != NULL
            // t1 = head;
            // t1= t1->next;
            printf("2nd- %d (==) %d ",t1->data,t2->data);

            // printf("2nd loop t2data-%d and t1-data-%d\n", t2->data,t1->data);

            if(t2->data == t1->data){
                printf("non unique is %d ", t2->data);
                count++;
            }
            // t1=head;
            t2 = t2->next;
            printf("\n");
        }
        // t1=t2;
        t1=t1->next;
        // printf("in\n");
    }
    printf("%d are duplicate number\n",count);
}
void free_linklist(){
    struct node *t1;
    t1 = head;
    while(t1 != NULL){
        head = t1;
        t1 = t1->next;
        free(head);
    }
    head = NULL;
    free(head);
}