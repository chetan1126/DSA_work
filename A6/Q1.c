/*
Create an Employee Database menu driven program having 
info (name, age, id, addresss, date of joining, id proof)
id proof types -> ADHAR / PASSPORT / PAN CARD. 
{ Hint - Use Enum + Union}


Guidelines =>
(Have Validation check for every input, malloc, free, id, age etc. 
for example - age / id / date of joining cant be negative or 0.) ---done
(proper comments / code indentation / arguments to function <= 3)
(List head should be maintained local in main() ) 

1. Use Doubly Circular Linked List for each employee.       --done
2. Insert in sorted order according of id. (1 Unique id per employee)
3. Menu option to sort list based on age.
4. Menu option to sort list based on id.                 --done
5. Menu option to write all information in a file.      --done
6. Menu option to load all information from file and reinitialise the list.     --done
7. Menu option to Display range for date of joining         --done
(User input 2005 so all employees with date of joining > 2005 will be displayed)
8. Menu option to delete by id.
9. Menu option to find employee by name or id.

*/
//------h file--------------
#include<stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
//------------------------------
typedef struct date_of_join{
    int day;
    int month;
    int year;
}doj;
typedef struct employee{
    struct employee *prev;
    char name[50];
    int age;
    int id;
    char address[100];
    //struct date_of_join;
    doj date;
    struct employee *next;
} empdata;
//----------function------
void insert_emp_data(empdata **ptr_to_head);
int display_linklist(empdata *ptr_to_head);
void display_range_ac_date(empdata *ptr_to_head, int range);
int backup_file_fun();
int File_save(empdata *ptr_to_head);
int backup_file_fun(empdata **ptr_to_head);
void LL_linkage(empdata **ptr_to_head,empdata *temp);
void insert_by_id(empdata **ptr_to_head);   //--not work
void sort_by_age(empdata **ptr_to_head);
//-------------------
int main()
{
    int index,  choice;
    int range;
    empdata  *head;
    head = NULL;


    while(1)
    {
        printf(
                "---------------------------------------------------------------------------\n"
                "1. Insert	                              2. display  \n"
	       	    "3.Display_range_for_date_of_joining      4. save    \n"
                "5.load file        6.insert_by_id\n"
                "7. sort_by_age\n"
		       ">>>>>> "
                "---------------------------------------------------------------------------\n");

        scanf("%d",&choice);
        switch(choice){
            case 1: 
                    insert_emp_data(&head);
                    break;
            case 2:  
                    display_linklist(head);
                    break;
            case 3: 
                    printf("Enter range for date of joining>>>  ");
                    scanf("%d",&range);
                    display_range_ac_date(head, range);
                    
                    break;
            case 4: 
                    File_save(head);
                    break;
            case 5: 
                    backup_file_fun(&head);
                    break;
            case 6: 
                    insert_by_id(&head);
                    break;
            case 7: 
                    sort_by_age(&head);
                    // exit(-1);
                    break;
            default : 
                    printf("Enter valid menu\n");

        }

    
    }
}
 
//---------fucnction-------------------
void insert_emp_data(empdata **ptr_to_head){
    empdata *temp;
    empdata *t1;
    t1 = *ptr_to_head;

    temp = (empdata*)malloc(sizeof(empdata));
    if(temp == NULL){
        printf("malloc fail\n");
        return;
    }
    temp->prev =NULL; //prev node
    //----------input data--------------
    printf("enter name of employee  ");
    // scanf("%s",temp->name);
    scanf(" %[^\n]",temp->name);

    printf("enter name of age  ");
    scanf("%d",&(temp->age));

    printf("enter name of id  ");
    scanf("%d",&(temp->id));

    printf("enter name of address  ");
    // scanf("%s",temp->address);
    scanf(" %[^\n]",temp->address);

    printf("Enter date : DD MM YYYY  ");
    scanf("%d %d %d",&(temp->date.day),&(temp->date.month),&(temp->date.year));
    //--------------------------------------------
    //next node
    temp->next = *ptr_to_head; 
    LL_linkage(ptr_to_head,temp);
}

void LL_linkage(empdata **ptr_to_head,empdata *temp){
    // empdata *temp;
    empdata *t1;
    t1 = *ptr_to_head;

     //age / id / date of joining cant be negative or 0 condition
    if((temp->age < 0) || (temp->id < 0)
         || (temp->date.day <= 0) || (temp->date.month <= 0)
        || (temp->date.year <= 0) || (temp->date.day > 31)
        || (temp->date.month > 12) || (temp->date.year < 2000)){
            printf("you enter invalid input\n");
            free(temp);
            return;
        }
        // if head null 1st inseet node
    if(*ptr_to_head == NULL){
        *ptr_to_head = temp;
        temp->next = temp;
        temp->prev = temp;
        // (*ptr_to_head)->prev = temp;
    }
    else{
        while(t1->next != *ptr_to_head){
            t1 = t1->next;
        }

        t1->next = temp; //last 2nd next connect to last
        temp->prev = t1; // last prev connect to last 2nd
        temp->next = *ptr_to_head; //last node next connect to first
        (*ptr_to_head)->prev = temp; // 1st node prev connect to last node

    }
}

int display_linklist(empdata *ptr_to_head){
    empdata *t1;
    t1 = ptr_to_head;
    printf("head=[%p]--->\n",ptr_to_head);
    if(ptr_to_head != NULL){
        
        do{
            printf("    ---->[Prev: %p] [ID: %d] [Age: %d] "
                " [Name: %s] [Address: %s] [date: %d %d %d] [Next: %p]\n", 
               t1->prev, t1->id, t1->age,t1->name, t1->address,\
               (t1->date.day),(t1->date.month),(t1->date.year),\
               t1->next);
        
            t1 =  t1->next;
        }while(t1 != ptr_to_head);
         
    }
    else{
        printf("all node delete\n");
    }
}

void display_range_ac_date(empdata *ptr_to_head, int range){
    empdata *t1;
    t1 = ptr_to_head;

    printf("head=[%p]--->\n",ptr_to_head);

    if(ptr_to_head != NULL){
        do{
            if(t1->date.year >= range){
                printf("    ---->[Prev: %p] [ID: %d] [Age: %d] "
                        "[Name: %s] [Address: %s] [date: %d %d %d] [Next: %p]\n", 
                        t1->prev, t1->id, t1->age,t1->name, t1->address,\
                        (t1->date.day),(t1->date.month),(t1->date.year),\
                        t1->next);
            }
            t1 = t1->next;
        }while(t1 != ptr_to_head);
    }
    else printf("No node available\n");
}


int File_save(empdata *ptr_to_head){   
    if(ptr_to_head == NULL) return 0;
	FILE *fptr;
	fptr = fopen("Employee_data.txt", "w");
	if(fptr==NULL){
		perror("fopen");
		printf("errno= %d\n",errno);
	}
	empdata *t1;
    t1 = ptr_to_head;
        // fprintf(fptr, "id\tage\tname\tadd\tdate\n");
    //             fprintf(fptr, "id\tage\tdate\tname\t\tadd\n");

    // do{
        // fprintf(fptr, "%d\t%d\t", t1->id,t1->age);
        // fprintf(fptr, "%d %d %d\t",(t1->date.day),(t1->date.month),(t1->date.year));
        // fprintf(fptr, " %s\t %s \n",t1->name, t1->address);

    do{
        fprintf(fptr, "%d %d %s %s ", t1->id,t1->age,t1->name, t1->address);
        fprintf(fptr, "%d %d %d\n",(t1->date.day),(t1->date.month),(t1->date.year));
        // fprintf(fptr, "%d %d ", t1->id,t1->age);
        // fprintf(fptr, "%d %d %d",(t1->date.day),(t1->date.month),(t1->date.year));
        // fprintf(fptr, " %s\t %s\t \n",t1->name, t1->address);
        t1 = t1->next;
    }while(t1 != ptr_to_head);
	fclose(fptr);
}

int backup_file_fun(empdata **ptr_to_head)
{
    if(*ptr_to_head == NULL){
        FILE *fptr;
        fptr = fopen("Employee_data.txt", "r+");
        if(fptr==NULL)
        {
            perror("fopen");
            printf("errno= %d\n",errno);
        }

        empdata *t1;
        t1 = *ptr_to_head;
        t1 = (empdata *)malloc(sizeof(empdata));
        int id,age,d,m,y;
        char name[50],address[100];

        // while(fscanf(fptr, "%d %d %d %d %d"
        //         " %[^\t]"  
        //         " %[^\t]", 
        //         &id,&age,&d,&m,&y
        //         ,name,address) != EOF){
        // while(fscanf(fptr, "%d %d %d %d %d %[^\t] %[^\n]\n", 
        //           &id, &age, &d, &m, &y, name, address) != EOF){
        while(fscanf(fptr, "%d %d %s %s %d %d %d", &id,&age,name,
            address,&d,&m,&y) != EOF){

                t1->id = id;
                t1->age = age;
                strcpy(t1->name,name);
                strcpy(t1->address,address);
                t1->date.day = d;
                t1->date.month = m;
                t1->date.year = y;

            // fscanf(fptr, "%d %d %s %s %d %d %d", &t1->id,&t1->age,t1->name, t1->address);
            // fscanf(fptr, "%d %d %d\n",(&t1->date.day),(&t1->date.month),(&t1->date.year));
            LL_linkage(ptr_to_head,t1);
            t1 = t1->next;
        }

        display_linklist(*ptr_to_head);
    }
    else {
        printf("Already data of employees in linked list\n");
    }
	
}

void insert_by_id(empdata **ptr_to_head){
    empdata *t1; //traverse
    // empdata *t2; //prev traverse node
    empdata *temp; //user value

    temp = (empdata*)malloc(sizeof(empdata));
    if(temp == NULL){
        printf("malloc fail\n");
        return;
    }
    temp->prev =NULL; //prev node
    //----------input data-------------------------------------------------
    printf("name:  ");
    scanf(" %[^\n]",temp->name);

    printf("age:  ");
    scanf("%d",&(temp->age));

    printf("id:  ");
    scanf("%d",&(temp->id));

    printf("address:  ");
    scanf(" %[^\n]",temp->address);

    printf("Enter date : DD MM YYYY  ");
    scanf("%d %d %d",&(temp->date.day),&(temp->date.month),&(temp->date.year));
    //------------------------------------------------------------------
    //next node of temp
    temp->next = *ptr_to_head;

    t1 = *ptr_to_head;
    // t2 = NULL;

    //age / id / date of joining cant be negative or 0 condition
    if((temp->age < 0) || (temp->id < 0)
         || (temp->date.day <= 0) || (temp->date.month <= 0)
        || (temp->date.year <= 0) || (temp->date.day > 31)
        || (temp->date.month > 12) || (temp->date.year < 2000)){
            printf("you enter invalid input\n");
            free(temp);
            return;
        }
    // if head null 1st inseet node
    if(*ptr_to_head == NULL){
        *ptr_to_head = temp;
        temp->next = temp;
        temp->prev = temp; 
    }
    else if(t1->id > temp->id){
        temp->prev = (*ptr_to_head)->prev;
        temp->next = (*ptr_to_head);
        (*ptr_to_head)->prev->next = temp;
        (*ptr_to_head)->prev = temp;
        (*ptr_to_head) = temp;

        // t1->prev->next = temp;
        // t1->next = *ptr_to_head;
        // temp->prev = t1->prev;
        // *ptr_to_head = temp;    // new node becomes head
        // t1->prev = temp; 

    }
    else{
        while((t1->next != *ptr_to_head) ){     // && ((t1->prev->id < temp->id) && (t1->id > temp->id))
            // if((t1->prev->id < temp->id) && (t1->id > temp->id)){
                // t1->prev->next = temp;
                // temp->next = t1;
                // temp->prev = t1->prev;
                // t1->prev = temp;
                printf("in t1->next , t1->id = [%p][%d] \n",t1->next , t1->id );
            // }
            if(t1->next->id > temp->id){
                printf("t1->next->id > temp->id = [%d][%d] ",t1->next->id ,temp->id);
                break;
            }
            // t2 = t1;
            t1 = t1->next;
        }
        printf("in t1->next , t1->id = [%p][%d] \n",t1->next , t1->id );
            temp->next = t1->next;
            t1->next->prev = temp;
            temp->prev = t1;
            t1->next = temp;
                // t1->prev->next = temp;
                // temp->next = t1;
                // temp->prev = t1->prev;
                // t1->prev = temp;
                // printf("in if\n");
        // if(t1->next == *ptr_to_head){
        //     printf("in outer if\n");
        //     t1->next = temp; //last 2nd next connect to last
        //     temp->prev = t1; // last prev connect to last 2nd
        //     temp->next = *ptr_to_head; //last node next connect to first
        //     (*ptr_to_head)->prev = temp; // 1st node prev connect to last node
        // }

    }
}


void sort_by_age(empdata **ptr_to_head){
    empdata *t1;
    empdata *t2; 
    empdata *t3;
    t3 = NULL;
    t1 = *ptr_to_head;
    t2 = NULL;

    do{
        t2=t1;
        do{
        // printf("t1->age[%d] t3->age [%d] t2->age[%d]  ",t1->age,t3->age,t2->age);

            t3 = t2;
            t2 = t2->next;
             printf("t1->age[%d] t3->age [%d] t2->age[%d] \n ",t1->age,t3->age,t2->age);

            if((t1->age) > (t2->age)){
                t1->next = t3->next;
                t3->next = t2->next;
                t2->next =t3;

                t3->prev = t2;
                t2->prev = t1;
            }

        }while(t2->next != *ptr_to_head);
        t1 = t1->next;
    }while(t1->next != *ptr_to_head);

}
//-------------------------------------