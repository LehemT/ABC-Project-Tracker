/**
 * @file main.c
 * @author Lehem Temesgen
 * @version 10/23/2023
 * @brief A text-based project details tracker.
 *
 * This file is the main interface of the ABC project tracker. It initializes the project 
 * details such as budget and duration, using the given input. It also presents a menu so 
 * users can interact with the milestones, allowing for updates and checks on their status.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

#define NUM_MILESTONES 5
#define PATTERN_LENGTH 50
#define PATTERN_CHARACTER '-'
#define TRUE 1
#define FALSE 0

int main()
{

	milestone_t project_details;
	milestone_t details;
	milestone_t milestone;
	milestone_t milestones[6];

	printf("Welcome to ABC Project Tracker\n");
	
	printf("Enter the total project's budget: ");
	float budget = get_input_f();

	printf("Enter the total project's duration: ");
	float duration = get_input_f();

	milestones[0] = init_milestone("Planned Details", budget);
	milestones[0].time = duration; 
	number_of_employees(&milestones[0]);

	print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);

	milestones[1] = init_milestone("Technical Requirements", budget / NUM_MILESTONES);
	milestones[2] = init_milestone("System Design", budget / NUM_MILESTONES);
	milestones[3] = init_milestone("Software Development", budget / NUM_MILESTONES);
	milestones[4] = init_milestone("Testing", budget / NUM_MILESTONES);
	milestones[5] = init_milestone("Product Release", budget / NUM_MILESTONES);
	
	int exit = 0;
	while (!exit){ 
		print_menu();
		unsigned short int user_inp_usi = get_input_usi();
		switch (user_inp_usi) // switch case for user's input 0-5
		{
		case 0:
			check_project_completion(milestones, NUM_MILESTONES);
			break;
		case 1:
			print_stats(milestones[1]);
			if (milestones[1].completed == FALSE){
				update_stats(milestones,1);
				print_stats(milestones[1]);
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			else if (milestones[1].completed == TRUE){
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
				printf("Technical Requirements milestone is completed\n");
				printf("              cannot be updated!");
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			break;
		case 2:
			print_stats(milestones[2]);
			if (milestones[2].completed == FALSE){
				update_stats(milestones,2);
				print_stats(milestones[2]);
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			else if (milestones[2].completed == TRUE){
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
				printf("System Design milestone is completed\n");
				printf("         cannot be updated!");
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			break;
		case 3:
			print_stats(milestones[3]);
			if (milestones[3].completed == FALSE){
				update_stats(milestones,3);
				print_stats(milestones[3]);
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			else if (milestones[3].completed == TRUE){
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
				printf("Software Development milestone is completed\n");
				printf("            cannot be updated!");
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			break;
		case 4:
			print_stats(milestones[4]);
			if (milestones[4].completed == FALSE){
				update_stats(milestones,4);
				print_stats(milestones[4]);
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			else if (milestones[4].completed == TRUE){
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
				printf("Testing milestone is completed\n");
				printf("      cannot be updated!");
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			break;
		case 5:
			print_stats(milestones[5]);
			if (milestones[5].completed == FALSE){
				update_stats(milestones,5);
				print_stats(milestones[5]);
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			else if (milestones[5].completed == TRUE){
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
				printf("Product Release milestone is completed\n");
				printf("          cannot be updated!");
				print_pattern(PATTERN_LENGTH, PATTERN_CHARACTER);
			}
			break;
		}
	}
	return 0;
}
