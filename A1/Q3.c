/*
Q3. Write C/C++ prgram which allocate and deallocate memory dynamically. 
(a) Allocating 1D array dynamically and access the elements
(b) Allocating 2D array dynamically
(1) contiguous rows with fixed no.of cols,
(2) Non contiguous rows with variable no.of columns
(c) Allocate memory for array of structure variables dynamically and access members of each element
*/

#include<stdio.h>
#include <stdlib.h>

//-------------function-------------
int array_1D_fun();  //a
int array_2d_contigueous_fun(); // b1
int array_2d_non_contigueous_fun(); //b2
int struct_dynamic();
//-------------------------------------
//--------struct---------------------
struct que_3c{
    int id;
    char name[20];
};
// int array_2D_fun();
int main()
{
    int choice;
    while(1)
    {
        printf("enter your choice\n");
        printf("1- (a) \t 2- (b1)\t 3- (b2)\t 4- (c)\t 5-exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                    array_1D_fun();
                    break;
            case 2: array_2d_contigueous_fun();
                    break;
            case 3: 
                    array_2d_non_contigueous_fun();
                    break;
            case 4: 
                    struct_dynamic();
                    break;
            case 5: 
                    exit(-1);
        }
    }

}

int array_1D_fun()
{
    int number_of_element;
    printf("Enter number of element\n");
    scanf("%d", &number_of_element);
    int *array[number_of_element];
    *array = (int *)malloc((number_of_element)*(sizeof(int) ) );
    for(int i=0; i<number_of_element; i++)
    {   //scan 1d aaray
        printf("Enter element %d --",i+1);
        scanf("%d", &array[i]);
    }
    printf("//////////////////////////////\n");
    for(int i=0; i<number_of_element; i++)
    {// print 1d array
        // printf(" array[%d] =  %d\n", i+1, array[i]);
        printf("   %d\t", array[i]);
    }
    printf("\n");
        printf("//////////////////////////////\n");

    free(array);
    return 0;

}

int array_2d_contigueous_fun()
{

    int number_of_2d_array_row = 0 , number_of_2d_array_column = 0;
    printf("Enter number_of_row");
    scanf("%d",&number_of_2d_array_row);
    printf("Enter number_of_column");
    scanf("%d",&number_of_2d_array_column);

    int *array_2d[number_of_2d_array_row][number_of_2d_array_column];

    for(int row = 0; row < number_of_2d_array_row; row++)
    {//scan
        for(int column =0; column < number_of_2d_array_column; column++)
        {
                printf("array_2d[%d_%d] =", row,column);
                scanf("%d", &array_2d[row][column]);
        }
    }
        printf("//////////////////////////////\n");
    for(int row = 0; row < number_of_2d_array_row; row++)
    {//print
        for(int column =0; column < number_of_2d_array_column; column++)
        {
                // printf("array_2d[%d_%d] = %d\n", row,column, array_2d[row][column] );  
                printf(" %d\t", array_2d[row][column] );  
        }
        printf("\n");
    }
        printf("//////////////////////////////\n");

    free(array_2d);
    return 0;
}

int array_2d_non_contigueous_fun()
{
 
    // row and column decleare---------------------
    int number_of_2d_array_row_qb2 = 0;
    printf("Enter number_of_row - ");
    scanf("%d",&number_of_2d_array_row_qb2); // number of scan
    //------------------------------
    int column_size_want_in_row_qb2; // for size of column how many wants
    printf("Enter number column - ");
    scanf("%d",&column_size_want_in_row_qb2); //scan size of column 
    //-------------if--------------------
    // if()
    //------------array decl--------------------
    int column_size[column_size_want_in_row_qb2];
    int *array_2d_qb2 = (int *) malloc((number_of_2d_array_row_qb2)*(sizeof(int)));
    //------------------------------------

    for(int i =0; i<number_of_2d_array_row_qb2; i++)
    {
        printf("Enter number column_size_want_in_row -- ");
        scanf("%d",&column_size[i]);
        // column size inside element taken how many column want in row one by one
    }

    for(int j= 0; j < number_of_2d_array_row_qb2; j++)
    {
        array_2d_qb2[j] =(int *) malloc((column_size[j])*(sizeof(int)));

    }
    
    printf("\narray_2d_qb2 --V\n");
    printf("//////////////////////////////\n");
    for(int row = 0; row < number_of_2d_array_row_qb2; row++)
    {//print
        for(int column =0; column < column_size[row]; column++)
        {
                printf(" %d\t", array_2d_qb2[row]=(row+column+1) );  
        }
        printf("\n");
    }
    printf("//////////////////////////////\n");
    free(array_2d_qb2);
    free(column_size);
    return 0;

}

int struct_dynamic()
{
    int number_insert;
    printf("number of insert\n");
    scanf("%d",&number_insert);
    struct que_3c *que3c = malloc( number_insert * sizeof(struct que_3c));

    for(int i=0; i< number_insert; i++)
    {
        que3c[i].id = (101+i);
        // que3c[i].name = 'name-i'+1;  /// not work
        sprintf(que3c[i].name, "name-%d", i+1);
    }
    printf("record\n");
    printf("//////////////////////////////\n");
    for(int j = 0; j< number_insert; j++)
    {
        printf("id - %d \t name - %s\n", que3c[j].id,que3c[j].name);

    }
        printf("//////////////////////////////\n");
  free(que3c);
    return 0;
}