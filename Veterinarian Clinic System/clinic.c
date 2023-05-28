/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Thy Nguyen
Student ID#: 105310221
Email      : nnguyen90@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "core.h"
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// main menu
void menuMain(struct ClinicData* data)
{
    int selection = 0;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection = 0;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  
            suspend();
            break;
        }
    } while (selection);
}


// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0;
    int displayNum = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            displayNum++;
        }
    }
    if (displayNum == 0)
    {
        printf("*** No records found ***");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int choose = 0;
    do
    {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n");
        printf("Selection: ");
        choose = inputInt(0, 2);
        putchar('\n');
        if (choose == 1)
        {
            searchPatientByPatientNumber(patient, max);
            putchar('\n');
            suspend();
        }
        if (choose == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            putchar('\n');
            suspend();
        }
    } while (choose != 0);
}

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int i = 0;
    int indexValue = -1;
    for (i = 0; i < max && indexValue == -1; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            indexValue = i;
        }
    }
    if (indexValue == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[indexValue].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[indexValue]);
    }
}

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    printf("Enter the patient number: ");
    int patientID = inputInt();
    putchar('\n');
    int indexValue = findPatientIndexByPatientNumber(patientID, patient, max);
    if (indexValue == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        menuPatientEdit(&patient[indexValue]);
    }
}

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    printf("Enter the patient number: ");
    int patientID = inputInt();
    int indexValue = findPatientIndexByPatientNumber(patientID, patient, max);
    if (indexValue == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        putchar('\n');
        displayPatientData(&patient[indexValue], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        int answer = inputCharOption("yn");
        if (answer == 'y')
        {
            patient[indexValue].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
        else 
        {
            printf("Operation aborted.\n\n");
        }
    }
}

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data)
{
    int i = 0, j = 0;
    int size = 0;

    size = calculateSizeOfAppArray (data ->appointments, data -> maxAppointments);
    sortingAppoint (data ->appointments, size);
    if (data)
    {
        displayScheduleTableHeader (&data ->appointments-> date, IS_ALL);
        for (i = 0; i < data->maxAppointments; i++)
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData (&data -> patients[j], &data ->appointments[i], IS_ALL);
                    break;
                }
            }
        }   
        putchar('\n\n');
    }
    else
    {
        printf("\n*** No records found ***\n");
    }
}


// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data)
{
    int i = 0, j = 0;
    int size = 0;
    struct Date input = {0};
    checkLeapYear (&input);
    putchar('\n');
    size = calculateSizeOfAppArray(data->appointments, data->maxAppointments);
    sortingAppoint(data->appointments, size);
    printf("Clinic Appointments for the Date: %04d-%02d-%02d\n", input.year, input.month, input.day);
    putchar('\n');
    displayPatientTableHeader (&input, NOT_ALL);
    for (i = 0; i < size; i++)
    {
        if (input.year == data->appointments[i].date.year && input.month == data->appointments[i].date.month && input.day == data->appointments[i].date.day)
        {
            for (j = 0; j < size; j++)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData (&data ->patients[j], &data ->appointments[i], NOT_ALL);
                }
            }
        }
    }
    putchar('\n');

}

// Add an appointment record to the appointment array
void addAppointment(struct Appointment* appointments, int maxAppointment, struct Patient* patient, int maxPatient)
{
    int i = 0;
    int size = 0;
    int flag = 1;
    size = calculateSizeOfAppArray(appointments, maxAppointment);
    if (maxAppointment > size);
    {
        printf ("Patient Number: ");
        scanf (" %d", &appointments[size].patientNumber);
        clearInputBuffer();
        if (findPatientIndexByPatientNumber(appointments[size].patientNumber, patient, maxPatient) != -1)
        {
            flag = 0;
            do
            {
                int duplicate = 0;
                checkLeapYear (&appointments[size].date);
                do
                {
                    printf ("Hour (0-23)  : ");
                    appointments[size].time.hour = inputIntRange (0, 23);
                    printf ("Minute (0-59): ");
                    appointments[size].time.min = inputIntRange(0, 59);
                    for (i = 0; i < size; i++)
                    {
                        if (appointments[size].date.year == appointments[i].date.year && 
                            appointments[size].date.month == appointments[i].date.month && 
                            appointments[size].date.day == appointments[i].date.day && 
                            appointments[size].time.hour == appointments[i].time.hour &&
                            appointments[size].time.min == appointments[i].time.min)
                        {
                            printf ("\nERROR: Appointment timeslot is not available!\n\n");
                            duplicate = 1;
                        }
                    }
                    if (duplicate == 0)
                    {
                        if (appointments[size].time.hour >= START_HOUR)
                        {
                            if (appointments[size].time.hour < END_HOUR &&
                                appointments[size].time.min >= START_MIN && appointments[size].time.min <= END_MIN &&
                                (appointments[size].time.min % INTERVAL == 0))
                            {
                                printf("\n*** Appointment scheduled! ***\n\n");
                                duplicate = 1;
                                flag = 1;
                            }
                            else if (appointments[size].time.hour == END_HOUR && appointments[size].time.min >= START_MIN &&
                                appointments[size].time.min == END_MIN)
                            {
                                printf("\n*** Appointment scheduled! ***\n\n");
                                duplicate = 1;
                                flag = 1; 
                            }
                            else
                            {
                                printf("ERROR: Time must be between %02d:%02d and %02d:%02d in %d minute intervals.\n\n", START_HOUR, START_MIN, END_HOUR, END_MIN, INTERVAL);
                            }
                        }
                        else
                        {
                            printf("ERROR: Time must be between %02d:%02d and %02d:%02d in %d minute intervals.\n\n", START_HOUR, START_MIN, END_HOUR, END_MIN, INTERVAL); 
                        }
                    }        
                } while (duplicate == 0);
            }while (flag == 0);
        }
        else
        {
            printf ("\nERROR: Patient record not found!");
        }
    }
}

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment* appointments, int maxAppointment, struct Patient* patient, int maxPatient)
{
    int index;
    char answer;
    int i;
    struct Appointment removeAppm = { 0 };
    int size = 0;
    //Calculate the size of the appoinment array
    size = calculateSizeOfAppArray(appointments, maxAppointment);
    //Sorting appointments
    sortingAppoint(appointments, size);
    printf("Patient Number: ");
    scanf(" %d", &removeAppm.patientNumber);
    clearInputBuffer();
    index = findPatientIndexByPatientNumber(removeAppm.patientNumber, patient, maxPatient);
    if (index != -1)
    {
        checkLeapYear(&removeAppm.date);
        putchar('\n');
        displayPatientData(&patient[index], FMT_FORM);
        printf("Are you sure you want to remove this appointment (y,n): ");
        answer = inputCharOption("yn");
        if (answer == 'y')
        {
            for (i = 0; i < maxAppointment; i++)
            {
                if (removeAppm.patientNumber ==
                    appointments[i].patientNumber && removeAppm.date.day == appointments[i].date.day &&
                    removeAppm.date.month == appointments[i].date.month && removeAppm.date.year ==
                    appointments[i].date.year)
                {
                    index = i;
                    break;
                }
            }
            appointments[index].patientNumber = 0;
            appointments[index].date.day = 0;
            appointments[index].date.month = 0;
            appointments[index].date.year = 0;
            appointments[index].time.hour = 0;
            appointments[index].time.min = 0;
            printf("\nAppointment record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

int calculateSizeOfAppArray(const struct Appointment* appointments, int maxAppointment)
{
    int size = 0;
    int i;
    for (i = 0; i < maxAppointment; i++)
    {
        if (appointments[i].date.day != 0)
        {
            size++;
        }
    }
    return size;
}

void checkLeapYear(struct Date* userInput)
{
    printf("Year        : ");
    scanf(" %d", &userInput->year);
    clearInputBuffer();
    printf("Month (1-12): ");
    userInput->month = inputIntRange(1, 12);
    switch (userInput->month)
    {
    case 1:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 2:
        //Check if the input year is a leap year
        if (userInput->year % 400 == 0 || userInput->year % 100 == 0 ||
            userInput->year % 4 == 0)
        {
            printf("Day (1-29)  : ");
            userInput->day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            userInput->day = inputIntRange(1, 28);
        }
        break;
    case 3:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 4:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 5:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 6:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 7:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 8:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 9:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 10:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 11:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    case 12:
        printf("Day (1-31) : ");
        userInput->day = inputIntRange(1, 31);
        break;
    default:
        inputIntRange(1, 12);
        break;
    }
}

void sortingAppoint(struct Appointment* appointments, int size)
{
    int i, j;
    struct Appointment temp;
    for (i = size - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            //Sorting by year
            if (appointments[j].date.year > appointments[j + 1].date.year)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
            //Sorting by day
            else if (appointments[j].date.year == appointments[j +
                1].date.year && appointments[j].date.day > appointments[j + 1].date.day)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
            //Sorting by hour
            else if (appointments[j].date.year == appointments[j +
                1].date.year && appointments[j].date.day == appointments[j + 1].date.day &&
                appointments[j].time.hour > appointments[j + 1].time.hour)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
            //Sorting by min
            else if (appointments[j].date.year == appointments[j +
                1].date.year && appointments[j].date.day == appointments[j + 1].date.day &&
                appointments[j].time.hour == appointments[j + 1].time.hour &&
                appointments[j].time.min > appointments[j + 1].time.min)
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }

}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    printf("Search by patient number: ");
    int patientID = inputInt();
    putchar('\n');
    int indexValue = findPatientIndexByPatientNumber(patientID, patient, max);

    if (indexValue == -1)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        displayPatientData(&patient[indexValue], FMT_FORM);
    }

}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i = 0;
    char inputPhoneNum[11] = { 0 };
    int number = 0;
    printf("Search by phone number: ");
    inputCString(inputPhoneNum, 10, 10);
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (strcmp(inputPhoneNum, patient[i].phone.number) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            number++;
        }
    }
    if (number == 0)
    {
        printf("\n*** No records found ***\n");
    }
    putchar('\n');
}

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int  i = 0;
    int maximum = patient[i].patientNumber;
    for (i = 1; i < max; i++)
    {
        if (patient[i].patientNumber > maximum)
        {
            maximum = patient[i].patientNumber;
        }
    }
    return maximum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNumber(int patientNumber, const struct Patient patient[], int max)
{
    int i = 0;
    int value = -1;
    for (i = 0; i < max && value == -1; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            value = i;
        }
    }
    return value;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: ");
    inputIntPositive(patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
    printf("*** New patient record added ***\n\n");
}

// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n");
    printf("Selection: ");
    int selection = inputInt(1, 4);
    putchar('\n');
    if (selection == 4)
    {
        strcpy(phone->description, "TBD");
        phone->description[0] = 0;
    }
    else
    {
        if (selection == 1)
        {
            strcpy(phone->description, "CELL");
        }
        if (selection == 2)
        {
            strcpy(phone->description, "HOME");
        }
        if (selection == 3)
        {
            strcpy(phone->description, "WORK");
        }
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        putchar('\n');
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* fp = fopen(datafile, "r");
    int i = 0;
    int records = 0;
    if (fp != NULL)
    {
        for (i = 0; i < max; i++)
        {
            //Check if the records are not empty and count the records
            if (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",
                &patients[i].patientNumber, patients[i].name, patients[i].phone.description,
                patients[i].phone.number) > 0)
            {
                records++;
            }
        }
        fclose(fp);
    }
    return records;
}

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int
    max)
{
    FILE* fp = fopen(datafile, "r");
    int i = 0;
    int records = 0;
    if (fp != NULL)
    {
        for (i = 0; i < max; i++)
        {
            //Check if the records are not empty and count the records
            if (fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber,
                &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day,
                &appoints[i].time.hour, &appoints[i].time.min) > 0)
            {
                records++;
            }
        }
        fclose(fp);
    }
    return records;
}