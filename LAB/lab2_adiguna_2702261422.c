#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For tolower function


typedef struct Node {
    char medicine[100];
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

// function untuk inisialisasi stack
void initStack(Stack *stack) {
    stack->top = NULL;
}

// menambahkan medicine ke dalam stack
void push(Stack *stack, const char *medicine) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->medicine, medicine, 100);
    newNode->next = stack->top;
    stack->top = newNode;
}

// function untuk menghapus medicine dari stack
// void pop(Stack *stack) {
//     if (stack->top == NULL) {
//         printf("Stack is empty.\n");
//         return;
//     }
//     Node *temp = stack->top;
//     stack->top = stack->top->next;
//     free(temp);
// }

// function to display the contents of the stack
void display(Stack *stack) {
    Node *temp = stack->top;
    int medicineNumber = 1;
    while (temp != NULL) {
        printf("Medicine Number #%d: %s\n", medicineNumber, temp->medicine);
        temp = temp->next;
        medicineNumber++;
    }
}

int main() {
    Stack medicineStack;
    initStack(&medicineStack);
    char medicine[100];
    char continueChoice[4];

    while (1) {
        int count =  0;
        system("clear"); // system("clr") jika pada windows, saya menggunakan macos
        printf("Sunib hospital\n");
        printf("==============\n");
        printf("\n");
        printf("\n");
        while (count < 5) {
            printf("Enter the medicine name [minimum 5 medicines] ('done' to finish): ");
            fgets(medicine, 100, stdin);
            // membuang newline character dari fgets
            medicine[strcspn(medicine, "\n")] =  0;

            if (strcmp(medicine, "done") ==  0) {
                if (count < 5) {
                    printf("Minimum of %d medicines required. Please enter more.\n", 5);
                    continue;
                } else {
                    break;
                }
            }
            push(&medicineStack, medicine);
            count++;
        }

        printf("\nMedicines Prescription: \n");
        display(&medicineStack);

        printf("\nDo you want to continue? (yes/no): ");
        fgets(continueChoice, sizeof(continueChoice), stdin);
        continueChoice[strcspn(continueChoice, "\n")] =  0;
        // mengubah continueChoice menjadi lowercase
        for (int i =  0; continueChoice[i]; i++) {
            continueChoice[i] = tolower(continueChoice[i]);
        }

        if (strcmp(continueChoice, "no") ==  0) {
            break;
        }
    }

    return  0;
}
