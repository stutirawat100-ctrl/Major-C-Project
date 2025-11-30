// --------------------- To Calculate (PF) Providient Fund ----------------------

#include "project.h"
#include <stdio.h>

float calculatePF(struct Employee e)
{
    /*
      PF is generally calculated as 12% of basic salary per month.
      For simplicity in this project:
      PF = (12% of monthly salary) × (years of service × 12 months)
    */

    // Compute PF (Providient Fund)
    float pf = (0.12 * e.salary)*(e.yearsOfService * 12);

    // Return PF 
    return pf;

}
