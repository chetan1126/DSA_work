/*
Q1. Write a C/C++ program that declares an array of length N
containing integers between 1 and N. Implement menu driven
program using switch case for below mentioned functionalities.
(1) insert element at index
(2) delete element at index
(3) find min val
(4) find max val
(5) display array element
(6) reverse display array element
(7) search element in array
(8) array element count
(9) avg of all array element
(10) determine if array contains any duplicates.
(11) reverse array element
*/

#include<stdio.h>
#include <stdlib.h>

int insert(int *array, int size);
int delete( int *array, int size);
void search(int *array, int size,int value);
int display(int *array, int size);
int min_value(int *array, int size);
int max_value(int *array, int size);
int reverse_display(int *array, int size);
int array_element_count(int *array,int size);
float avg_value(int *array, int size);
int duplicate(int *array, int size, int value);
int reverse_array(int *array,int size);
void menu();
#define val -1
int n;
//int array[]={-1,20,20,-1,-1,-1,-1,-1,-1,-1,};
//int array[n];
//int array[] = {10,20,30,5,99};



int main()
{
int option, value, index;
	printf("enter how many element");
	scanf("%d",&n);
	int array[n];
	for(int i=0; i<n; i++)
	{
		array[i]= val;
	}
	// int array[] = {10,20,30,5,99};
		int size = (sizeof(array)/sizeof(int));
	while(1)
	{
		menu();
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: 
				
				insert(array,size);
				break;
			case 2: 
				
				delete(array,size);
				break;
			case 3:
				min_value(array,size);
				break;
			case 4: 
				max_value(array,size);
				break;
			case 5: 
				 display(array,size);
				break;
			case 6: 
				reverse_display(array,size);
				break;
			case 7: 
				printf("Enter value want to search\n");
                                scanf("%d", &value);
                                search(array,size,value);
				break;
			case 8: 
				array_element_count(array,size);
				break;
			case 9:
				avg_value(array,size);
				break;
			case 10:
			printf("Enter value want to search duplicate\n");
                                scanf("%d", &value);
				duplicate(array,size,value);
				break;
			case 11:
				reverse_array(array,size);
				break;

			case 12: 
				exit(-1);
				break;
			default : 
				printf("Enter valid menu\n");
				
		}
	}


}
void menu(){
		printf("Enter your option\n1-insert\t2-delete\t3-minimum value\n");
		printf("4-maximum value\t5-display\t6-reverse display\n");
		printf("7-search\t8-array element count\t9-average1\n");
		printf("10-duplicate\t11-reverse\t12-exit\n");
}
int insert(int *array, int size){
	int index,value;
	printf("Enter value of index\n value index\n");
	scanf("%d %d", &value, &index);
	array[index] = value;
	printf("insert: %d\n", array[index]);
}

int delete(int *array, int size){
	int d_option;
	int index, value;

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
					array[i]=val;
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
				array[index]=val;
				printf("delete array[%d]: %d\n", index, array[index]);
			}
			else 
				printf("invalid index\n");
	}
	
}


int min_value(int *array, int size){
	 int minval =1;
	for(int i=0; i<size; i++)
	{
		if (array[i]  <  array[i+1])
		{
			minval =array[i];
		}
	}
	printf("min= %d\n", minval);
}

int max_value(int *array, int size){
	int maxval = 0;
	for (int i=0; i<size; i++)
	{
		if(maxval < array[i])
		{
			maxval =array[i];
		}
	}
	printf("max=%d\n",maxval);
}
void search(int *array, int size,int value){	
	for(int i=0; i<size; i++)
	{
		if(array[i] == value)
		{
			printf("search array[%d]: %d\n", i , array[i]);
		}
	}
}

int reverse_display(int *array, int size){
	// int size = (sizeof(array)/sizeof(int));
	for(int i=size-1; i>=0; i--)
	{
		printf("%d  ",array[i]);
	}
	printf("\n");
}

int display(int *array, int size){
	// int size = (sizeof(array)/sizeof(int));
	printf("display:\n");
	for(int i=0; i<size; i++)
	{
		printf(" %d ", array[i]);
		//printf("array[%d] = %d \n", i,array[i]);
	}
	printf("\n");
}
float avg_value(int *array, int size){
	float sum=0;
	float avg=0;
	for(int i=0; i<size; i++)
	{
		sum += array[i];	
	}
	avg = sum/size;
	printf("Average of Array = %0.2f\n", avg);
}

int array_element_count(int *array,int size){
	int count = 0;
	for(int i=0; i<size; i++){
		if(array[i] != val)
			count++;
	}
	printf("Array element count = %d\n",count);
}
int duplicate(int *array, int size ,int val){
	for (int i = 0; i < size; i++ ){
		for (int j = i+1; j < size; j++)
		{
			if ((array[i] == array[j]) && array[i] != val)
			{
				printf("Duplicate Array is %d\n", array[i]);
				break;
			} 
		}
	
	}
}

int reverse_array(int *array,int size){
	int temp=0;
	for(int i=0; i<size/2; i++){
		temp = array[i];
		array[i] = array[size-i-1];
		array[size-i-1] = temp;
	}
	display(array,size);
}
