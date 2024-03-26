#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define M 7

struct Data{
	int value;
	struct Data *next;
};
struct Data *table[M];
void insert(int key){

	int idx = key % M;

	if(table[idx] == NULL){

		table[idx] = (struct Data *)malloc(sizeof(struct Data));
		table[idx]->value = key;
		table[idx]->next = NULL;
		printf("Insert Success!");

	}else{

		struct Data *ptr = table[idx];
		while(ptr->next != NULL && ptr->value !=key)
			ptr = ptr->next;

		if(ptr->value == key){
			printf("Duplikat Data!");
		}else{
			struct Data *newData = (struct Data*)malloc(sizeof(struct Data));
			newData->value = key;
			newData->next = NULL;
			ptr->next = newData;
			printf("Insert Success!");
		}
	}

}

void view(){
	printf("The Data\n");
	printf(" Idx | Data\n");
	printf("-----+--------\n");

	for(int i = 0; i < M; i++){
		printf("%3d | ", i);
		if(table[i] == NULL){
			printf("NULL\n");
		}else{
			struct Data *ptr = table[i];
			printf("%d", ptr->value);
			while(ptr->next != NULL){
				ptr = ptr->next;
				printf("-> %d", ptr->value);
			}
			printf("\n");
		}
	}
}

int main(){

	for(int i = 0; i <M; i++){
		table[i] = NULL;
	}

	int pilih, key;

	do{
		system("cls");
		printf("\n1. Input\n");
		printf("2. View\n");
		printf("3. Exit\n");
		printf("Pilih: ");
		scanf("%d", &pilih);

		switch(pilih){
			case 1:
				printf("masukkan key: ");
				scanf("%d", &key);
				insert(key);
				getch();
				break;
			case 2:
				view();
				getch();
				break;
			case 3:
				break;
			default:
				printf("wrong input");
				getch();
				break;
		}

	}while(pilih != 3);
	return 0;
}