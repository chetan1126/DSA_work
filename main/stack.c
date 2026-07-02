#include<stdio.h>
#define size 5
#define val -99

void display(int array[]);
void pop(int array[], int *top);
void push(int array[], int *top, int ele);
int main(){
    int array[size];
    int top =-1;
    int choice, ele;
    for(int i =0; i<size; i++){
        array[i]=val;
    }
    while(1){
        printf("1-push 2-pop 3-display\n");
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
                    display(array);
                    // exit(-1);
                    break;
        }
    }


}

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