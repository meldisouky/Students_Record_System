#ifndef STUDENTDATABASESYSTEM_CONFIG_H
#define STUDENTDATABASESYSTEM_CONFIG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS (100)  // That is the maximum number of student that be recorded

/** Type Definitions **/
typedef struct _student
{
    char* name;
    char* password;
    int id;
    char year;
}student_t;
typedef void (*displayIntFptr)(int);  
typedef void (*displayStringFptr)(char*);
typedef void (*displayCharFptr)(char); 

/** Handling IDs **/
int id_declaration(int studentIndex);
int student_index(int id);
int git_available_index(void);

/** Displaying Functions **/
void display_integer(int numToDisplay);
void display_string(char* stringToDisplay);
void display_char(char charToDisplay);


#endif //STUDENTDATABASESYSTEM_CONFIG_H