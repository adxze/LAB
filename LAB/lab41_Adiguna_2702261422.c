#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1007

typedef struct {
    char medicineName[51];
    char manufacturerName[26];
    char registrationNumber[11];
    int batchLotNumber;
    char uniqueId[100];
    struct Medicine* next;
} Medicine;

Medicine* hashtable[SIZE];

int hashFunction(char* key) {
    int sum = 0;
    while (*key) {
        sum += *key++;
    }
    return sum % SIZE;
}

int lastInsertedID = 0; 

char* generateUniqueID(char* registrationNumber, char* manufacturerName, char* medicineName) {
    char* uniqueID = (char*)malloc(26 * sizeof(char)); // Allocate memory for the unique ID
    if (uniqueID == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }


    lastInsertedID++;
    

    sprintf(uniqueID, "M%05d-%s-%c%c", lastInsertedID, registrationNumber, toupper(manufacturerName[0]), toupper(medicineName[0]));

    return uniqueID;
}

// perbaikan pada insert 
// insert beberapa ada yang tidak bisa sama. 

void insert(){
    
    Medicine* newMedicine = (Medicine*)malloc(sizeof(Medicine));
    if (newMedicine == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    int isValidInput = 0;
    do {
        printf("Input medicine name[5-10][Unique]: ");
        scanf(" %[^\n]", newMedicine->medicineName);


        int len = strlen(newMedicine->medicineName);
        if (len < 3 || len > 50) {
            printf("Invalid medicine name. Medicine name must have a length between 3 and 50 characters.\n");
            isValidInput = 0;
        } else {

            int isUnique = 1;
            for (int i = 0; i < SIZE; i++) {
                Medicine* currentMedicine = hashtable[i];
                while (currentMedicine != NULL) {
                    if (strcmp(currentMedicine->medicineName, newMedicine->medicineName) == 0) {
                        isUnique = 0;
                        break;
                    }
                    currentMedicine = (Medicine*)currentMedicine->next;
                }
                if (!isUnique) {
                    break;
                }
            }

            if (!isUnique) {
                printf("Medicine name already exists. Please enter a unique medicine name.\n");
                isValidInput = 0;
            } else {
                isValidInput = 1;
            }
        }
    } while (!isValidInput);

    isValidInput = 0;
    do {
        printf("Input manufacturer name [3-25][end with Ltd.]: ");
        scanf(" %[^\n]", newMedicine->manufacturerName);


        int len = strlen(newMedicine->manufacturerName);
        if (len < 3 || len > 25 || strcmp(newMedicine->manufacturerName + len - 4, "Ltd.") != 0) {
            printf("Invalid manufacturer name. Manufacturer name must end with 'Ltd.' and have a length between 3 and 25 characters.\n");
            isValidInput = 0;
        } else {
            isValidInput = 1;
        }
    } while (!isValidInput);

    isValidInput = 0;
    do {
        printf("Input Registration No. [10 digits][Numeric] : ");
        scanf(" %[^\n]", newMedicine->registrationNumber);


        int regNumLen = strlen(newMedicine->registrationNumber);
        int isNumeric = 1;
        for (int i = 0; i < regNumLen; i++) {
            if (!isdigit(newMedicine->registrationNumber[i])) {
                isNumeric = 0;
                break;
            }
        }

        if (regNumLen != 10 || !isNumeric) {
            printf("Invalid registration number. Registration number must be numeric and have a length of 10 digits.\n");
            isValidInput = 0;
        } else {
            isValidInput = 1;
        }
    } while (!isValidInput);

    isValidInput = 0;
    do {
        printf("Input batch/lot number [>=16]: ");
        scanf("%d", &newMedicine->batchLotNumber);


        if (newMedicine->batchLotNumber < 16) {
            printf("Invalid batch/lot number. Batch/lot number must be an integer larger than 16.\n");
            isValidInput = 0;
        } else {
            isValidInput = 1;
        }
    } while (!isValidInput);
    


    char* uniqueID = generateUniqueID(newMedicine->registrationNumber, newMedicine->manufacturerName, newMedicine->medicineName);
    if (uniqueID == NULL) {
        printf("Failed to generate unique ID. Aborting insertion.\n");
        free(newMedicine);
        return;
    }


    strcpy(newMedicine->uniqueId, uniqueID);


    free(uniqueID);



    int index = hashFunction(newMedicine->uniqueId);
    newMedicine->next = (struct Medicine*)hashtable[index];
    hashtable[index] = newMedicine;

    printf("Medicine inserted successfully.\n");
    printf("press Enter To Continue. . .");
    getchar();
    getchar();


}

void viewMedicine() {
    int found = 0;

    for (int i = 0; i < SIZE; i++) {
        if (hashtable[i] != NULL) {
            printf("--------------------------------------------------------------------------------------------------------\n");
            printf("| Medicine Name   | Manufacturer Name | Registration Number | Batch/Lot Number | Unique ID              |\n");
            printf("--------------------------------------------------------------------------------------------------------\n");
            printf("| %-15s | %-17s | %-19s | %-16d | %-19s |\n", hashtable[i]->medicineName, hashtable[i]->manufacturerName, hashtable[i]->registrationNumber, hashtable[i]->batchLotNumber, hashtable[i]->uniqueId);
            printf("--------------------------------------------------------------------------------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("There is no medicine(s)!\n");
    }

    printf("Press any key to continue. . .");
    getchar();


}

void removeMedicine(char* uniqueId) {
    int index = hashFunction(uniqueId);
    if (hashtable[index] != NULL && strcmp(hashtable[index]->uniqueId, uniqueId) == 0) {
        printf("Medicine found:\n");
        printf("Medicine Name: %s\n", hashtable[index]->medicineName);
        printf("Manufacturer Name: %s\n", hashtable[index]->manufacturerName);
        printf("Registration Number: %s\n", hashtable[index]->registrationNumber);
        printf("Batch/Lot Number: %d\n", hashtable[index]->batchLotNumber);
        printf("Unique ID: %s\n", hashtable[index]->uniqueId);
        printf("------------------------------\n");
        
        char confirm;
        do {
            printf("Do you want to remove it? (y/n): ");
            scanf(" %c", &confirm);
            confirm = tolower(confirm); // Convert to lowercase
            if (confirm == 'y') {
                free(hashtable[index]);
                hashtable[index] = NULL;
                printf("Medicine removed successfully.\n");
            } else if (confirm == 'n') {
                printf("Operation cancelled.\n");
            } else {
                printf("Invalid input. Please enter 'y' or 'n'.\n");
            }
        } while (confirm != 'y' && confirm != 'n');
    } else {
        printf("Medicine not found!\n");
        printf("press Enter To Continue. . .");
        getchar();
    }
}
void removeMedicineMenue() {
    char uniqueId[100];
    printf("Input Medicine Id To Delete: ");
    scanf("%s", uniqueId);
    removeMedicine(uniqueId);
    printf("press Enter To Continue. . .");
    getchar();
    getchar();
}

int main() {
    system("clear");
    int choice; 
    for (int i = 0; i < SIZE; i++) {
        hashtable[i] = NULL;
    }

    while (1) {
        printf("SUNIB Hospital\n");
        printf("=============\n");
        printf("1. View Medicine\n");
        printf("2. Insert Medicine\n");
        printf("3. Remove Medicine\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                viewMedicine();
                break;
            case 2:
                insert();
                break;
            case 3:
                removeMedicineMenue();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
