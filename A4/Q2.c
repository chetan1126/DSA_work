/* question 
Q2. Write a C/C++ program to implement stack data structure using 
array. Implement below metioned functions. 
a)push -- done
b)pop -- done
c)peep
d)displayStack -- done 
f)isStackEmpty -- done

*/
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
#define size 5
#define val -99
//------------------------------
//----------function------
void display(int array[]);
void pop(int array[], int *top);
void push(int array[], int *top, int ele);
void isStackEmpty(int *top);
//-------------------
int main()
{
        int array[size];
        int top =-1;
        int choice, ele;
        for(int i =0; i<size; i++){
                array[i]=val;
        }
        while(1)
        {
                printf("enter choice\n1-push\t2-pop\t3-peep\t4-displayStack\t5-isStackEmpty\t6-exit\n");
                scanf("%d",&choice);
                switch(choice){
                case 1: 
                        printf("enter number\n");
                        scanf("%d",&ele);
                        push(array , &top,ele);
                        break;
                case 2:  
                        pop(array, &top);
                        break;
                case 3: 
                        
                        break;
                case 4: 
                        display(array);
                        break;
                case 5:
                        isStackEmpty(&top);
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

void push(int array[], int *top,int ele){
    if(*top == size-1){
        printf("stack full\n");
        return;
    }
    (*top)++;
    array[*top] = ele;
}
void display(int array[]){
    for(int i=0; i<size; i++) printf("[%d] ",array[i]);
    printf("\n");
}

void pop(int array[], int *top){
    if(*top == -1){
        printf("stack empty\n");
        return;
    }
    int temp = array[(*top)];
    array[(*top)] = -99;
    (*top)--;
    printf("pop - %d\n",temp);
}

void isStackEmpty(int *top){
    if(*top == -1){
        printf("stack empty\n");
        return;
    }else
        printf("stack is not empty\n");

}


//-------------------------------------