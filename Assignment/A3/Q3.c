/* question 

Q3. Write a C/C++ program to implement single linked list in sorted 
order. Implement below metioned functions. Apply all required 
condition check & validation like list empty or not, while 
inserting/deleting by position validate the position. Implement a policy
for duplicate value input.    
a)insert  
b) displayList  c)listNodeCount d) deleteFromEnd 
e) deleteFromBeg f)deleteFromPos g) reverseDisplay

*/
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
//------------------------------
struct node{
    int data;
    struct node *next;
};
struct node *head;
//----------function------
void insert_linklist(int);
int duplicat_check(int);
int insert_at_pos(int element, int position);
void insert_sort_linklist(int);
void display_linklist();
void sort_linklist();
int list_node_count();
void delete_from_end();
void delete_from_beg();
void delete_from_pos(int);
void free_linklist();
void reverse_display(struct node*);
//-------------------
int main()
{
    int index,  choice, element,position;
    // printf("enter number of index");
    // scanf("%d",&index);
    // int array[index];
  //  int array[]={10,20,30,40,50,50,50,80,90,95};
   // int size = (sizeof(array)/sizeof(int));
    // printf("enter array");
    // for(int i=0; i<size; i++){
    //     printf("array[%d]-");
    //     scanf("%d",&array[i]);
    // }
    // printf("\n");


    while(1)
    {
        printf("enter choice\n1-insert\t2-display_list\t3-list node count\t4-delete from end\n \
5-delete from beg\t6-delete from pos\t7-reverse display\t8exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    printf("enter number of index");
                    scanf("%d",&element);
                    // duplicat_check( element);
                    // insert_sort_linklist(element);
                    insert_linklist(element);
                    // duplicat_check( element);
                    break;
            case 2:  
                    display_linklist();
                    // printf("enter number of index");
                    // scanf("%d",&element);
                    // duplicat_check( element);
                    // duplicat_check( element);

                    break;
            case 3: 
                    // sort_linklist();
                    list_node_count();
                    break;
            case 4: 
                    delete_from_end();
                    break;
            case 5:
                    delete_from_beg();
                    break;
            case 6: 
                    printf("enter number of position ");
                    scanf("%d",&position);
                    delete_from_pos(position);
                    break;
            case 7: 
                    reverse_display(head);
                    break;
            case 8: 
                    free_linklist();
		    display_linklist();
		    // exit(-1);
                    break;
            default : 
                    printf("Enter valid menu\n");

        }

    
    }
}
 
//---------fucnction-------------------
int insert_at_pos(int element, int position){
    struct node *t1;
    struct node *t2;
    struct node *temp;
    int count = 1;

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
int duplicat_check(int element){
    struct node *t1;
    t1 = head;
    int flag_duplicate =0;
    if(head != NULL){
        while(t1 != NULL){
            t1 = t1->next;
            if(t1->data == element){
                flag_duplicate=1;
            }
        }
    }
    if(flag_duplicate ==1){
        printf("duplicat found \n");
    }
    else{
        printf("duplicat not found\n");
    }
    return flag_duplicate;
}
void insert_sort_linklist(int element){
    
        struct node *temp;
        struct node *t1;
        struct node *t2;

        int count=0;
        int flag =0;

        temp = (struct node *)malloc(sizeof(struct node));
        t1=head;
        t2 = NULL;

        temp->data = element;
        temp->next = NULL;
    // if(duplicat_check(element) != 1){
        if(head == NULL){
            head = temp;
        }
        else{
            while(t1->next != NULL){
                t2 = t1;
                t1 = t1->next;
                count++;
                printf("count %d\n",count);
                printf("t2-data = %d  t1-data = %d\n",t2->data,t1->data);
                if(t2->data < element && element < t1->data){
                    // insert_at_pos(element, count);
                    printf("flag ==1\n");
                    flag =1;
                    break;
                }
                // else t1->next = temp;
            }
            // if(t1->next == NULL && flag ==0){
            //     t1->next = temp;
            //     printf("if\n");

            // }
            if(flag == 1){
                insert_at_pos(element, count+1);
                printf("in\n");
            }else{
                t1->next = temp;
                printf("if\n");
            }
        }
    // }else{
    //     printf("duplicat found cannot insert\n");
    // }
}
void insert_linklist(int element){
    struct node *temp;
    struct node *t1;

    temp = (struct node *)malloc(sizeof(struct node));
    t1=head;
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
            printf("%d-->",t1->data);
            t1 = t1->next;
        }
        printf("\n");
    }
    else {
        printf("not available linklist\n");
    }
}
void sort_linklist(){
    struct node *t1;
    struct node *t2;
    struct node *temp;

    int var3rd;
    t1 = head;
    t2 = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if(head != NULL){
        while(t1->next != NULL){
            t2 = t1;
            t1 = t1->next;
            if(t2->data > t1->data){
                temp->data = t2->data;
                t2->data = t1->data;
                t1->data = temp->data;
                printf("pass\n");
            }else{
                printf("fail\n");
            }
        }
    }
        display_linklist();
}
int list_node_count(){
    struct node *t1;
    t1 = head;
    int node_count = 0;

    if(head != NULL){
        while(t1 != NULL){
            node_count++;
            t1 = t1->next;
            printf("in\n");
        }
    }else {
        printf("zero node\n");
    }
    printf("node_count = %d\n",node_count);
    return node_count;
}
void delete_from_end(){
    struct node *t1;
    t1 = head;

    if(head != NULL){
        if(t1->next == NULL){
            free(t1);
            head = NULL;
        }
        else {
            while(t1->next->next != NULL){
                // printf("%d-\n",t1->data);
                t1 = t1->next;
            }
            free(t1->next);
            t1->next = NULL;
        }
    }else{
        printf("not available linklist\n");
    }
}
void delete_from_beg(){
    struct node *t1;
    t1 = head;

    if(head != NULL){
            head = t1->next;
            free(t1);
    }
        else {
            printf("not available linklist\n");
        }
}
void delete_from_pos(int position){

    struct node *t1;
    struct node *temp;
    t1 = head;

    int count_position = 0;
    if(head != NULL){
        while(count_position < position ){
            // printf("%d-\n",t1->data);
            t1 = t1->next;
            count_position++;
            printf("c %d\n",count_position);
        }//not work
        // t1->next = (t1->next->next);
        // printf(" af %d-\n",t1->data);
        // free(t1->next->next);
        temp = t1->next;
        t1->next = temp->next;
        free(temp);
    }
    else printf("vv");
    
}
 void reverse_display(struct node *t1){
    if(t1 != NULL){
        reverse_display(t1->next);
        printf("%d ", t1->data);
    }
 }
void free_linklist(){
	struct node *t1;
	while(t1 != NULL){
	head = t1;
	t1 = t1->next;
	free(head);
	}
	head=NULL;

}

//-------------------------------------
