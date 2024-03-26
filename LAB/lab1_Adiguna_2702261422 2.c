#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char medcode[10];
    char medname[50];
    char disease[50];
    int stock;
    float price; 
} Data;


int main(){

    Data data[4];
    char code[10];
    int found = 0;  
    float total = 0;

    strcpy(data[0].medcode, "DIZ001");
    strcpy(data[0].medname, "Paramex");
    strcpy(data[0].disease, "Dizziness");
    data[0].stock = 120;
    data[0].price = 14.000;

    strcpy(data[1].medcode, "FLU001");
    strcpy(data[1].medname, "Panadol");
    strcpy(data[1].disease, "Flu & Fever");
    data[1].stock = 57;
    data[1].price = 8.000;

    strcpy(data[2].medcode, "DIA001");
    strcpy(data[2].medname, "Diatabs");
    strcpy(data[2].disease, "Diarrhea");
    data[2].stock = 10;
    data[2].price = 6.500;

    strcpy(data[3].medcode, "DIA002");
    strcpy(data[3].medname, "Diapet");
    strcpy(data[3].disease, "Diarrhea");
    data[3].stock = 18;
    data[3].price = 6.000;

    int n;

    do {
        printf("\t\t\t+---------------------------------+\n");
        printf("\t\t\t|         SUNIB Hospital          |\n");
        printf("\t\t\t+---------------------------------+\n");

        printf("\n");

        printf("+-----------------------------------------------------------------------------------+\n");
        printf("|  No. | Medicine Code   | Medecine Name    | Disease      | Stock  | Price         |\n");
        printf("|-----------------------------------------------------------------------------------|\n");
        for (int i =  0; i <  4; i++) {
            printf("|  %d   | %-14s  | %-16s | %-12s | %-6d | Rp. %-6.3f,-  |\n",
                i +  1, data[i].medcode, data[i].medname, data[i].disease, data[i].stock, data[i].price);
        }
        printf("+-----------------------------------------------------------------------------------+\n");
        printf("\n");
        printf("menu : \n");
        printf("1. add stock\n");
        printf("2. sell \n");
        printf("3. exit\n");
        printf("\n");

        printf("Input Choice [1-3]: ");
        scanf("%d", &n);

        switch (n)
        {
            case 1 :
                do {
                    printf("\n");
                    printf("Enter Medicine Code: ");
                    scanf("%s", code);

                    for (int i = 0; i < 4; i++)
                    {
                        if (strcmp(code, data[i].medcode) == 0)
                        {
                            int stock;
                            found = 1;
                            do {
                                printf("\n");
                                printf("Enter Medicine Quantity [1-100]: ");
                                scanf("%d", &stock);
                            } while (stock <= 0 || stock > 100);

                            data[i].stock += stock;
                            // printf("Stock Updated\n");
                            // printf("New Stock: %d\n", data[i].stock);
                            break;
                        }
                    }
                    if (!found)
                    {
                        printf("\n");
                        printf("Medicine Code Doesn't Exist\n");

                    }
                } while (!found);
                printf("\n");   
                printf("Press Enter to Continue....");
                getchar();
                getchar(); 
                break;

            case 2 :

                do {
                    printf("\n");
                    printf("Enter Medicine Code: ");
                    scanf("%s", code);

                    for (int i = 0; i < 4; i++) {
                        if (strcmp(code, data[i].medcode) == 0) {
                            int quantity;
                            found = 1;
                            do {
                                printf("\n");   
                                printf("Enter Medicine Quantity [1-100]: ");
                                scanf("%d", &quantity);
                            } while (quantity <= 0 || quantity > data[i].stock);

                            data[i].stock -= quantity;
                            total += data[i].price * quantity;
                            // printf("Sold %d %s\n", quantity, data[i].medname);
                            // printf("Total Price: Rp. %.3f\n", total);
                            printf("\n"); 
                            printf("+---- Total Price ----+\n");
                            printf(" Quantity: %d\n", quantity);
                            printf(" Rp. %.3f,-\n", data[i].price);
                            printf(" -----------------x\n");
                            printf(" Total: Rp. %.3f,-\n", total);
                            printf("+---------------------+\n");
                            printf("\n");
                            
                            printf("-- Thank You --\n");
                            break;
                        }
                    }
                    if (!found) {
                        printf("\n");
                        printf("Medicine Code Doesn't Exist\n");

                    }
                } while (!found);

                printf("Press Enter to Continue....");
                getchar();
                getchar(); 

                
                break;
            case 3 :
                break;
            default:
                break;
        }
    } while (n != 3);

    return 0;
}