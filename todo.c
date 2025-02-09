/*
Description : A simple todo program, which uses 2d arrays to store tasks
Author: Akshat Pasbola
Date: 09/02/2025
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASKS 100
#define MAX_TASK_LEN 256

//Add string in form of character to a 2d array.
void add_task(char tasks[][MAX_TASK_LEN], int *task_count);

//Iterates through the rows of the 2d array.
void list_tasks(char tasks[][MAX_TASK_LEN], int *task_count);

int main(){
    
    char tasks[MAX_TASKS][MAX_TASK_LEN];
    int task_count = 0;
    int choice;

    while(1){
        printf("\n1. Add Task\n2. List Tasks\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice){
            case 1:
                add_task(tasks, &task_count);
                break;
            case 2:
                list_tasks(tasks,&task_count);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice");
        }

    }

    return 0;
}

void add_task(char tasks[][MAX_TASK_LEN], int *task_count){

    if (*task_count >= MAX_TASKS){
        printf("\nTask list is full!\n");
        return;
    }

    printf("\nEnter your task: ");

    //Using fgets to input a string of characters on one row.
    //One column is a character.
    fgets(tasks[*task_count], MAX_TASK_LEN, stdin);
    tasks[*task_count][strcspn(tasks[*task_count], "\n")] = '\0';
    (*task_count)++;
}

void list_tasks(char tasks[][MAX_TASK_LEN], int *task_count){
    if (*task_count == 0){
        printf("\nno tasks\n");
        return;
    } 

    printf("\nYour Tasks:\n");

    //Iterating through rows of tasks.
    for (int i = 0; i < *task_count; i++){
        printf("%d. %s\n", i+1, tasks[i]);
    }
}