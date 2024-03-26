#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Patient{
    
    char name[100];
    char id[100];
    int age;
    char Description[100];
    char code[100]; // Red, Yellow, Green -> based on the patient's priority  
    struct node *next;  

} Patient;

voind InsertPatient(){

void InsertPatient() {
    struct Patient newPatient;
    
    printf("Enter patient name: ");
    scanf("%s", newPatient.name);
    
    printf("Enter patient ID: ");
    scanf("%s", newPatient.id);
    
    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);
    
    printf("Enter patient description: ");
    scanf("%s", newPatient.Description);
    
    printf("Enter patient code (Red, Yellow, Green): ");
    scanf("%s", newPatient.code);
    
    // Insert code to add newPatient to the patient list
    
    printf("Patient inserted successfully.\n");
    

}



int main(){

    printf("SUNIB Patient Entry\n");
    printf("================================\n");
    printf("[1] Insert Patient\n");
    printf("[2] View Patient\n");
    printf("[3] Next Queue\n");
    printf("[4] Exit\n");
    int choice;
    printf(">>> ");

    switch (choice) {
        case 1:

            break;
        case 2:
            printf("View Patient\n");
            break;
        case 3:
            printf("Next Queue\n");
            break;
        case 4:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}