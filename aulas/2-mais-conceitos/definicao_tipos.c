#include <stdio.h>
#include <string.h>

struct Pessoa
{
    char name[50];
    u8 age;
    float height;
};

typedef unsigned short int u8;
typedef struct Pessoa people;

int main()
{
    people pep;
    strcpy(pep.name, "Guardiola");
    pep.age = 53;
    pep.height = 1.8f;

    return 0;
}