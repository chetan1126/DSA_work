/* question 
Q3. Find the Factor
Determine the factors of a number (i.e., all positive integer values 
that evenly divide into a number) and then return the p
the element of the list, sorted ascending. If there is no p the element, return 0.

Example: n = 20 and p = 3
The factors of 20 in ascending order are {1, 2, 4, 5, 10, 20}. Using 1-based 
indexing, if p = 3, then 4 is returned. If p > 6, 0 would be returned.

Function Description
Complete the function pthFactor in the editor below.

pthFactor has the following parameter(s):
int n: the integer whose factors are to be found
int p: the index of the factor to be returned
Returns:
int: the long integer value of the p

the integer factor of n or, if there is no factor at that index, then 0 is returned
*/

//------h file--------------
#include<stdio.h>
#include<stdlib.h>
//-----------linklist-------------------
struct node{
    int data;
    struct node *next;
};
struct node *head;
//-----------------------------------

//----------function------------------------------------------
int factor_find_stored_in_linklist(int , int);
void insert_linklist(int);
void display_linklist();
void pth_element_of_linklist(int, int);
void combine_logic(int num,int pth_element,int factor_index);
void free_linklist();
//-----------------------------------------------------------
int main()
{
    int  num,pth_element, choice;
    int factor_index = 0;
    while(1){
        printf("enter number  ");
        scanf("%d",&num);
        printf("enter pth the index ");
        scanf("%d",&pth_element);

        
        factor_index = factor_find_stored_in_linklist(num, factor_index);
        printf("factor %d are of %d  ",factor_index,num);
        display_linklist();    
        pth_element_of_linklist(pth_element,factor_index);

        // combine_logic( num, pth_element, factor_index);
        free_linklist();
        display_linklist();    

/*
        choice =0;
        printf("1-if want to find pth element of above number\n2- if want to give anothe number to find");
        scanf("%d",&choice);
        // free_linklist();
        switch(choice){
            case 1: 
                    factor_index = factor_find_stored_in_linklist(num, factor_index);
                    printf("enter pth the index ");
                    scanf("%d",&pth_element);
                    pth_element_of_linklist(pth_element,factor_index);
                    free_linklist();
                    break;
            case 2: 
                    free_linklist();
                    // combine_logic( num, pth_element, factor_index);
                    break;
            default : 
                    printf("Enter valid menu\n");
        }
                    */
       
    }
}
 
//---------fucnction-------------------
void free_linklist(){
    struct node *t1;
    // struct node *t2;
    while(t1 != NULL){
        head=t1;
        t1 = t1->next;
        free (head);
    }
    head =NULL;
}

void insert_linklist(int element){
    struct node *temp;
    struct node *t1;
    
    t1 =head;
    temp = (struct node *)malloc(sizeof(struct node));
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

int factor_find_stored_in_linklist(int num, int factor_index){
    for(int i = 1; i<=num; i++){
        if(num%i == 0){
            factor_index++;
            // printf("%d\n",i);
            insert_linklist(i);
        }
    }
    return factor_index;
}


void display_linklist(){
    struct node *t1;
    t1 = head;
    if(head != NULL){
        while(t1 != NULL){
            printf("%d--> ", t1->data);
            t1 = t1->next;
        }
        printf("\n");
    }else {
        printf("all free\n");
    }
}

void pth_element_of_linklist(int pth_element, int factor_index){
    struct node *t1;
    t1 = head;
    int count_compare = 1;
    if(pth_element <= factor_index){
        if(head != NULL){
            while(t1 != NULL && count_compare <= pth_element){           
                if(count_compare == pth_element){
                    printf("pth element is = %d  ", t1->data);
                }
                count_compare++;
                t1 = t1->next;
            }
        }
    }
    else{
        printf("Enter pth value doesnot exit. Enter another pth value  ");
    }
}

void combine_logic(int num,int pth_element,int factor_index){

        factor_index = factor_find_stored_in_linklist(num, factor_index);
        printf("factor %d are of %d\n",factor_index,num);
        display_linklist();    
        pth_element_of_linklist(pth_element,factor_index);
}
//-------------------------------------