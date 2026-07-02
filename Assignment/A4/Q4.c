/* question 
Q4. Write a C/C++ program to implement circular queue data 
structure using array. Implement below metioned functions. 
a) add  
b) delete 
c) peep 
d) displayQueue 
f) isQueueEmpty

*/
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
#define size 5
#define val -99
//------------------------------
//----------function------
void display(int array[]);
void dequeue(int array[], int *front, int *rear); //pop
void enqueue(int array[], int *front, int *rear, int ele); //push
void isQueueEmpty(int *front);
//-------------------
int main()
{
    int array[size];
    int front =-1;
    int rear = -1;
    int choice, ele;
    for(int i =0; i<size; i++){
        array[i]=val;
    }


    while(1)
    {
        printf("enter choice\n1-enqueue\t2-dequeue\t3-peep\t4-displayQueue\t5-isQueueEmpty\t6-exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    
                    break;
            case 2:  
                    break;
            case 3: 
                    
                    break;
            case 4: 
                    display(array);
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
void display(int array[]){
    for(int i=0; i<size; i++) printf("[%d] ",array[i]);
    printf("\n");
}
void enqueue(int array[], int *front, int *rear, int ele){
 //push   
    
} 



//-------------------------------------