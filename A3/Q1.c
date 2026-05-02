/* question 
Q1. Write a C/C++ program to implement below mentioned Searching 
and Sorting Techniques.
(a) Bubble Sort
(b) Selection Sort
(c) Insertion Sort

*/
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
//------------------------------
//----------function------
int bubble_sort(int *array, int size);
int selection_sort(int *array, int size);
int insertion_sort(int *array, int size);
//-------------------
int main()
{
    int index, choice;
    // printf("enter number of index");
    // scanf("%d",&index);
    // int array[index];
    int array[]={20,30,40,50,50,30,25,5,95};
    int size = (sizeof(array)/sizeof(int));
    // printf("enter array");
    // for(int i=0; i<size; i++){
    //     printf("array[%d]-");
    //     scanf("%d",&array[i]);
    // }
    printf("%d\n",size);


    while(1)
    {
        printf("enter choice\n1-bubble\t2-selection sort\t3-insertion sort\t4exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    bubble_sort(array, size);
                    break;
            case 2:  
                      selection_sort(array, size);
                    break;
            case 3: 
                    insertion_sort(array, size); 
                    break;
            case 4: 
                    exit(-1);
                    break;
            default : 
                    printf("Enter valid menu\n");

        }

    
    }
}
 
//---------fucnction-------------------
int bubble_sort(int *array, int size){
    int temp;
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size-1-i; j++){
            if(array[i]>array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }


        for(int i=0; i<size; i++)
	{
		printf(" %d ", array[i]);
        // printf("array[%d] = %d \n", i,array[i]);

	}
	printf("\n");
}
int selection_sort(int *array, int size){

    
        int minimum_index_val,temp;
    for(int i=0; i<size; i++){
        minimum_index_val=i;
        for(int j=i+1; j<size; j++){
            if(array[minimum_index_val]>array[j]){
                minimum_index_val=j;
                }
            }
        temp = array[i];
        array[i] = array[minimum_index_val];
        array[minimum_index_val] = temp;
        }
    for(int i=0; i<size; i++)
	{
		printf(" %d ", array[i]);
        // printf("array[%d] = %d \n", i,array[i]);

	}
	printf("\n");

}


int insertion_sort(int *array, int size){
    int i,j ,temp;
    for (i=1; i<size; i++){
        temp = array[i];
        j = i-1;
        while(j>=0 && array[j] > temp){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
    printf("sort by insertion \n");
    for(int k = 0; k<size; k++){
        printf("%d ", array[k]);
    }
    printf("\n");
   
}




//-------------------------------------