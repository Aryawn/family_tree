#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char* name, int age)
{
    Person* person = malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age; 
    person->mother = NULL;
    person->father = NULL;
    return person;
}

void read_person_info(const char *role, char *name_out, int *age_out)
{
    printf("%s's name is? ", role);
    scanf("%49s", name_out);

    printf("%s's age is? ", role);
    scanf("%d", age_out);
}

int main(void)
{
int age;
char name[50];

read_person_info("mine", name, &age);
Person* me = create_person(name, age);
read_person_info("mother", name, &age);
Person* mom = create_person(name, age);
read_person_info("father", name, &age);
Person* dad =  create_person(name, age);
read_person_info("nana", name, &age);
Person* nana = create_person(name, age);
read_person_info("nani", name, &age);
Person* nani = create_person(name, age);
read_person_info("dada", name, &age);
Person* dada = create_person(name, age);
read_person_info("dadi", name, &age);
Person* dadi = create_person(name, age);

return 0;
}



void link_parents(Person *child, Person *father, Person *mother)
{
    child->father = father;
    child->mother = mother;
}

