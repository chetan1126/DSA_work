#include<stdio.h>
#include <stdlib.h>

int insert(int , int );
int delete( );
void search(int);
int display();
int n;
int array[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,};
//int array[n];

int main()
{
int option, value, index;
//printf("how many element in array\n");
//scanf("%d",&n);
//array[n];
	int size = (sizeof(array)/sizeof(int));
/*	for(int i=0; i<size; i++)
	{
		printf("array[%d]", i);
		scanf("%d", &array[i]);
		printf("\n");
	}
*/	

	while(1)
	{
		printf("Enter your option\n1-insert\n2-delete\n3-search\n4-display\n5-exit\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: 
				printf("Enter value of index\n value index\n");
				scanf("%d %d", &value, &index);
				insert(value , index);
				break;
			case 2: 
				
				delete( );
				break;
			case 3: 
				printf("Enter value want to search\n");
				scanf("%d", &value);
				search(value);
				break;
			case 4: 
				//printf("Enter value of index\n");
				//scanf("%d",&index);
				display();
				break;
			case 5: 
				exit(-1);
				break;
			default : 
				printf("Enter valid menu\n");
				
		}
	}


}
int insert(int value, int index)
{
	array[index] = value;
	printf("insert: %d\n", array[index]);
}

int delete()
{
int d_option;
int index, value;
int size = (sizeof(array)/sizeof(int));

	printf("\t\t1-delete by value\n\t\t2-delete by index\n");
	scanf("%d",&d_option);
	
	switch(d_option)
	{
		case 1: 
			printf("Enter the value you want to delete\n");
			scanf("%d",&value);
			
			for(int i=0; i<size; i++)
			{
				if(array[i] == value)
				{
					array[i]=NULL;
					printf("delete: %d\n", array[i]);
				}
				else if(i == (size - 1))
					printf("invalid value\n");
			}
			break;
		case 2: 
			printf("Enter the index you want to delete\n");
			scanf("%d",&index);
			
			if(index<=size)
			{
				array[index]=NULL;
				printf("delete array[%d]: %d\n", index, array[index]);
			}
			else 
				printf("invalid index\n");
	}
	
}

void search(int value)
{	//int size=n;
	int size = (sizeof(array)/sizeof(int));
	for(int i=0; i<size; i++)
	{
		if(array[i] == value)
		{
			printf("search array[%d]: %d\n", i , array[i]);
		}
	}
}

int display()
{
//int index;
	//printf("display: %d\n", array[index]);
	//int size=n;
	int size = (sizeof(array)/sizeof(int));
	printf("display:\n");
	for(int i=0; i<size; i++)
	{
		printf(" %d ", array[i]);
		//printf("array[%d] = %d \n", i,array[i]);
	}
printf("\n");
}
