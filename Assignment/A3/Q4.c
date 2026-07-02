/* question  done ok
Q4. Write a C/C++ program to implement single linked list to store 
Student Information ( StudentName and StudentPRN).
Implement below metioned functions. Apply all required condition 
check & validation like list empty or not, while inserting/deleting by 
position validate the position.  
a)insertAtEnd
b) insertAtBeg
c) insertAtPos 
d) displayList 
e)listNodeCount 
f) deleteFromEnd 
h)deleteFromPos
g) deleteFromBeg 
i) deleteByElement
j) reverseDisplay
k)freeAllNode  

*/
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------------------
struct student{
        int prn;
        char name[50];
        struct student *next;
};
//----------function------
int insert_at_end(struct student **head,int prn,char NAME[]);
int display_linklist(struct student *head);
void insert_at_beg(struct student **head,int PRN,char NAME[]);
void insert_at_pos(struct student **head,int PRN,char NAME[] , int position);
int list_count_node(struct student *head);
void delete_from_end(struct student **head);
void delete_from_pos(struct student **head, int position);
void delete_from_beg(struct student **head);
void delete_by_element(struct student **head, int PRN);
void reverse_recursive(struct student *);
void free_all_node(struct student **head);
//-------------------
int main()
{
    int index,choice,PRN=0,position;
    char NAME[50];
    struct student *head;
    head = NULL;


    while(1)
    {
        printf("enter choice\n1-insertAtEnd\t2-insertAtBeg\t3-insertAtPos\t4-displayList\t5-listNodeCount\
 \n6-deleteFromEnd\t7-deleteFromEnd\t8-deleteFromPos\t9-deleteFromBeg\t10-deleteByElement\n\
 11-reverseDisplay\t12-freeAllNode\t 13-exit\n");
        scanf("%d",&choice);
                switch(choice){
                case 1: 
                        printf("enter number ");
                        scanf("%d",&PRN);
                        printf("enter name ");
                        scanf("%s",NAME);
                        insert_at_end(&head,PRN,NAME);
                        break;
                case 2:  
                        printf("enter number ");
                        scanf("%d",&PRN);
                        printf("enter name ");
                        scanf("%s",NAME);
                        insert_at_beg(&head,PRN,NAME);
                        break;
                case 3: 
                        printf("enter your position\n");
                        scanf("%d",&position);
                        printf("enter number ");
                        scanf("%d",&PRN);
                        printf("enter name ");
                        scanf("%s",NAME);
                        insert_at_pos(&head,PRN,NAME,position);
                                
                        
                        break;
                case 4: 
                        display_linklist(head);
                        break;
                case 5: 
                        list_count_node(head);
                        break;
                case 6:
                        delete_from_end(&head);
                        break;
                case 7: 
                        
                        break;
                case 8: 
                        printf("enter position\n");
                        scanf("%d",&position);
                        delete_from_pos(&head,position);
                        break;
                case 9:  
                        delete_from_beg(&head);
                        break;
                case 10: 
                        printf("enter PRN\n");
                        scanf("%d",&PRN);
                        delete_by_element(&head,PRN);
                        break;
                case 11: 
                        reverse_recursive(head);
                        break;
                case 12:
                        free_all_node(&head);
                        break;
                case 13: 
                        exit(-1);
                        break;
                default : 
                        printf("Enter valid menu\n");

        }

    
    }
}
 
//---------fucnction-------------------
int insert_at_end(struct student **head,int PRN,char NAME[]){

    struct student *temp;
    struct student *t1;
    t1 = *head;
    temp = (struct student *) malloc(sizeof(struct student));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }
    temp->prn = PRN;
    strcpy(temp->name, NAME);
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
    return 0;
}

int display_linklist(struct student *head){
    struct student *t1;
    t1=head;
    if(head != NULL){
        while(t1 != NULL){
            printf("PRN - %d\t",t1->prn);
            printf("NAME- %s\t", t1->name);
            printf("t1->next--%u\n",t1->next);
            t1 =  t1->next;
        }
        printf("\n");
    }
    else{
        printf("all node delete\n");
    }
}

void insert_at_beg(struct student **head,int PRN,char NAME[]){

    struct student *temp;
    temp =(struct student *) malloc(sizeof(struct student));
    temp->prn = PRN;
    strcpy(temp->name, NAME);
    temp->next = *head;

    *head = temp;
}

void insert_at_pos(struct student **head,int PRN,char NAME[] , int position){
    struct student *t1;
    struct student *t2;
    struct student *temp;
    int count = 1;

    temp = (struct student *) malloc(sizeof(struct student));

    t2 = NULL;
    t1 = *head;

        temp->prn = PRN;
        strcpy(temp->name, NAME);
        temp->next = NULL;

    if(position == 1){
        temp->next = *head;
        *head =temp;
        return ;
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

int list_count_node(struct student *head){
    struct student * t1;
    t1= head;
    int node_count = 0;

    while(t1 != NULL){
        node_count++;
        t1= t1->next;
    }
    printf("node count = %d\n",node_count);
    return node_count;
}

void delete_from_end(struct student **head){
    
    struct student *t1;
    struct student *t2;
    t1 = *head;
    t2 = NULL;

    printf("t1->next--%u\n",t1->next);
    while(t1->next != NULL){
        t2 = t1;
        printf("1t1->next--%u\n",t1->next);
        t1 = t1->next;
        printf("in loop\n");
        printf("t1->next--%u\n",t1->next);
    }
    
    if(t2 == NULL){
        // free(t1);
        // t2->next = NULL;
        // printf("successfully delete\n");
        // free(t2);
        
        free(t1);
        // t2->next = NULL;
        *head =NULL;
        printf("successfully delete first and last node of linklist\n");
    }
    else{
        // t1->prn = NULL;
        // t1->name = NULL;
        // t1->next = NULL;
        // free(t1);
        // head =NULL;
        // printf("successfully delete first and last node of linklist\n");
        free(t1);
        t2->next = NULL;
        printf("successfully delete\n");
    }
}

void delete_from_pos(struct student **head, int position){
      
    struct student *t1;
    struct student *t2;
    int count=1;
    t1 = *head;
    t2 = NULL;

    while(count< position && t1 != NULL){
        t2 = t1;
        t1 = t1->next;
        count++;
        // printf("in loop\n");
    }
    
    if(t2 == NULL){
        // free(t1);
        *head =t1->next;
        t1->next = NULL;
        free(t1);
        printf("successfully delete first and last node of linklist\n");
    }
    else{
        // free(t1);
        t2->next = t1->next;
        free(t1);
        printf("successfully delete\n");
    }
}

void delete_from_beg(struct student **head){
    struct student *t1;
    t1 = *head;
    *head = t1->next;
    free(t1);
}

void delete_by_element(struct student **head, int PRN){
    struct student *t1;
    t1 = *head;
    int count = 0 , flag =0, position = 0;
    while(t1 != NULL){
        count++;
        if(PRN == t1->prn){
            flag =1;
            position = count;
            // delete_from_pos(&head,count);
            break;
        }
        t1 = t1->next;
    }
    printf("count- %d\n",count);
    if(flag == 1){
            delete_from_pos(head,count);
    }else{
        printf("enter element not exit in linklist\n");
    }
}

void reverse_recursive(struct student *ptr){
    // static struct node *t1 = head ;
    if(ptr == NULL)
        {
            return;
        }
    else{
        reverse_recursive(ptr->next);
        printf("PRN - %d\t",ptr->prn);
        printf("NAME- %s\t", ptr->name);
        printf("ptr->next--%u\n",ptr->next);
    }
}

void free_all_node(struct student **head){
	struct student *t1 = *head;
	while(t1 != NULL){
	*head = t1;
	t1 = t1->next;
	free(*head);
	}
	*head=NULL;

}
//-------------------------------------

// void delete_from_end(struct student *head){
//     struct student *t1;
//     struct student *t2;
//     t1=head;
//     t2 = NULL;

//     if(head == NULL){
//         printf("no node present all delete\n");
//     }
//     else {
//         while(t1->next != NULL){
//             t2 = t1;
//             t1 = t1->next;
//         }
//         if(t2 != NULL){
//             t2 = NULL;
//             // t1 = NULL;
//             free(t1);
//             printf("node delete\n");
//         }else{
//             // t2->next = NULL;
//             // free(t1);
//             // printf("node delete\n");
//             printf("t2->next = %d\n", t2->next);
//             free(t1);
//             free(t2);
//             head =NULL;
//             printf("last node delete\n");
//         }
//     }
// }
// //-------------------------------------