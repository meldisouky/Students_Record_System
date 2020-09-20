#ifndef STUDENTDATABASESYSTEM_SYSTEM_H
#define STUDENTDATABASESYSTEM_SYSTEM_H

#include "config.h"
#include "neededFunctions.h"

#define MAXIMUM_PASSWORD_SIZE (20)
#define MAXIMUM_NAME_SIZE (20)

/** Type Definition **/
typedef int (*loginNextScreenFptr)(int);

/** Main Function **/
void system_update(void);

/** Choosing Mode **/
int choose_mode(void);

/** Admin mode Functions **/
void admin_login();
int admin_choices_display(void);
void admin_choices(int choice);

/** User mode Functions **/
void user_login();
int user_choices_display(void);
void user_choices(int choice);

/** Next step after each function **/
void functions_nextStep(int admin1_user2);
#endif //STUDENTDATABASESYSTEM_SYSTEM_H