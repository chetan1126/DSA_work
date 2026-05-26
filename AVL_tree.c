/* question 
tree--> avl tree
//aa test case
*/
//trial 2
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
//------------------------------
//----------function------
struct node {
    struct node *left;
    int data;
    struct node *right;
};

void insert(struct node **head,int);
void display_inorder(struct node *head);
void display_preorder(struct node *head);
void display_postorder(struct node *head);
//-------------------
int main()
{
        int index,element,choice;
        struct node *head;
        head = NULL;

        while(1)
        {
            printf("enter choice\n1-insert\t2-display\t3-\t4-\t5exit\n");
            scanf("%d",&choice);
            switch(choice){
                case 1: 
                        printf("enter number\n");
                        scanf("%d",&element);
                        insert(&head,element);
                        break;
                case 2: 
                        printf("\n---------------\n");
                        printf("inorder--\n");
                        display_inorder(head);
                        printf("\n---------------\n");
                        printf("preorder--\n");
                        display_preorder(head);
                        printf("\n---------------\n");
                        printf("postorder--\n");
                        display_postorder(head); 
                        printf("\n---------------\n"); 
                        break;
                case 3: 
                        
                        break;
                case 4: 
                        
                        break;
                case 5: 
                        exit(-1);
                        break;
                default : 
                        printf("Enter valid menu\n");

            }

        
        }
}
 
//---------fucnction-------------------

void insert(struct node **head,int element){
    if(*head == NULL){
        *head = (struct node*)malloc(sizeof(struct node));
        (*head)->data = element;
        (*head)->left = NULL;
        (*head)->right = NULL;
    }
    else{
        if((*head)->data < element) insert(&(*head)->right,element);
        else insert(&(*head)->left,element);
    }
}

void display_inorder(struct node *head){
    if((head) != NULL){
        display_inorder(head->left);
        printf("%d ", head->data);
        display_inorder(head->right);
    }
}

void display_preorder(struct node *head){
    if((head) != NULL){
        printf("%d ", head->data);
        display_preorder(head->left);
        display_preorder(head->right);
    }
}

void display_postorder(struct node *head){
    if((head) != NULL){
        display_postorder(head->left);
        display_postorder(head->right);
        printf("%d ", head->data);
    }
}

//-------------------------------------