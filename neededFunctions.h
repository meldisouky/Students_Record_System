#ifndef STUDENTDATABASESYSTEM_NEEDEDFUNCTIONS_H
#define STUDENTDATABASESYSTEM_NEEDEDFUNCTIONS_H

#include "config.h"

/** Login Functions **/
int admin_login_check_password(char* adminPassword);
int user_login_check_password(int id, char* userPassword);

/** adding Function **/
void add_student_record(char* name, char year, char* password);

/** modify Functions **/
void modify_admin_password(char* adminNewPassword);
void modify_student_name(int id, char* newName);
void modify_student_year(int id, char newYear);
void modify_student_password(int id, char* newPassword);

/** remove Functions **/
void remove_student_record(int id);
void view_all_student_records(void);

/** view Function **/
void view_student_record(int id, const displayIntFptr display_int, const displayStringFptr display_str, const displayCharFptr display_char);

#endif //STUDENTDATABASESYSTEM_NEEDEDFUNCTIONS_H