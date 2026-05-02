#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

/////////////////////////////////
//linklist structure definr
///////////////////////////////
struct node
{
	int data;
	struct node *next;
};

struct node *head;
////////////////////
///////////function///////////////
void insert(int);
void display();
void deleteAtPos(int pos);
//////////////////////////////////



int main()
{
	//head =NULL;
	int pos, choice, ele;
	while(1)
	{
		printf("enter choice\n 1-insert 2-display 3- delete at pos 4-exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: 
				scanf("%d", &ele);
				insert(ele);
				break;
			case 2:
				display();
				break;
			case 3: 
                                printf("enter pos\n");
                                scanf("%d",&pos);

                                deleteAtPos(pos);
                                break;

			case 4: 
				exit(-1);
				break;
			default:
				perror("switch(choice)");
				printf("errno = %d\n",errno);
		}
	}
}


void deleteAtPos(int pos){
        struct node *t1,*t2;
        t1 = head;
        t2= NULL;

        if(pos == 1){
                head = t1->next;
                free(t1);
        }
        int jump = 0;
        while (jump++ <pos-1){

                t2 = t1;
                t1 = t1->next;

        }
        t2->next = t1->next;
        free(t1);
}

void insert(int ele)
{
	struct node *temp;
	struct node *t1;
	t1 = head;
	temp = malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
	}
	else{
		while(t1->next != NULL)
		{
			t1 = t1->next;
		}
	
		t1->next = temp;
	}
}

void display()
{
	struct node *t2;
//	struct node *temp;
	t2 = head;

	while(t2 != NULL)
	{
		printf("|[%d]|-->", t2->data);
		t2 = t2->next;
	}
	printf("\n");

}
