/*
Q1. Write a C/C++ program to implement Linear Search. 
We need to check for duplicate inputs.  
If the duplicate element is allowed then a linear search algo needs to implement accordingly. 
An appropriate condition check needs to apply for element not found scenario. 
(a) Search Element ( iterative approach )
(b) Search Element ( recursion approach )
(c) Print Input array ( iterative approach )
(d) Print Input array ( recursion approach )
(e) Print Input array reverse order ( iterative approach )
(f) Print Input array reverse order ( recursion approach )
*/
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
//------------------------------
//----------function--------------------------------------------
void linear_search_iterative(int *array, int size, int target);
void linear_search_recursive(int *array, int size, int target, int o);
void print_iterative(int *array, int size);
void print_recursive(int *array, int size, int i);
void print_iterative_recusive(int *array, int size);
void print_recursive_reverse(int *array, int size, int i);
//----------------------------------------------------------------------


int main()
{
    int array[]={10,20,30,40,10,60,10,80,90,100};
    int size = (sizeof(array)/sizeof(int));


    int target,choice;
    while(1){
            printf("enter choice\n1-linear_search_iterative\t2-linear_search_recursion\t3-print_iterative \
                \t4-print_recursive \t 5-print_iterative_reverse\t6-print_recursive_reverse\t7-exit\n");
            scanf("%d",&choice);
            switch(choice){
                case 1: 
                        printf("enter target element\n");
                        scanf("%d",&target);
                        linear_search_iterative(array, size,target);
                        break;
                case 2:  
                        printf("enter target element by recursive\n");
                        scanf("%d",&target);
                        linear_search_recursive(array, size,target,0);
                        break;

                case 3: 
                        print_iterative(array, size);
                        break;
                case 4: 
                        print_recursive(array,size,0);
                        printf("\n");
                        break;
                case 5: 
                        print_iterative_recusive(array, size);
                        break;
                case 6: 
                        print_recursive_reverse(array,size,0);
                        printf("\n");
                        break;
                case 7: 
                        exit(-1);
                        break;
                default : 
                        printf("Enter valid menu\n");

            }
        } 

}

void linear_search_iterative(int *array, int size, int target){
    int found = 0;
    printf("Iterative Search\n");
    for (int i = 0; i < size; i++){
        if (array[i] == target) {
            printf("found at index: %d\n", i);
            found = 1;
        }
    }

    if (found == 0){
        printf("Element %d not found\n", target);
    }
}
void linear_search_recursive(int *array, int size, int target, int i){
    static int found = 0;

     if (i == size){
            if (found == 0){
                printf("Element %d not found\n", target);
            }
        }

    if(i < size){

        if (array[i] == target) {
                printf("found at index: %d\n", i);
                found = 1;
            }

        linear_search_recursive(array, size,  target, i+1);
    }
}

void print_iterative(int *array, int size){

    for(int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void print_recursive(int *array, int size, int i){
    if(i < size){
        printf(" %d ", array[i]);
        print_recursive(array,size, i+1);
            // printf("\n");
    }
}


void print_iterative_recusive(int *array, int size){

    for(int i = size-1; i >= 0; i--){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void print_recursive_reverse(int *array, int size, int i){
    if(i < size){
        print_recursive_reverse(array,size, i+1);
        printf(" %d ", array[i]);
    }
}