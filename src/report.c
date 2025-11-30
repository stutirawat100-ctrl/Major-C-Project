// --------------------- To Display Retirement Report ----------------------

#include "project.h"
#include <stdio.h>

void generateRetirementReport(struct Employee e)
{
    float g = calculateGratuity(e);
    float pf = calculatePF(e);

    float totalBenefits = g + pf;

    printf("\n=======================================================\n");
    printf("        Retirement Report for Employee ID: %d\n", e.id);
    printf("\n Name: %s\n", e.name);
    printf(" Salary: %.2f\n", e.salary);
    printf(" Years of Service: %d\n", e.yearsOfService);
    printf("\n-------------------------------------\n\n");
    printf(" Provident Fund (PF): %.2f\n", pf);
    printf(" Gratuity: %.2f\n", g);
    printf(" Total Retirement Benefits: %.2f\n", totalBenefits);
    printf("\n=======================================================\n\n");

}

// Function to generate retirement reports for all employees stored in a file
void generateAllRetirementReports(const char *filename) 
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) 
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    struct Employee e;
    while (fread(&e, sizeof(struct Employee), 1, fp)) 
    {
        generateRetirementReport(e);
    }

    fclose(fp);
}