#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
    int data;
    struct node *next;
};

void addInFront(struct node **head, int data){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void addInMiddle(struct node *head, int position, int data){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;

    struct node *temp = head;

    for(int i=2; i < position; i++) {
        if(temp->next != NULL) {
            temp = temp->next;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


void addInEnd(struct node *head, int data){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    struct node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


int main(){

    struct node *head;
    struct node *one =NULL;
    struct node *two =NULL;
    struct node *three =NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    
    one->data = 1;
    two->data = 2;
    three->data = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    struct node *temp = head;



    // addInFront(&head, 0); 
    // addInMiddle(head, 2, 5);
    // addInEnd(head, 4);
    
    printf("\n\nList elements are : \n");
    while(temp != NULL) {
        printf("%d --->",temp->data);
        temp = temp->next;
    }

    return 0;
}