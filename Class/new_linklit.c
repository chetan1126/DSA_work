#include <stdio.h>
#include<stdlib.h>

///////function/////////////
int insert();
void display();
void deleteAtPos(int);
///////////////////////////

struct node{
	int data;
	struct node *next;

};

struct node *head;


int main()
{	
	int choice;
	int pos;
	while(1)
	{
		printf("Enter your choice\n1-insert 2-display 3- delete at pos 4-exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2: 
//				printf("switch");
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
				printf("ERROR");
				break;

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
int insert()
{
	int ele;
	printf("Enter element ");
	scanf("%d",&ele);

	struct node *temp;
	struct node *t1;
	t1 = head;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;

	if(head == NULL)
	{
		temp = head;
	}
	else
	{
		while(t1->next != NULL)
		{
			t1 = t1->next;

		}
		t1->next = temp;
	}

}


void display()
{
//	printf("function");
	struct node *t1;
	t1 = head;

	while(t1 != NULL)
	{

		printf("|%d|->",t1->data);
		t1 = t1->next;
	}
	printf("\n");

} 
