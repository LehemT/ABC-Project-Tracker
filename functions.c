/**
 * @file functions.c
 * @author Lehem Temesgen
 * @version 10/23/2023
 * @brief A text-based project details tracker.
 *
 * This file contains the implementations the functions used to manage 
 * project milestones, such as calculating the number of employees needed, 
 * updating milestone statistics, and checking project completion. 
*/

#include <stdlib.h>   
#include <stdio.h>    
#include <stdbool.h>

#include <math.h>
#include <string.h>
#include"functions.h"

#define NUM_MILESTONES 5
#define  HOURS_PER_WEEK 40
#define SALARY_PER_HOUR 25
#define PATTERN_LENGTH 50
#define PATTERN_CHARACTER '-'
#define TRUE 1
#define FALSE 0

/*
   Calculate number of employees needed for the project based on cost and time
*/
void number_of_employees(milestone_t *project_details)
{
   float salary;
   unsigned short int employees;

   salary = project_details->time * HOURS_PER_WEEK * SALARY_PER_HOUR; // calculate employees needed
   employees = (int)round(project_details->cost / salary);
   printf("The planned number of employees needed is: %hu", employees);
   printf("\n");
   project_details->num_employees = employees;
}

/* 
   Initialize milestones with names and planned budget
*/
milestone_t init_milestone(char stage_name[], float assigned_budget)
{
   milestone_t milestone;

   strcpy(milestone.name, stage_name);
   milestone.cost = assigned_budget;
   milestone.num_employees = 0;
   milestone.time = 0;
   milestone.completed = 0;

   return milestone;
}


/* 
   Get unsigned short integer user input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
unsigned short int get_input_usi(void){
   unsigned short int user_inp_usi;
   printf("\nYour choice is: ");
	scanf(" %hu", &user_inp_usi);

   while (user_inp_usi < 0 || user_inp_usi > NUM_MILESTONES){
      print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
      printf("The value you entered is wrong.\nEnter a value between 0 and 5: ");
	   scanf(" %hu", &user_inp_usi);
      }

   return user_inp_usi;
}


/*
   Get user float input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
float get_input_f(void)
{
   float user_inp_f;
   scanf("%f", &user_inp_f);

   while (user_inp_f < 0){
      print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
      printf("\nThe value you entered is wrong. \n Enter a positive value: ");
      scanf("%f", &user_inp_f);
   }
   
   return user_inp_f;
}


/* 
   Print menu with a list of milestones/options for the user to choose from
*/
void print_menu(void){
   char* milestone_options[NUM_MILESTONES] = {
        "1. Technical Requirements",
        "2. System Design",
        "3. Software Development",
        "4. Testing",
        "5. Product Release"
    };

   printf("\nWhich milestone do you want to update? (0 to exit)\n");
   for (int i = 0; i < NUM_MILESTONES; i++){
      printf("%s",milestone_options[i]);
      printf("\n");
   }
}


/*
   Print out current stats of each milestone/project.
*/
void print_stats(milestone_t details){
   printf("\n------------ Milestone Stats --------------\n");
   printf("Below is \"%s\" current stats:", details.name);
   print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
   printf("\nActual time: %.2f weeks\n", details.time);
   printf("Actual number of employees: %d\n", details.num_employees);
   printf("Actual cost: %.2f$\n", details.cost);
   printf("Completed: %s\n", details.completed ? "Yes" : "No");  
}


/*
   Update the stats of the milestones, not the project.
*/
void update_stats(milestone_t milestone_array[], int milestone_num){
   float actual_time;
   unsigned short int actual_employees;
   char completion;

   printf("\n-------------- Update Stats ----------------\n\n");
   printf("Enter the milestone's actual time: ");
   scanf("%f", &actual_time);

   printf("Enter the milestone's actual number of employees: ");
   scanf(" %hu", &actual_employees);

   milestone_array[milestone_num].cost = actual_employees * actual_time * HOURS_PER_WEEK * SALARY_PER_HOUR; // calculate actual cost
   printf("Actual cost: $%.2f", milestone_array[milestone_num].cost);

   printf("\nIs this milestone complete?: (Y/N)");
   scanf(" %c", &completion);

   if (completion == 'Y'){
      milestone_array[milestone_num].completed = TRUE;
   } else if (completion == 'N') {
      milestone_array[milestone_num].completed = FALSE;
   } else {
      printf("Invalid input!\n");
      printf("Is this milestone complete?: (Y/N)");
      scanf(" %c", &completion);   
   }
   printf("Stats Updated!\n");

   milestone_array[milestone_num].time = actual_time;
   milestone_array[milestone_num].num_employees = actual_employees;
}

/*
   Check if all milestones are completed or not. If completed, updated the project's details to completed.
*/
void check_project_completion(milestone_t milestone_array[], int num_milestones){
   float total_cost = 0;
   unsigned short int milestones_completed = 1;
   char choice;
   milestone_t project_details;
   milestone_t milestone;
   milestone_t details;
   milestone_t milestones[6];

   // loop to check if all milestones are completed
   for (int i = 1; i <= num_milestones; i++) {
      total_cost += milestone_array[i].cost;
      if (!milestone_array[i].completed) {
         milestones_completed = 0;
      }
   }
   
   if (milestones_completed){ // milestones are completed
      print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
      printf("----------- Final Project's Performance -----------");
      print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);

      if (total_cost <= milestone_array[0].cost){
         printf("\nThe project's cost is below budget!");
      }
      else {
         printf("\nThe project's cost is above budget!");
      }
      printf("\nPlanned budget: $%.2f", milestone_array[0].cost);
      printf("\nActual cost: $%.2f", total_cost);
      printf("\n");
      print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
      printf("--- The program will quit now! Goodbye! ---");
      print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
   }
   else { // milestones aren't completed

      print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
      printf("------------- Project's Performance --------------");
      print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
      print_stats(milestone_array[0]); 
      printf("Do you want to finish the remaining milestones? (Y/N)");
      scanf(" %c", &choice);

      if (choice == 'Y'){ // user selects Y
         
      }
      else if (choice == 'N'){ // user selects N
         print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
         printf("----------- Final Project's Performance -----------");
         print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);

         if (total_cost <= milestone_array[0].cost){
            printf("\nThe project's cost is below budget!");
         }
         else {
            printf("\nThe project's cost is above budget!");
         }
         printf("\nPlanned budget: $%.2f", milestone_array[0].cost);
         printf("\nActual cost: $%.2f", total_cost);
         printf("\n");
         print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
         printf("--- The program will quit now! Goodbye! ---");
         print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
      }
   }

}

// prints a pattern of chosen length and character
void print_pattern(unsigned int length, char character){
   printf("\n");
   for(int i = 0; i < length; i++){
      printf("%c", character);
   }
   printf("\n");
}

