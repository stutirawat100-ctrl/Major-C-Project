#ifndef PROJECT_H
#define PROJECT_H

// Employee structure
struct Employee
{
    int id;
    char name[50];
    float salary;
    int yearsOfService;
};

// Employee functions
void addEmployee( struct Employee *e);
void displayEmployee(struct Employee e);
void saveEmployee(struct Employee e, const char *filename);
struct Employee loadEmployee(int id, const char *filename);
void displayAllEmployees(const char *filename);

// PF functions
float calculatePF(struct Employee e);

// Gratuity functions
float calculateGratuity(struct Employee e);

// Report functions
void generateRetirementReport(struct Employee e);
void generateAllRetirementReports(const char *filename);

#endif