//----------------------------------- Main Function --------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "project.h"

int main()
{
    int choice;
    struct Employee emp;
    const char *filename = "docs/employees.dat";
    
    while (1) 
    {

        printf("\n===== Employee Retirement Benefit Management System =====\n\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Generate Retirement Report for One Employee\n");
        printf("4. Generate Retirement Reports for All Employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addEmployee(&emp);                  // take input
                saveEmployee(emp, filename);        // save to file
                break;

            case 2:
                displayAllEmployees(filename);      // show all employees
                break;

            case 3: 
            {
                int id;
                printf("Enter Employee ID to generate report: ");
                scanf("%d", &id);
                emp = loadEmployee(id, filename);   // load employee by ID
                generateRetirementReport(emp);      // single report
                break;
            }

            case 4:
                generateAllRetirementReports(filename); // reports for all
                break;

            case 5:
                printf(" \n===== Thank You For Using Employee Retirement Benefit Management System =====\n ");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}