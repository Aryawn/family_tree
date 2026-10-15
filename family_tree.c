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

void link_parents(Person *child, Person *father, Person *mother)
{
    child->father = father;
    child->mother = mother;
}

void print_family_relationships(const Person *me)
{
    printf("1. Yourself:\n");
    printf(" - Name: %s | Age: %d\n", me->name, me->age);

    printf("2. Parents:\n");
    printf(" - Name: %s | Age: %d\n", me->mother->name, me->mother->age);
    printf(" - Name: %s | Age: %d\n", me->father->name, me->father->age);

    printf("3. Paternal Grandparents\n");
    printf(" - Name: %s | Age: %d\n", me->father->father->name, me->father->father->age);
    printf(" - Name: %s | Age: %d\n", me->father->mother->name, me->father->mother->age);

    printf("4. Maternal Grandparents\n");
    printf(" - Name: %s | Age: %d\n", me->mother->father->name, me->mother->father->age);
    printf(" - Name: %s | Age: %d\n", me->mother->mother->name, me->mother->mother->age);
    
}

void free_family_tree(Person *people[], int count)
{
    for (int i = 0; i < count; i++)
    {
        free(people[i]);
    }
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

link_parents(me, dad, mom);
link_parents(dad, dada, dadi);
link_parents(mom, nana, nani);

print_family_relationships(me);

Person *people[7] = {me, mom, dad, nana, nani, dada, dadi};
free_family_tree(people, 7);
return 0;
}




