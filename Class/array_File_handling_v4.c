#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
int insert(int , int );
int delete( );
void search(int);
int display();
int reset();
int File_save();
int first_call_fun();
#define n 10
int array[n]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//int array[n]={10,20,30,40,50,60,70,80,90,100};
//int array[n];

char name[50];
char anything[50];

int main()
{
int option, value, index;
//printf("how many element in array\n");
//scanf("%d",&n);
//array[n];
	int size = (sizeof(array)/sizeof(int));
	
	first_call_fun();
	
	while(1)
	{
		printf("\tEnter your option\n\t1-insert\n\t2-delete\n\t3-search\n\t4-display\n\t5-Reset\n\t6-Save File\n\t7-exit\n");
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
				reset();
				break;
			case 6: 
				File_save();
				break;
			case 7: 
				exit(-1);
				break;
			default : 
				printf("Enter valid menu\n");
				
		}
	}


}
int insert(int value, int index)
{
	int size = (sizeof(array)/sizeof(int));
	int index_fun =index;
	int pos_dir_size = size - index;
	int neg_dir_size = index;

	if(index <=size)
	{
		if(array[index_fun] == -{
			array[index_fun] = value;
			printf("insert array[%d]: %d\n", index_fun , array[index_fun]);
		}
		else if( array[index_fun] != -1)
		{
			for(int i=0; i<=pos_dir_size; i++)
			{
				index_fun++;
				if(index_fun <= size)
				{
					if(array[index_fun] == -1)
					{
						array[index] = value;
						array[index_fun] = array[index_fun - 1];
						printf("insert1 array[%d]: %d\t insert1 array[%d]: %d\n", index_fun , array[index_fun], index_fun-1 , array[index_fun-1]);
						break;
					}
				}
				else 
				{
				
				}
			}
		}
		else 
		{
			printf("Insertion not possible\n");
		}
	}
	else
	{
		printf("Enter valid index value\n");
	}	
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
					array[i] = -1;
					printf("delete array[%d]: %d\n", i ,  array[i]);
				}
				else if(i == (size - 1))
					printf("invalid value\n");
			}
			break;
		case 2: 
			printf("Enter the index you want to delete\n");
			scanf("%d",&index);
			
			if(index <= size)
			{
				array[index] = -1;
				printf("delete array[%d]: %d\n", index, array[index]);
			}
			else 
				printf("invalid index\n");
		default : 
				printf("Enter valid menu\n");
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
printf("  0   1   2   3   4   5   6   7   8   9 \n");
}

int reset()
{
	int size = (sizeof(array)/sizeof(int));
	for(int i=0; i<size; i++)
	{
		array[i] = -1;
	}
}


int File_save()
{
	FILE *fptr;
	fptr = fopen("Array_File_save.txt", "w");
	if(fptr==NULL)
	{
		perror("fopen");
		printf("errno= %d\n",errno);
	}
	
	for(int i=0; i<n; i++)
	{
		fprintf(fptr, "%d\n", array[i]);
	}
	//gets(array);
	fclose(fptr);
	int newarray[n];
	fptr = fopen("Array_File_save.txt", "r");
	if(fptr==NULL)
	{
		perror("fopen");
		printf("errno= %d\n",errno);
	}
	int counter=0;
	while((fscanf(fptr, "%d", &newarray[counter++])) != EOF);
	
	for(int i=0; i<n; i++)
	{
		printf("newarray[%d] = %d\n",i,  newarray[i]);
	}
	
}


int first_call_fun()
{
	FILE *fptr;
	fptr = fopen("Array_File_save.txt", "r");
	if(fptr==NULL)
	{
		perror("fopen");
		printf("errno= %d\n",errno);
	}
	int counter=0;
	while((fscanf(fptr, "%d", &array[counter++])) != EOF);
	
	for(int i=0; i<n; i++)
	{
		printf("array[%d] = %d\n",i,  array[i]);
	}
}

