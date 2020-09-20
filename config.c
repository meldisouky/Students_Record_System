#include "config.h"

student_t *studentRecord[MAX_RECORDS];
int arrAvailableIndex[MAX_RECORDS] = {0};

int id_declaration(int studentIndex)
{
    /*
     * This Function to declare an ID by adding a constant to the index of the student.                    
     * it returns the ID of the student.                                                                                              
     */
    int returnedValue_studentID = -1 ;

    // NOTE: The maximum number of students is (100)
    if (studentIndex < 100)
        returnedValue_studentID = 1000149200 + studentIndex;

    return returnedValue_studentID;
}

int student_index(int studentID)
{
    /*
     * This Function to git the index of the student by passing its ID.                                         
     * it returns the index of the student which is used in the array of struct.                                
     */
    int returnedValue_studentIndex = -1 ;

    if (studentID >= 1000149200 && studentID <= 1000149299)
        returnedValue_studentIndex = studentID % 100 ;

    return returnedValue_studentIndex;
}

int git_available_index(void)
{
    /*
     * This Function to git the first available index to be used to add a new record.   
     * it returns the available index.                                                  
    */
    int returnedValue_availableIndex = -1;

    int iCounter = 0;
    for (iCounter = 0; iCounter < MAX_RECORDS; iCounter++)
    {
        if (arrAvailableIndex[iCounter] == 0)
        {
            returnedValue_availableIndex = iCounter ;
            arrAvailableIndex[iCounter] = 1;
            break;
        }
    }
    return returnedValue_availableIndex;
}

void display_integer(int numToDisplay)
{
    /*
     * This Function to display an integer.                                             
     * it returns no thing.                                                             
     */
    printf("%d\n", numToDisplay);
}

void display_string(char* stringToDisplay)
{
    /*
     * This Function to display a string.                                               
     * it returns no thing.                                                             
    */
    printf("%s\n", stringToDisplay);
}

void display_char(char charToDisplay)
{
    /*
     * This Function to display a character.                                            
     * it returns no thing.                                                             
     */
    printf("%c\n", charToDisplay);
}