#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7 //size of the hash table

struct Data{
    int value;
    struct Data *next;
};


void insert(int key){

    int index = key % M;
    struct Data *newData;
    newData = malloc(sizeof(struct Data));
    newData->value = key;
    newData->next = NULL;

    if(hashTable[index] == NULL){
        hashTable[index] = newData;
    }else{
        struct Data *temp = hashTable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newData;
    }   

}

void view(){
    printf("The Data \n");
    printf("Index \t Value\n");
    struct Data *hashTable[M];
    for(int i=0; i<M; i++){

        struct Data *temp = hashTable[i];
        printf("%d \t", i);
        while(temp != NULL){
            printf("%d ->", temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}   


int main(){
    struct Data *hashTable[M];
    for(int i=0; i<M; i++){
        hashTable[i] = NULL;
    }

    int pilih; 

    do
    {
        int key;
        printf("\n 1. Input \n");
        printf(" 2. View \n");
        printf(" 3. Exit \n");
        printf("Pilih : ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
          
            printf("Masukkan Nilai: ");
            scanf("%d", &key);
            insert(key);
            //Insert 
            break;
        case 2:
            //view
            view();
            break;
        case 3: 
            printf("Exit\n");
            break;
        default:
            printf("Pilihan tidak ada\n");
            break;
        }


    } while ( pilih != 3);

    

    

    return 0;
}