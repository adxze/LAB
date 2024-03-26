#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define clear system("cls")

struct BinaryTreeNode {
    char phoneNumber[14];
    char name[26];
    char email[21];
    int visits;
    bool isMember;
    struct BinaryTreeNode *left, *right;
};
struct BinaryTreeNode* newNodeCreate(char phoneNumber[], char name[], char email[]) {
    struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    strcpy(temp->phoneNumber, phoneNumber);
    strcpy(temp->name, name);
    strcpy(temp->email, email);
    temp->visits = 0;
    temp->left = temp->right = NULL;
    return temp;
}

struct BinaryTreeNode* searchNode(struct BinaryTreeNode* root, char phoneNumber[]) {
    if (root == NULL || strcmp(root->phoneNumber, phoneNumber) == 0) {
        return root;
    }
    if (strcmp(root->phoneNumber, phoneNumber) > 0) {
        return searchNode(root->left, phoneNumber);
    }
    return searchNode(root->right, phoneNumber);
}

struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, char phoneNumber[], char name[], char email[]) {
    if (node == NULL) {
        return newNodeCreate(phoneNumber, name, email);
    }
    if (strcmp(phoneNumber, node->phoneNumber) < 0) {
        node->left = insertNode(node->left, phoneNumber, name, email);
    } else if (strcmp(phoneNumber, node->phoneNumber) > 0) {
        node->right = insertNode(node->right, phoneNumber, name, email);
    }
    return node;
}

void inOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        printf("-----------------------------------------------------------------------------------\n");
        printf("| %-15s | %-25s | %-20s | %-10s |\n", "Phone Number", "Name", "Email", "Visits");
        printf("-----------------------------------------------------------------------------------\n");
        inOrder(root->left);

        printf("| %-15s | %-25s | %-20s | %-10d |\n", root->phoneNumber, root->name, root->email, root->visits);
        printf("-----------------------------------------------------------------------------------\n");
        inOrder(root->right);
        getchar();
    }
}

struct BinaryTreeNode* deleteNode(struct BinaryTreeNode* root, char phoneNumber[]) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(phoneNumber, root->phoneNumber) < 0) {
        root->left = deleteNode(root->left, phoneNumber);
    } else if (strcmp(phoneNumber, root->phoneNumber) > 0) {
        root->right = deleteNode(root->right, phoneNumber);
    } else {
        if (root->left == NULL) {
            struct BinaryTreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BinaryTreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct BinaryTreeNode* findMin(struct BinaryTreeNode* root);

        struct BinaryTreeNode* temp = findMin(root->right);
        strcpy(root->phoneNumber, temp->phoneNumber);
        strcpy(root->name, temp->name);
        strcpy(root->email, temp->email);
        root->right = deleteNode(root->right, temp->phoneNumber);
        getchar();
    }
    return root;
}
struct BinaryTreeNode* findMin(struct BinaryTreeNode* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return findMin(root->left);
}


int validatePhoneNumber(char phoneNumber[]) {
    int length = strlen(phoneNumber);
    if (length < 10 || length > 13) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!isdigit(phoneNumber[i])) {
            return 0;
        }
    }
    return 1;
}
int validateName(char name[]) {
    char *titles[2] = {"Mr. ", "Mrs. "};
    char *titlePos; 
    int valid = 0;


    for (int i = 0; i < 2 && !valid; i++) {
        titlePos = strstr(name, titles[i]);
        if (titlePos && (int)(titlePos - name) == 0) {
            // Memeriksa panjang nama setelah prefix
            if (strlen(titlePos + strlen(titles[i])) >= 5 && strlen(titlePos + strlen(titles[i])) <= 25) {
                valid = 1;
            }else{
                printf("Name is too short !\n");
        }
    }
    return valid;
    printf("Invalid name\n");
    }
    return 0;
}
int validateEmail(char email[]) {
    int length = strlen(email);
    if (length < 10 || length > 20) {
        return 0;
    }
    int atCount = 0;
    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            atCount++;
        }
    }
    if (atCount != 1) {
        return 0;
    }
    if (strstr(email, ".com") == NULL && strstr(email, ".co.id") == NULL) {
        return 0;
    }
    return 1;
}

void buyProduct(struct BinaryTreeNode* customer, bool isMember) {

    int ob1 = 0, ob2 = 0, ob3 = 0, ob4 = 0, ob5 = 0;
    int choice;

    int total = 0;
    char yesno;
    if (!isMember == false) {
        customer->visits++;
        printf("Number of visits: %d\n", customer->visits);
    }
    if(isMember == true){
        printf("Welcome back, %s!\n", customer->name);
    } else {
        printf("Welcome, %s!\n", customer->name);
    }
    printf("--------------------------------------------------\n");   
    printf("| %-10s | %-20s | %-10s |\n", "NO", "Nama Obat", "Harga");
    printf("--------------------------------------------------\n");   
    printf("| %-10s | %-20s | %-10s | \n", "1", "Paracetamol", "5000");
    printf("| %-10s | %-20s | %-10s | \n", "2", "Diapet", "7000");
    printf("| %-10s | %-20s | %-10s | \n", "3", "Oralit", "3500");
    printf("| %-10s | %-20s | %-10s | \n", "4", "Paratusin", "5500");
    printf("| %-10s | %-20s | %-10s | \n", "5", "OB Herbal", "6000");
    printf("--------------------------------------------------\n");
    /* Bisa menggunakan loop, data medicine di store didalam struct
        Tapi malas buatnya, jadi saya hardcode saja
    */
    do{
        printf("Input medicine[1-5]: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Input quantitiy[>=1]: ");
                scanf("%d", &ob1);
                total += 5000 * ob1;
                break;
            case 2:
                printf("Input quantitiy[>=1]: ");
                scanf("%d", &ob2);
                total += 7000 * ob2;
                break;
            case 3:
                printf("Input quantitiy[>=1]: ");
                scanf("%d", &ob3);
                total += 3500 * ob3;
                break;
            case 4:
                printf("Input quantitiy[>=1]: ");
                scanf("%d", &ob4);
                total += 5500 * ob4;
                break;  
            case 5:
                printf("Input quantitiy[>=1]: ");
                scanf("%d", &ob5);
                total += 6000 * ob5;
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }

        printf("Do you want to order another medicine[y/n]: ");
        scanf(" %c", &yesno);
 
    } while (yesno == 'y' || yesno == 'Y');


    printf("Order Summary:\n");

    for(int i = 0; i < 5; i++){
        if(i == 0 && ob1 > 0){
            printf("Paracetamol         - %dx = %d\n", ob1, ob1 * 5000);
        } else if(i == 1 && ob2 > 0){
            printf("Diapet             - %dx = %d\n", ob2, ob2 * 7000);
        } else if(i == 2 && ob3 > 0){
            printf("Oralit             - %dx = %d\n", ob3, ob3 * 3500);
        } else if(i == 3 && ob4 > 0){
            printf("Paratusin          - %dx = %d\n", ob4, ob4 * 5500);
        } else if(i == 4 && ob5 > 0){
            printf("OB Herbal          - %dx = %d\n", ob5, ob5 * 6000);
        }
    }
    if(!isMember == true){
        if (customer->visits >= 5) {
            total = total - (total * 0.1);
            printf("Discount 10%% applied!\n");
        }
    }

    printf("Total : %d\n", total);

    printf("Press enter to continue...");
    getchar(); 
}

int main() {
    struct BinaryTreeNode* root = NULL;
    int choice; 
    int valid;
    char phoneNumber[14];
    char name[26];
    char email[21];

    do {
        system("clear");
        printf("SUNIB's Pharmacy\n");
        printf("================\n");
        printf("1. Process Order\n");
        printf("2. View All Customers\n");
        printf("3. Remove Customer\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter phone number[1-10][Numerical]: ");
                scanf("%s", phoneNumber);
                while(!validatePhoneNumber(phoneNumber)){
                    printf("Invalid phone number. Please try again.\n");
                    printf("Enter phone number: ");
                    scanf("%s", phoneNumber);
                }
                struct BinaryTreeNode* customer = searchNode(root, phoneNumber);
                if (customer == NULL) {
                    printf("Phone number does not exist. Register for membership? [y/n]: ");
                    char registerChoice;
                    scanf(" %c", &registerChoice);
                    if (registerChoice == 'y' || registerChoice == 'Y') {
                        // printf("pilihan iya\n");

                        while(valid == 0){
                            printf("Enter name[5-25][Mr. | Mrs. ]: ");
                            fgets(name, sizeof(name), stdin);
                            name[strcspn(name, "\n")] = 0;
                            valid = validateName(name);

                        };
                
                        printf("Enter email: ");
                        scanf("%s", email);
                        while(!validateEmail(email)){
                            printf("Invalid email. Please try again.\n");
                            printf("Enter email: ");
                            scanf("%s", email);
                        }
                        root = insertNode(root, phoneNumber, name, email);
                        printf("\n");
                        printf("Customer registered successfully.\n");
                        printf("\n");
                        customer = searchNode(root, phoneNumber);

                        buyProduct(customer, customer->isMember);
                        getchar();
                    }
                    else {
                        printf("Customer not registered.\n");
                        struct BinaryTreeNode* tempCustomer = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
                        strcpy(tempCustomer->phoneNumber, "N/A");
                        strcpy(tempCustomer->name, "Guest");
                        strcpy(tempCustomer->email, "N/A");
                        tempCustomer->visits = 0;
                        tempCustomer->left = tempCustomer->right = NULL;
                        tempCustomer->isMember = false; 

                        buyProduct(tempCustomer, tempCustomer->isMember);
                        getchar();
                        free(tempCustomer); 
                    }
                } else {
                    buyProduct(customer, customer->isMember);
                    getchar();
                }
                break;
            case 2:
                if (root == NULL) {
                    printf("There is no data!\n");
                    printf("Press enter to continue...");
                    getchar();
                    getchar();
                } else {
                    printf("Customer Data:\n");
                    inOrder(root);
                    getchar();
                }
                break;
            case 3:
                printf("Enter phone number to remove: ");
                scanf("%s", phoneNumber);
                if (!validatePhoneNumber(phoneNumber)) {
                    printf("Invalid phone number.\n");
                    getchar();
                    getchar();
                }
                else if (searchNode(root, phoneNumber) == NULL) {
                    printf("Data invalid!\n");
                    getchar();
                    getchar();
                } else {
                    root = deleteNode(root, phoneNumber);
                    printf("Customer removed successfully.\n");
                    getchar();
                    getchar();
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }  
    } while (choice != 4);
    return 0;
}


