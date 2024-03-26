#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

    int num = 5;
    int *ptr = &num;
    int **ptr2 = &ptr;

    **ptr2 = 10;
    printf("Value of num: %d\n", num);


    return 0;
}