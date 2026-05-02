#include<stdio.h>
#include <stdlib.h>
#include <errno.h>

#define n 10

int array[n]={10,20,30,40,50,60,70,80,90,100};


char name[50];
char anything[50];
int main()
{
	FILE *fptr;
	fptr = fopen("text.text", "w");
	if(fptr==NULL)
	{
		perror("fopen");
		printf("errno= %d\n",errno);
	}
	
	for(int i=0; i<n; i++)
	{
		fprintf(fptr, "%d\n", array[i]);
	}
	
	fclose(fptr);
	int newarray[n];
	fptr = fopen("text.text", "r");
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
        fclose(fptr);
	
}
