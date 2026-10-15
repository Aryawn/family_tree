#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

int main(void)
{


}

Person* create_person(const char* name, int age)
{
    Person* person = malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age; 
    person->mother = NULL;
    person->father = NULL;
}


