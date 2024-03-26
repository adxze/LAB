#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct namaStruct{ // structure declaration
    int myNum;  // member int variables 
    char myLetter; // members char variabels 
};// akhir struct dengan ; 


// untuk mengakses struct harus 

int main(){

    struct namaStruct t1; 

    t1.myNum = 18;
    t1.myLetter = 'B';


  printf("My number: %d\n", t1.myNum);
  printf("My letter: %c\n", t1.myLetter);

    return 0; 
}


struct myStructure {
  int myNum;
  char myLetter;
  char myString[30]; // String
};

int main() {
  struct myStructure s1;

  // Assign a value to the string using the strcpy function
  strcpy(s1.myString, "Some text");

  // Print the value
  printf("My string: %s", s1.myString);

  return 0;
}

struct myStructure {
  int myNum;
  char myLetter;
  char myString[30];
};

int main() {
  // Create a structure variable and assign values to it
  struct myStructure s1 = {13, 'B', "Some text"};

  // Modify values
  s1.myNum = 30;
  s1.myLetter = 'C';
  strcpy(s1.myString, "Something else");

  // Print values
  printf("%d %c %s", s1.myNum, s1.myLetter, s1.myString);

  return 0;
}