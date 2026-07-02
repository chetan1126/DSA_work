/* question 

Q2. Write a C/C++ program to implement single linked list.
Implement below metioned functions. Apply all required condition 
check & validation like list empty or not, while inserting/deleting by 
position validate the position.  
1)insertAtEnd 
2) insertAtBeg
3) insertAtPos 
4) displayList
5)listNodeCount
6) deleteFromEnd
7)deleteFromPos
8) deleteFromBeg
9) deleteByElement
10) reverseDisplay
11)freeAllNode
12) reverseList
13)sortedList
*/
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
//------------------------------
//----------function------
int insert_linklist();
int display_linklist();
int insert_at_beg();
int insert_at_pos();
int list_node_count();
int delete_from_end();
int delete_from_pos(int position);
int delete_from_beg();
int delete_by_element(int element);
int reverse_display();
void reverse_recursive(struct node*);
//-------------------
//---------struct-----------
//---------linklist---------
struct node *head;
//------------------------------

int main()
{
    
int choice,position,element;

    while(1)
    {
        printf("enter choice\n1)insertAtEnd\t2)insertAtBeg\t3)insertAtPos\t4)displayList\n");
        printf("5)listNodeCount\t6)deleteFromEnd\t7)deleteFromPos\t8)deleteFromBeg\n");
        printf("9)deleteByElement\t10)reverseDisplay\t11)freeAllNode\t12)reverseList\n");
        printf("13)sortedList\t14)exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    insert_linklist();
                    break;
            case 2:  
                    insert_at_beg();
                    break;
            case 3: 
                    insert_at_pos();
                    break;
            case 4: 
                    display_linklist();
                    break;
            case 5: 
                    printf("list_node %d count\n",list_node_count());
                    break;
            case 6: 
                    delete_from_end();
                    break;
            case 7: 
                    printf("enter position\n");
                    scanf("%d",&position);
                    delete_from_pos(position);
                    break;
            case 8: 
                    delete_from_beg();
                    break;
            case 9: 
                    printf("enter element\n");
                    scanf("%d",&element);
                    delete_by_element(element);
                    break;
            case 10: 
                    reverse_recursive(head);
                    // reverse_display();
                    break;
            case 14: 
                    exit(-1);
                    break;
            default : 
                    printf("Enter valid menu\n");
        }
    }
}
 
//---------fucnction-------------------

int insert_linklist(){
    int element;
    printf("enter your number");
    scanf("%d",&element);
    struct node *temp;
    struct node *t1;
    t1 = head;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = element;
    temp->next = NULL;

    if(head == NULL){ 
        head = temp;
    }
    else
    {
        while( t1->next != NULL){
        t1 = t1->next; 
        }
    
    
    t1->next = temp;
    }
}
int display_linklist(){
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
int insert_at_beg(){
    int element;
    printf("enter your number\n");
    scanf("%d",&element);

    struct node *temp;
    temp =(struct node *) malloc(sizeof(struct node));
    temp->data = element;
    temp->next = head;
    head = temp;
}
int insert_at_pos(){
    struct node *t1;
    struct node *t2;
    struct node *temp;
    int count = 1, element, position;

    printf("enter your number\n");
    scanf("%d",&element);
    printf("enter your position\n");
    scanf("%d",&position);

    temp = (struct node *) malloc(sizeof(struct node));

    t2 = NULL;
    t1 = head;

    temp->data = element;
    temp->next = NULL;

    if(position == 1){
        temp->next = head;
        head =temp;
        return 0;
    }
    while(t1 != NULL && count < position){ //t1->next != NULL &&
        t2 = t1;
        t1 = t1->next;
        count++;
    }
    if(t1 != NULL){
    temp->next = t1;
    t2->next = temp;
    }else {
        printf("Position out of bounds!\n");
        free(temp);
        free(t1);
        free(t2); 
    }

}
int list_node_count(){
    int count =0;
    struct node *t1;
    t1 = head;
    while(t1 != NULL){
        t1 = t1->next;
        count++;
        // printf("in\n");
    }
    // printf("list_node %d count\n", count);
    return count;
}
int delete_from_end(){

    struct node *t1;
    struct node *t2;
    t1 = head;
    t2 = NULL;


    while(t1->next != NULL){
        t2 = t1;
        t1 = t1->next;
        printf("in\n");
    }
    
    if(t2 != NULL){
        free(t1);
        t2->next = NULL;
        printf("successfully delete\n");
    }
    else{
        free(t1);
        head =NULL;
        printf("successfully delete first and last node of linklist\n");
    }

    
}  
int delete_from_beg(){
    struct node *temp;

    temp =head;
    head = temp->next;
    free(temp);
}
int delete_by_element(int element){
    struct node *t1;
    t1 = head;
    int count = 0 , flag =0, position = 0;
    while(t1 != NULL){
        count++;
        if (t1->data == element){
            flag =1;
            position = count;
        }
        t1 = t1->next;

    }
    printf("count- %d",count);
    if(flag == 1){
        delete_from_pos(position);
    }else{
        printf("enter element not exit in linklist");
    }
}
int reverse_display(){
    struct node *t1;
    t1=head;
    int index = list_node_count();
    int stack[index];
    int i=0;

    while(t1 != NULL){
        stack[i] = t1->data;
        t1 = t1->next;
        i++;
        // printf("in\n");
    }  

    for(int j= index-1; j>=0; j--){
        printf("<--%d", stack[j]);
    }
    printf("\n");
}

void reverse_recursive(struct node * t1){
    // static struct node *t1 = head ;
    if(t1 != NULL)
    {
        reverse_recursive(t1->next);
        printf("%d ",t1->data);
    }
}
//-------------------------------------