/*
Q2. Create an employee structure with the following members
empid, employee name, salary, year of joining etc.

Accept the data for certain no. o of employees and find their total,
average, max, min salary.

Also find out the employees with maximum, minimum service,use a
function to find service for each employee element in the array.
*/

#include<stdio.h>
#include<time.h>
#include <string.h>
#define   current_year  2026
//--------structure---------------
struct date_of_joining{
    int day;
    int month;
    int year;
}date_of_joining;
struct employee{
    int empid;
    char employee_name[10];
    float salary;
    struct  date_of_joining date_of_joining;
    
    int service;
    // service = current_year - emp[i].date_of_joining.year;
    // struct date_of_joining.day;
    // int date_of_joining.month;
    // struct date_of_joining.year;
};
//---------------------------------------------
//---------------function-------------------
void scan_employee_data(int, struct employee emp[]);
int print_data(int, struct employee emp[]);
int average_salary_of_employee(int, struct employee emp[]);
int max_salary_of_employee(int, struct employee emp[]);
int min_salary_of_employee(int, struct employee emp[]);
//-----------------------------------------

int main(){
    int number_of_employee;
    int average_salary, max_salary, min_salary;
    printf("Enter Number of employee\n");
    scanf("%d", &number_of_employee);
    struct employee emp[number_of_employee];

     scan_employee_data(number_of_employee,  emp);
     print_data(number_of_employee,  emp);
     average_salary_of_employee(number_of_employee,  emp);
     max_salary_of_employee(number_of_employee,  emp);
     min_salary_of_employee(number_of_employee,  emp);
  
    int max_service_surve, min_service_surve;
    int id_max,id_min;
    char name_max[20], name_min[20];
    for(int i=0; i<number_of_employee; i++){
        
        emp[i].service = current_year - emp[i].date_of_joining.year;
        if(max_service_surve < emp[i].service){
            max_service_surve = emp[i].service;
            id_max =emp[i].empid;
            strcpy(name_max, emp[i].employee_name);
        }
         if( emp[i].service < emp[i+1].service){
            min_service_surve = emp[i].service;
            id_min =emp[i].empid;
            strcpy(name_min, emp[i].employee_name);
        }
    }
    printf("max service surve :- Name-%s . ID- %d . service - %d years",name_max, id_max, max_service_surve );
    printf("min service surve :- Name-%s . ID- %d . service - %d years",name_min, id_min, min_service_surve );



}

void scan_employee_data(int number_of_employee, struct employee emp[number_of_employee]){
    for(int i=0; i<number_of_employee; i++){
        printf("Enter detail of employee %d\n",i+1);
        printf("Enter employee id\n");
        scanf("%d", &emp[i].empid);
        // printf("id=%d\n", emp[i].empid);
        printf("Enter employee name\n");
        scanf("%s", &emp[i].employee_name);
        printf("Enter employee salary\n");
        scanf("%f", &emp[i].salary);
        printf("Enter date of joining dd mm yy");
        scanf("%d %d %d", &emp[i].date_of_joining.day, &emp[i].date_of_joining.month, &emp[i].date_of_joining.year);
    }
}

int print_data(int number_of_employee, struct employee emp[number_of_employee]){
    for(int i=0; i<number_of_employee; i++){
        printf(" detail of employee %d\n",i+1);
        
        printf("id=%d\n", emp[i].empid);
        printf("employee_name=%s\n", emp[i].employee_name);
        printf("salary=%f\n", emp[i].salary);
        printf("dd mm yy = %d %d %d\n", emp[i].date_of_joining.day,emp[i].date_of_joining.month,emp[i].date_of_joining.year);
        printf("----------------\n");
    }
}

int average_salary_of_employee(int number_of_employee, struct employee emp[number_of_employee]){
    float average_salary=0, sum_of_salary=0;    
    for(int i=0; i<number_of_employee; i++){
        sum_of_salary += emp[i].salary;
    }
    average_salary = ((sum_of_salary)/(number_of_employee));
    printf("Average salary = %f\n", average_salary);
}

int max_salary_of_employee(int number_of_employee, struct employee emp[number_of_employee]){
    float max_salary = 0;
        for(int i=0; i<number_of_employee; i++){
            if(max_salary < emp[i].salary){
                max_salary = emp[i].salary;
            }
        }
        printf("max_salary = %f\n",max_salary);
}


int min_salary_of_employee(int number_of_employee, struct employee emp[number_of_employee]){
    float min_salary = 0;
    for(int i=0; i<number_of_employee; i++){
        if(emp[i].salary < emp[i+1].salary){
            min_salary = emp[i].salary;
        }
    }
        printf("min_salary = %f\n",min_salary);
}