// Nama : Adiguna Sanjaya Ligawan
// NIM : 2702261422

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define clr system("clear")

typedef struct Patient {
    char name[26];
    char id[6];
    int age;
    char symptoms[101];
    char code[6]; // "Red", "Yellow", or "Green"
    struct Patient *next;
    int priority; // 1 untuk Green, 2 untuk Yellow, 3 untuk Red
} Patient;

Patient *head = NULL;

// int isValidInput(char *input, int minLength, int maxLength) {
//     int length = strlen(input);
//     return length >= minLength && length <= maxLength;
// }
int ifIdExist(char *id) {
    Patient *current = head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}   

void insertPatient(Patient *newPatient) {
    if (head == NULL) {
        head = newPatient;
        newPatient->next = NULL;
        return;
    }
    if (newPatient->priority < head->priority) {
        newPatient->next = head;
        head = newPatient;
        return;
    }
    Patient *current = head;
    while (current->next != NULL && current->next->priority <= newPatient->priority) {
        current = current->next;
    }
    newPatient->next = current->next;
    current->next = newPatient;
}

void insertPatientUI() {

    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    if (newPatient == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }


    do {
        printf("Input patient name[4-25]: ");
        scanf(" %[^\n]", newPatient->name);
    } while (strlen(newPatient->name) < 4 || strlen(newPatient->name) > 25);


    do {
        printf("Input patient age[0-150]: ");
        scanf("%d", &newPatient->age);
    } while (newPatient->age < 0);

    getchar(); 

    do {
        printf("Input patient ID[5]: ");
        scanf("%s", newPatient->id);
        if (ifIdExist(newPatient->id) == 1) {
            printf("ID already exists.\n");
        }
    } while (strlen(newPatient->id) != 5 || ifIdExist(newPatient->id) == 1);

    
    do {
        printf("Input description[>= 6]: ");
        scanf(" %[^\n]", newPatient->symptoms);
    } while (strlen(newPatient->symptoms) < 6 || strlen(newPatient->symptoms) > 100);


    do {
        printf("Input code [Red|Yellow|Green]: ");
        scanf(" %[^\n]", newPatient->code);
    } while (strcmp(newPatient->code, "Red") != 0 && strcmp(newPatient->code, "Yellow") != 0 && strcmp(newPatient->code, "Green") != 0);


    if (strcmp(newPatient->code, "Red") == 0) {
        newPatient->priority = 3;
    } else if (strcmp(newPatient->code, "Yellow") == 0) {
        newPatient->priority = 2;
    } else {
        newPatient->priority = 1;
    }

    insertPatient(newPatient);
    printf("Insert Success!\n");
    printf("Press Enter to continue...");
    while (getchar() != '\n'); 
    getchar(); 
}


void viewList() {
    Patient *current = head;
    if (current == NULL) {
        printf("There is no queue yet!\n");
        printf("Press Enter to continue...");
        while (getchar() != '\n'); 
        return;
    }

    int count = 0;
    Patient *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }


    Patient *patients[count];
    

    int i = 0;
    while (current != NULL) {
        patients[i] = current;
        current = current->next;
        i++;
    }


    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (patients[j]->priority < patients[j + 1]->priority) {
                Patient *temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }


    printf("----------------------------------------------------------------------------------------------\n");
    printf("|  No. | %-20s | %-5s | %-8s | %-30s | %-12s |\n", "Name", "ID", "Age", "Description", "Code");
    printf("----------------------------------------------------------------------------------------------\n");


    for (int i = 0; i < count; i++) {
        printf("|  %-3d | %-20s | %-5s | %-8d | %-30s | %-12s |\n",
               i + 1, patients[i]->name, patients[i]->id, patients[i]->age, patients[i]->symptoms, patients[i]->code);
    }


    printf("+----------------------------------------------------------------------------------------------\n");
}


void nextQueue() {
    if (head == NULL) {
        printf("There is no queue yet!\n");
        return;
    }


    Patient *current = head;
    Patient *previous = NULL;
    Patient *highestPriority = NULL;

    while (current != NULL) {
        if (highestPriority == NULL || current->priority > highestPriority->priority) {
            highestPriority = current;
        }
        previous = current;
        current = current->next;
    }


    if (previous != NULL && highestPriority != NULL) {
        if (previous == head) {
            head = head->next;
        } else {
            previous->next = highestPriority->next;
        }
    }



    if (highestPriority != NULL) {
        printf("\n");
        printf("The next patient is:\n");
        printf("Name: %s\n", highestPriority->name);
        printf("ID: %s\n", highestPriority->id);
        printf("Age: %d\n", highestPriority->age);
        printf("Symptoms: %s\n", highestPriority->symptoms);
        printf("Code: %s\n\n", highestPriority->code);
        free(highestPriority);
        highestPriority = NULL; 
    } else {
        printf("There is no patient in the queue.\n");
    }


    if (head == NULL) {
        printf("The last patient has been removed from the queue.\n");
        return;
    }

}




int main() {
    system("clear");
    int choice;

    while (1) {
        printf("SUNIB Patient Entry\n");
        printf("=====================\n");
        printf("[1] Insert Patient\n");
        printf("[2] View Patient\n");
        printf("[3] Next Queue\n");
        printf("[4] Exit\n");
        printf(">>> ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                insertPatientUI();
                break;
            case 2:
                viewList();
                break;
            case 3:
                nextQueue();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
