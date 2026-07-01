/* question 


*/
//------h file--------------
#include<stdio.h>
#include <stdlib.h>
//------------------------------
//----------function------
int single_unique(int *array, int *size);
int multi_unique(int *array, int *size);

//-------------------
int main()
{
    int choice;

    int array[]={10,20,30,40,2,6,10,20,30,40,};
    int size = (sizeof(array)/sizeof(int));



    while(1)
    {
        printf("enter choice\n1-unique\t2-multi_unique\t3-\t4-\t5exit\n");
        scanf("%d",&choice);
        printf("choice= %d\n", choice);
        switch(choice){
            case 1: 
                    single_unique(array,  &size);
                    break;
            case 2:  
                    multi_unique(array, &size);
                    break;
            case 3: 
                    
                    break;
            case 4: 
                    
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

int single_unique(int *array, int *size)
{
        int single_unique_number = 0;
        for(int i = 0; i< *size; i++)
        {
                single_unique_number ^= array[i];
                // printf("only = %d\n", single_unique_number);

        }
        printf("single_unique_number = %d\n", single_unique_number);
        return single_unique_number;
}


int multi_unique(int *array, int *size)
{
        int single_unique_number = 0;
        for(int i = 0; i< *size; i++)
        {
                single_unique_number ^= array[i];
        }

        int mask = single_unique_number & -single_unique_number;
        int num1_unique =0;
        int num2_unique = 0;

        printf("mask = %d and binary = %b\n", mask, mask);        
        
        for( int i =0 ; i<*size; i++)
        {
                if(array[i] & mask)
                        num1_unique ^= array[i];
                else num2_unique ^= array[i];
        }
        printf("num1_unique = %d\n", num1_unique);
        printf("num2_unique = %d\n", num2_unique);

}

//-------------------------------------