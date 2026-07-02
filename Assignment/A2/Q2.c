/*
Q2. Write a C/C++ program to implement Binary Search. We need to check for duplicate element inputs, 
* if found any should not insert into the input array.  
* The array should manage in sorted order. 
* Apply a duplicacy check on the element while inserting the element, 
* if found duplicate then discards the input. 
* The input element should insert in the array at the right position( index). 
* Appropriate shifting can be applied in the array in order to insert the input element at the right position.
* An appropriate condition check needs to apply for element not found scenario. 
(a) Binary Search ( iterative approach)
(b) Binary Search ( recursion approach )
*/
// not full done
#include<stdio.h>
#include <stdlib.h>
//----------function------
int insert_check_duplicate(int *array, int size);
int duplicate(int *array,int , int);
int binary_search_iterative ( int *array, int);
int binary_search_recursive( int *array, int size , int low,int high, int ele);
int display(int *array,int size);

//-------------------
int main()
{
    int index;
    int result;
    // printf("enter number of index");
    // scanf("%d",&index);

    // int array[index];
    
    int array[]={10,20,30,40,50,50,50,80,90,95};
    int size = (sizeof(array)/sizeof(int));
    // printf("enter array");
    // for(int i=0; i<size; i++){
    //     printf("array[%d]-");
    //     scanf("%d",&array[i]);
    // }
    // printf("\n");
    int choice, value;
    int ele;

    while(1)
    {
        printf("enter choice\n1-insert\t2-display\t3-binary_search_iterative\t4-binary_search_recursive\t5exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    // printf("Enter value want to search\n");
                    // scanf("%d", &value);
                    // duplicate( array, value ,size);
                    insert_check_duplicate(array, size);
                    
                    break;
            case 2:  display(array,size);
                    break;
            case 3: 
                    result= binary_search_iterative(array, size);
                    if(result != -22)
                     printf("Element found at index %d\n",result);
                     else printf("Element not found\n");
                    break;
            case 4: 
                    printf("enter insert ele\n");
                    scanf("%d",&ele);
                    result= binary_search_recursive( array, size , 0 ,size-1,ele);
                    if(result != -22)
                     printf("Element found at index %d\n",result);
                     else printf("Element not found\n");
                    break;
      
            case 5: 
                    exit(-1);
                    break;
            default : 
                    printf("Enter valid menu\n");

        }

        //     printf("display:\n");
        // for(int i=0; i<size; i++)
        // {
        // 	printf(" %d ", array[i]);
        // 	//printf("array[%d] = %d \n", i,array[i]);
        // }
        // printf("\n");
    }
}


int binary_search_iterative ( int *array, int size)
{
    int ele;
    printf("enter insert ele\n");
    scanf("%d",&ele);

     int low = 0, high = size - 1, mid;

     while (low <= high)
     {
        mid = (low + high) / 2;

        if (array[mid] == ele)
            return mid;
        else if (array[mid] < ele)
            low = mid + 1;
        else
            high = mid - 1;
     }

    return mid = -22; // Not found
    //  if(mid != -22)
    //  printf("Element not found\n");
}


int binary_search_recursive( int *array, int size , int low,int high, int ele)
{// 4567012  01234567
    
    //  int  high = size - 1, mid;
      int  mid = (low + high) / 2;

        if (array[mid] == ele)
            return mid;
        else if (array[mid] < ele)
            return  binary_search_recursive( array,  size,  mid+1,high ,ele);
        else
            return  binary_search_recursive( array,size,low,mid-1, ele);
     
    return mid = -22; // Not found
    
}

int display(int *array,int size)
{
    for(int i=0; i<size;i++)
    {
        printf("%d ",array[i]);
        // printf("array[%d]-%d\n", i, array[i]);
    }
            printf("\n");
}

//---------------------------------------------------------
int insert_check_duplicate(int *array ,int size){
    int ele, index;
    printf("enter insert ele\n");
    scanf("%d",&ele);
    int i, found =0;
    for( i=0; i<size; i++)
    {
        if(array[i] == ele){
		printf("Duplicate Array is %d\n", array[i]);
        found = 1;
        return 1;
        }
    }
    // for (i=size; array[i]>ele; i--){
    //     array[i+1] = array[i];
    // }
    // array[i+1] = ele;
    if(found == 0){
        printf("enter index\n");
        scanf("%d",&index);
        array[index] = ele;
    }


}
int duplicate( int *array, int value ,int size){
    for (int i = 0; i < size; i++ ){
		for (int j = i+1; j < size; j++)
		{
			if ((array[i] == array[j]) ) //&& array[i] != value
			{
				printf("Duplicate Array is %d\n", array[i]);
                return 1;
				break;
			} 
            // else printf("No Duplicate Array");
		}
	}

    // return 
}