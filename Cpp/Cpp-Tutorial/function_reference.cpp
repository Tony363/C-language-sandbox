#include <stdio.h>
# include <iostream>
using namespace std;

typedef struct {
  char *name;
  int age;
} person;

/* function declaration */
void birthday(person * p);

int main(void) {
  person john;
  john.name = "John";
  john.age = 27;

  printf("%s is %d years old.\n", john.name, john.age);
  birthday(&john);
  printf("Happy birthday! %s is now %d years old.\n", john.name, john.age);

  return 0;
}

void birthday(person *p){
    p->age++;
}