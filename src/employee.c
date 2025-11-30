// --------------------- To Take Inputs of Employee's Details ----------------------

#include "project.h"
#include <stdio.h>
#include <string.h>

void addEmployee(struct Employee *e)
{
    printf(" \nEnter Employee's Details: \n");
    printf("Employee ID: ");
    scanf("%d", &e->id);
    getchar();  // clear leftover newline

    printf("Employee Name: ");
    fgets(e->name, sizeof(e->name), stdin);

    // Remove trailing newline from name
    size_t len = strlen(e->name);
    if (len > 0 && e->name[len - 1] == '\n') 
    {
        e->name[len - 1] = '\0';
    }

    printf("Employee Salary: ");
    scanf("%f", &e->salary);
    printf("Employee Years of Service: ");
    scanf("%d", &e->yearsOfService);
}

// Save one employee to file
void saveEmployee(struct Employee e, const char *filename) 
{
    FILE *fp = fopen(filename, "ab");  // append mode
    if (fp == NULL) 
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    fwrite(&e, sizeof(struct Employee), 1, fp);
    fclose(fp);
}

// Load employee by ID
struct Employee loadEmployee(int id, const char *filename) 
{
    struct Employee e;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) 
    {
        printf("Error: Could not open file %s\n", filename);
        e.id = -1;  // signal not found
        return e;
    }

    while (fread(&e, sizeof(struct Employee), 1, fp)) 
    {
        if (e.id == id) 
        {
            fclose(fp);
            return e;
        }
    }

    fclose(fp);
    e.id = -1;  // signal not found
    return e;
}

// Display all employees stored in file
void displayAllEmployees(const char *filename) 
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) 
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    struct Employee e;
    printf("\n===== Employee List =====\n");
    while (fread(&e, sizeof(struct Employee), 1, fp)) 
    {
        displayEmployee(e);  // reuse your single-employee display function
    }
    fclose(fp);
}

#include <stdio.h>
#include "project.h"

// Display details of one employee
void displayEmployee(struct Employee e) 
{
    printf("\n-------------------------------------\n");
    printf(" Employee ID       : %d\n", e.id);
    printf(" Name              : %s\n", e.name);
    printf(" Salary            : %.2f\n", e.salary);
    printf(" Years of Service  : %d\n", e.yearsOfService);
    printf("-------------------------------------\n");
}

