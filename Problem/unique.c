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

                /*
                Loop through the entire array exactly once
                Time Complexity: O(N) - Linear scan of the array
                Space Complexity: O(1) - Constant space, uses only one extra primitive variable
                */

        }
        printf("single_unique_number = %d\n", single_unique_number);
        return single_unique_number;
        /*
          WHY THIS WORKS (XOR Properties):
         1. Commutative & Associative: The order of numbers does not matter (A ^ B ^ A == A ^ A ^ B).
          2. Self-Inverse: Any number XORed with itself becomes 0 (X ^ X = 0).
          Because of these rules, all duplicate pairs completely wipe each other out to 0, 
          leaving behind only the single unique number:
          e.g., 4 ^ 7 ^ 4  =>  (4 ^ 4) ^ 7  =>  0 ^ 7  =>  7
         */

}


int multi_unique(int *array, int *size)
{
        int single_unique_number = 0;
        for(int i = 0; i< *size; i++)
        {
                single_unique_number ^= array[i];
                /*
                Iterates through the entire array exactly once to XOR all elements.
                This takes O(N) time.
                */
        }

        int mask = single_unique_number & -single_unique_number;
        /*
         O(1) (constant) time.
         Divide numbers into two groups based on the mask bit.
         One group has the bit set, the other does not. XORing each group reveals the unique numbers.
         Time Complexity: O(N) | Space Complexity: O(1)
        */
        int num1_unique =0;
        int num2_unique = 0;

        printf("mask = %d and binary = %b\n", mask, mask);        
        
        for( int i =0 ; i<*size; i++)
        {
                if(array[i] & mask)
                        num1_unique ^= array[i];// Group 1: Bit is set
                else num2_unique ^= array[i]; // Group 2: Bit is not set

                /*
                 Iterates through the array a second time to separate the numbers
                  into two groups based on the mask.
                  This takes O(N) time
                  */
        }
        printf("num1_unique = %d\n", num1_unique);
        printf("num2_unique = %d\n", num2_unique);


        /*
          COMPLEXITY SUMMARY:
          Time Complexity:  O(N) - We loop through the array of size N twice sequentially.
          Space Complexity: O(1) - Constant memory. Only primitive stack variables 
          (mask, unique numbers, iterator) are used regardless of N.
         
         Total Time Complexity:
         O(N) + O(1) + O(N) = O(2N) ->O(N)
          */
        


}

//-------------------------------------