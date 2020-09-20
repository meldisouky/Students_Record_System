#include "neededFunctions.h"

#define safeFree(p) saferFree((void*)&(p))

/** global variables **/
char* adminDefaultPassword = "1234" ;
extern student_t *studentRecord[MAX_RECORDS];
extern arrAvailableIndex[MAX_RECORDS];
static void saferFree(void ** pp);


int admin_login_check_password(char* adminPassword)
{
    /*
     * This Function to check if the entered password by the user is correct or not. 
     * it returns (1) if the password is correct and (0) if it is wrong.             
     */
    int returnedValue_checkPassword = -1;

    if (strcmp(adminPassword, adminDefaultPassword) == 0)
        returnedValue_checkPassword = 1;
    else
        returnedValue_checkPassword = 0;

    return  returnedValue_checkPassword;
}

int user_login_check_password(int id, char* userPassword)
{
    /*
     * This Function to check if the entered id and password are correct or not. 
     * it returns (1) if the id and password are correct and (0) if it is wrong. 
     */
     int returnedValue_checkPassword = -1;
     int studentIndex = student_index(id);;

     if (strcmp(studentRecord[studentIndex]->password, userPassword) == 0 && studentRecord[studentIndex]->id == id)
         returnedValue_checkPassword = 1;
     else
         returnedValue_checkPassword = 0;

    return returnedValue_checkPassword ;
}

void add_student_record(char* name, char year, char* password)
{
    /*
     * This Function to add a new record to the data structure.                  
     * it does not return any data type.                                         
     */
    int studentIndex = git_available_index();
    int studentID = id_declaration(studentIndex);
    studentRecord[studentIndex] = (student_t*)malloc(sizeof(student_t));

    studentRecord[studentIndex]->name = (void*)malloc(strlen(name) + 1);
    strcpy(studentRecord[studentIndex]->name, name);
    studentRecord[studentIndex]->password = (void*)malloc(strlen(password) + 1);
    strcpy(studentRecord[studentIndex]->password, password);
    studentRecord[studentIndex]->year = year;
    studentRecord[studentIndex]->id = studentID;
}

void modify_admin_password(char* adminNewPassword)
{
    /*
     * This Function to modify the admin password                                
     * it does not return any data type.                                         
     */
    adminDefaultPassword = adminNewPassword;
}

void modify_student_name(int id, char* newName)
{
    /*
     * This Function to modify a name of student                                 
     * it does not return any data type.                                         
     */
    int studentIndex = student_index(id);
    studentRecord[studentIndex]->name = realloc(studentRecord[studentIndex]->name,strlen(newName)+1);
    strcpy(studentRecord[studentIndex]->name, newName);
}

void modify_student_year(int id, char newYear)
{
    /*
     * This Function to modify a year of student                                 
     * it does not return any data type.                                         
     */
    int studentIndex = student_index(id);
    studentRecord[studentIndex]->year = newYear;
}

void modify_student_password(int id, char* newPassword)
{
    /*
     * This Function to modify a password of student                             
     * it does not return any data type.                                         
     */
    int studentIndex = student_index(id);
    studentRecord[studentIndex]->password = realloc(studentRecord[studentIndex]->password,strlen(newPassword)+1);
    strcpy(studentRecord[studentIndex]->password, newPassword);
}

void remove_student_record(int id)
{
    /*
     * This Function to remove a record                                          
     * it does not return any data type.                                         
     */
    int studentIndex = student_index(id);
    saferFree(studentRecord[studentIndex]->name);
    saferFree(studentRecord[studentIndex]->password);
    saferFree(studentRecord[studentIndex]);
    arrAvailableIndex[studentIndex] = 0;  //to make this index is available to be used again
}

void view_student_record(int id, const displayIntFptr display_int, const displayStringFptr display_str, const displayCharFptr display_char)
{
    /*
     * This Function to view a student record (name, ID, password, year)         
     * it does not return any data type.                                         
     */
    int studentIndex = student_index(id);
    printf("\nStudent name ::\t");
    display_str(studentRecord[studentIndex]->name);
    printf("\nStudent ID ::\t");
    display_int(studentRecord[studentIndex]->id);
    printf("\nStudent year ::\t");
    display_char(studentRecord[studentIndex]->year);
    printf("\nStudent password ::\t");
    display_str(studentRecord[studentIndex]->password);
}

void view_all_student_records(){
    /*
     * This Function to view all student record (name, ID, password, year)       
     * it does not return any data type.                                         
     */
    printf("ID                   Name                 year                 Password\n");
    for(int i = 0; i < MAX_RECORDS; i++){
        if(arrAvailableIndex[i] == 1){
            printf("%-21d%-21s%-21c%s\n",studentRecord[i]->id,studentRecord[i]->name,studentRecord[i]->year,studentRecord[i]->password);
        }
    }
}


static void saferFree(void ** pp)
{
    /*
     * This Function to remove a record safely.                                 
     * it does not return any data type.                                         
     */
    if (pp != NULL && * pp != NULL) {
        free(* pp);
        * pp = NULL;
    }
}