// --------------------- To Calculate Gratuity ----------------------

#include "project.h"
#include <stdio.h>

float calculateGratuity(struct Employee e)
{
    /*
      Standard gratuity formula (India):
      Gratuity = (15 * last drawn salary * years of service) / 26
      - Salary here is taken as monthly basic salary
      - 26 represents the number of working days in a month
    */

    float g=1;
    g = (15 * e.salary * e.yearsOfService)/26;      // Compute Gratuity

    // Return Gratuity 
    return g;

}
