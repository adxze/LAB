#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Medicine {
    char medicineName[101];
    char manufacturer[101];
    char registrationNumber[101];
    char batchLotNumber[101];
    char UniqueID[101];
    struct Medicine *next;

}Medicine;

int hashFunction(char *UniqueID){
    int sum = 0;
    for (size_t i = 0; i < strlen(UniqueID); i++){
        sum += UniqueID[i];
    }
    return sum % SIZE;
}

void insertMedicine(struct Medicine *newMedicine, struct Medicine *hashTable[]){
    int index = hashFunction(newMedicine->UniqueID);
    newMedicine->next = hashTable[index];
    hashTable[index] = newMedicine;
}

void viewMedicine(struct Medicine *hashTable[]){
    int found = 0;
    for (int i = 0; i < SIZE; i++){
        struct Medicine *current = hashTable[i];
        while (current != NULL){
            printf("Medicine Name: %s\n", current->medicineName);
            printf("Manufacturer: %s\n", current->manufacturer);
            printf("Registration Number: %s\n", current->registrationNumber);
            printf("Batch/Lot Number: %s\n", current->batchLotNumber);
            printf("Unique ID: %s\n", current->UniqueID);
            printf("\n");
            current = current->next;
            found = 1;
        }
    }
    if (found == 0){
        printf("No medicine found\n");
    }
}

void removeMedicine(char *UniqueID, struct Medicine *hashTable[]){
    int index = hashFunction(UniqueID);
    struct Medicine *current = hashTable[index];
    struct Medicine *prev = NULL;
    while (current != NULL && strcmp(current->UniqueID, UniqueID) != 0){
        prev = current;
        current = current->next;
    }
    if (current == NULL){
        printf("Medicine not found\n");
        return;
    }
    printf("Medicine found. Do you want to delete it? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        if (prev == NULL){
            hashTable[index] = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Medicine removed\n");
    } else {
        printf("Medicine not deleted\n");
    }
}




int main(){

    struct Medicine *hashTable[SIZE];

    for (int i = 0; i < SIZE; i++){
        hashTable[i] = NULL;
    }   
    int choice;

    struct Medicine *newMedicine = malloc(sizeof(struct Medicine));

    printf("SUNIB Hospital\n");
    printf("=============\n");
    printf("1. View Medicine\n");   
    printf("2. Insert Medicine\n");
    printf("3. Remove Medicine\n");
    printf("4. Exit\n");
    printf(">> ");    

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            viewMedicine(hashTable);
            break;
        case 2:
            insertMedicine(newMedicine, hashTable); 
            break;
        case 3:
            removeMedicine(newMedicine->UniqueID, hashTable);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid input\n");
            break;
    }



    return 0;
}