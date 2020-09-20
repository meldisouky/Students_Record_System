#include "system.h"

static int numOfTry = 3 ;
int firstTime[10] = {0};
// (0) -> Modify admin password -- (1) -> Add new record -- (2) -> Modify student name
// (3) -> Modify student password -- (4) -> Modify your password(user)

void system_update(void)
{
    /*
     * This Function to handle all the system.                                        
     * it returns no thing.                                                           
     */
    system("cls");  //to clear the screen
    /** choosing the mode **/
    int systemMode = choose_mode();
    if (systemMode == 1)
    {
        admin_login();
    }
    else if (systemMode == 2)
    {
        user_login();
    }
    else
    {
        printf("\nError :: You have to choose a number from the above list");
        system_update();
    }
}

int choose_mode(void)
{
    /*
     * This Function to design the entry screen and make the user determine the mode. 
     * it returns (1) if admin mode, (0) if user mode.                                
     */
    int returnedValue_mode = 0;

    /** presented screen **/
    printf("\n\t*** Welcome in our simple project \"student record database\" ***");
    printf("\n\t\t\t Done by: Mohamed Elsaeid");
    printf("\n\nChoose the desired mode, please ... ");
    printf("\n1. Admin Mode.");
    printf("\n2. User Mode.");

    /** get the user choice **/
    printf("\nYour choice is :: ");
    scanf("%d", &returnedValue_mode);

    return returnedValue_mode;
}

void admin_login()
{
    /*
     * This Function to design admin login screen and check if the password is correct or not. 
     * it returns (1) if admin password is correct, (0) if admin password is not correct.      
     */
    system("cls");  //to clear the screen

    /** presented screen **/
    printf("\n\t*** Admin mode ***");
    printf("\n\nLogin as an admin ... ");
    printf("\nNote: IF it is your first time to login, your password is 1234 ");

    /** get the user password **/
    printf("\nEnter your password :: ");
    char enteredPassword[MAXIMUM_PASSWORD_SIZE];
    scanf("%s", enteredPassword);
    int login_check = admin_login_check_password(enteredPassword);
    if (login_check == 1)
    {
        system("cls");  //to clear the screen
        numOfTry = 3;
        int choice = admin_choices_display();
        admin_choices(choice);
    }
    else if (login_check == 0)
    {
        printf("\nWrong password ... ");
        if (numOfTry > 0)
        {
            printf("\nYou have available %d try(tries)", numOfTry);
            printf("\npress any kay to continue ... ");
            char enteredChar = 0;
            fflush(stdin);
            if (scanf("%c", &enteredChar))
            {
                numOfTry--;
                admin_login();
            }
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        printf("\nError :: There is an error in admin_login function");
        exit(0);
    }
}

void user_login()
{
    /*
     * This Function to design user login screen and check if the password is correct or not. 
     * it returns (1) if user password is correct, (0) if admin password is not correct.      
     */
    system("cls");  //to clear the screen

    /** presented screen **/
    printf("\n\t*** User mode ***");
    printf("\n\nLogin as a user ... ");
    printf("\nNote: IF it is your first time to login, your password is 1234 ");

    /** get the user id **/
    printf("\nEnter your iD :: ");
    int enteredID = 0;
    scanf("%d", &enteredID);

    /** get the user password **/
    printf("\nEnter your password :: ");
    char enteredPassword[MAXIMUM_PASSWORD_SIZE];
    scanf("%s", enteredPassword);
    int login_check = user_login_check_password(enteredID, enteredPassword);
    if (login_check == 1)
    {
        system("cls");  //to clear the screen
        numOfTry = 3;
        int choice = user_choices_display();
        user_choices(choice);
    }
    else if (login_check == 0)
    {
        printf("\nWrong password ... ");
        if (numOfTry > 0)
        {
            printf("\nYou have available %d try(tries)", numOfTry);
            printf("\npress any kay to continue ... ");
            char enteredChar = 0;
            fflush(stdin);
            if (scanf("%c", &enteredChar))
            {
                numOfTry--;
                user_login();
            }
        }
    }
    else
    {
        printf("\nError :: There is an error in user_login function");
        exit(0);
    }
}

int admin_choices_display(void)
{
    /*
     * This Function to show admin available function.                                
     * it returns the chosen number (Function).                                       
    */
    int returnedValue_choice = 0;
    system("cls");  //to clear the screen
    printf("\nAdmin Choices ... ");
    printf("\n1. Modify admin password.");
    printf("\n2. Add new record.");
    printf("\n3. Remove record.");
    printf("\n4. View record.");
    printf("\n5. View all records.");
    printf("\n6. Modify student name.");
    printf("\n7. Modify student password.");
    printf("\n8. Modify student year.");
    printf("\n9. Return to the entry screen.");
    printf("\n10. Exit.");

    printf("\n\nEnter your choice :: ");
    scanf("%d", &returnedValue_choice);

    return returnedValue_choice;
}

void admin_choices(int choice)
{
    /*
     * This Function to access desired function from admin.                           
     * it returns no thing.                                                           
     */
    if (choice == 1)
    {
        system("cls");  //to clear the screen
        char* adminNewPassword;
        if (firstTime[0] == 1)
        {
            free(adminNewPassword);
        }
        adminNewPassword = (char *)malloc(MAXIMUM_PASSWORD_SIZE);
        printf("\nEnter a new password :: ");
        fflush(stdin);
        scanf("%s", adminNewPassword);
        modify_admin_password(adminNewPassword);
        firstTime[0] = 1;
        functions_nextStep(1);
    }
    else if (choice == 2)
    {
        system("cls");  //to clear the screen
        char* name;
        char year;
        if (firstTime[1] == 1)
        {
            free(name);
        }
        name = (char *)malloc(MAXIMUM_NAME_SIZE);
        printf("\nEnter student name :: ");
        fflush(stdin);
        scanf("%s", name);
        printf("\nEnter student year :: ");
        fflush(stdin);
        scanf("%c", &year);
        add_student_record(name, year, "1234");
        firstTime[1] = 1;
        functions_nextStep(1);
    }
    else if (choice == 3)
    {
        system("cls");  //to clear the screen
        int studentID = 0;
        printf("\nEnter Student ID :: ");
        scanf("%d", &studentID);
        remove_student_record(studentID);
        functions_nextStep(1);
    }
    else if (choice == 4)
    {
        system("cls");  //to clear the screen
        int studentID = 0;
        printf("\nEnter Student ID :: ");
        scanf("%d", &studentID);
        view_student_record(studentID, display_integer, display_string, display_char);
        functions_nextStep(1);
    }
    else if (choice == 5)
    {
        system("cls");  //to clear the screen
        view_all_student_records();
        functions_nextStep(1);
    }
    else if (choice == 6)
    {
        system("cls");  //to clear the screen
        int studentID = 0;
        char* newName;
        if (firstTime[2] == 1)
        {
            free(newName);
        }
        printf("\nEnter Student ID :: ");
        scanf("%d", &studentID);
        newName = (char *)malloc(MAXIMUM_NAME_SIZE);
        printf("\nEnter student new name :: ");
        fflush(stdin);
        scanf("%s", newName);
        modify_student_name(studentID, newName);
        firstTime[2] = 1;
        functions_nextStep(1);
    }
    else if (choice == 7)
    {
        system("cls");  //to clear the screen
        int studentID = 0;
        char* newPassword;
        if (firstTime[3] == 1)
        {
            free(newPassword);
        }
        printf("\nEnter Student ID :: ");
        scanf("%d", &studentID);
        newPassword = (char *)malloc(MAXIMUM_PASSWORD_SIZE);
        printf("\nEnter student new password :: ");
        fflush(stdin);
        scanf("%s", newPassword);
        modify_student_password(studentID, newPassword);
        firstTime[3] = 1;
        functions_nextStep(1);
    }
    else if (choice == 8)
    {
        system("cls");  //to clear the screen
        int studentID = 0;
        char newYear;
        printf("\nEnter Student ID :: ");
        scanf("%d", &studentID);
        printf("\nEnter student new year :: ");
        fflush(stdin);
        scanf("%c", &newYear);
        modify_student_year(studentID, newYear);
        functions_nextStep(1);
    }
    else if (choice == 9)
    {
        system_update();
    }
    else if (choice == 10)
    {
        exit(0);
    }
    else
    {
        printf("\nError :: There is an error in admin_choices function");
        exit(0);
    }
}

int user_choices_display(void)
{
    /*
     * This Function to show user available function.                                 
     * it returns the chosen number (Function).                                       
     */
    int returnedValue_choice = 0;
    system("cls");  //to clear the screen

    printf("\nUser Choices ... ");
    printf("\n1. Modify your password.");
    printf("\n2. View your record.");
    printf("\n3. Return to the entry screen.");
    printf("\n4. Exit.");

    printf("\n\nEnter your choice :: ");
    scanf("%d", &returnedValue_choice);

    return returnedValue_choice;
}

void user_choices(int choice)
{
    /*
     * This Function to access desired function from user.                            
     * it returns no thing.                                                           
     */
    if (choice == 1)
    {
        int studentID = 0;
        char* newPassword;
        if (firstTime[4] == 1)
        {
            free(newPassword);
        }
        printf("\nEnter your ID :: ");
        scanf("%d", &studentID);
        newPassword = (char *)malloc(MAXIMUM_PASSWORD_SIZE);
        printf("\nEnter new password :: ");
        fflush(stdin);
        scanf("%s", newPassword);
        modify_student_password(studentID, newPassword);
        firstTime[4] = 1;
        functions_nextStep(2);
    }
    else if (choice == 2)
    {
        int studentID = 0;
        printf("\nEnter Student ID :: ");
        scanf("%d", &studentID);
        view_student_record(studentID, display_integer, display_string, display_char);
        functions_nextStep(2);
    }
    else if (choice == 3)
    {
        system_update();
    }
    else if (choice == 4)
    {
        exit(0);
    }
    else
    {
        printf("\nError :: There is an error in user_choices function");
        exit(0);
    }
}

void functions_nextStep(int admin1_user2)
{
    /*
     * This Function to determine the next step after ending the function.            
     * it returns no thing.                                                           
     */
    printf("\n\n1. Return to the previous page.");
    printf("\n2. Return to entry page.");
    printf("\n3. Exit.");

    int enteredInt = 0;
    printf("\nyour choice :: ");
    scanf("%d", &enteredInt);

    if (enteredInt == 1)
    {
        if (admin1_user2 == 1)
        {
            int enteredIntChoice = admin_choices_display();
            admin_choices(enteredIntChoice);
        }
        else if (admin1_user2 == 2)
        {
            int enteredIntChoice = user_choices_display();
            user_choices(enteredIntChoice);
        }
        else
        {
            printf("\nError :: There is an error in functions_nextStep function");
            exit(0);
        }
    }
    else if (enteredInt == 2)
    {
        system_update();
    }
    else if (enteredInt == 3)
    {
        exit(0);
    }
    else
    {
        printf("\nError :: There is an error in functions_nextStep function");
        exit(0);
    }
}