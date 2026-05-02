/* question 
Q3. Write a C/C++ program to implement queue data structure using 
array. Implement below metioned functions. 
a) add   -- done
b) delete -- done
c) peep 
d) displayQueue -- done
f) isQueueEmpty -- done

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
                    printf("enter number\n");
                    scanf("%d",&ele);
                    enqueue(array , &front, &rear, ele);
                    break;
            case 2:  dequeue(array, &front, &rear);

                    break;
            case 3: 
                   
                    break;
            case 4: 
                     display(array);
                    break;
            case 5: 
                    isQueueEmpty(&front);
                    break;
            case 6:
                    exit(-1);
                    break;
            default : 
                    printf("Enter valid menu\n");

        }

    
    }
}
 
//---------fucnction-------------------

void enqueue(int array[], int *front, int *rear,int ele){
    if(*rear == size-1){
        printf("queue full\n");
        return;
    }
    (*rear)++;
    array[*rear] = ele;
    if(*front == -1){
        *front =0;
    }
        printf("front=%d rear=%d\n",*front,*rear);

}
void display(int array[]){
    for(int i=0; i<size; i++) printf("[%d] ",array[i]);
    printf("\n");
}

void dequeue(int array[], int *front, int *rear){
    if(*front == -1){
        printf("queue empty\n");
        return;
    }
    int temp = array[(*front)];
    array[(*front)] = -99;
    if(*front == *rear) *front =*rear = -1;
    else (*front)++;
    printf("pop - %d\n",temp);
    printf("front=%d rear=%d\n",*front,*rear);

}

void isQueueEmpty(int *front){
    if(*front == -1){
        printf("queue empty\n");
        return;
    }else
        printf("queue is not empty\n");
}



//-------------------------------------