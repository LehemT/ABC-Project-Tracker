/**
 * @file data_structures.h
 * @author Lehem Temesgen
 * @version 10/23/2023
 * @brief A text-based project details tracker.
 *
 * This header file contains the definition of the data structure 
 * which holds information about each milestone including its name, 
 * cost & time, number of employees needed, and completion status.
*/
#include <stdlib.h>   
#include <stdio.h>    
#include <stdbool.h>

typedef struct milestone {
    char name[100];
    float cost, time;
    unsigned short int num_employees;
    _Bool completed; 
}milestone_t;
