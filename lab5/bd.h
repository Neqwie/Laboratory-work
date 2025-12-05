#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>

/*

Бд компании по найму сотрудников

Умный массив 

Бинарный

*/

typedef struct Emp {
    int id;
    char name[32];
    char work[32];
    int salary;
} Emp;

typedef struct vector {
    Emp* arr;
    unsigned int size;
    unsigned int capacity;
} vector;

void init_vector(vector *v);

void free_v(vector *v);

void push_back(vector *v, Emp value);

void v_remove(vector *v, int id);

void print_db(vector *v);

void find_name_work(vector *v, char* findname, char* findwork);

void edit_element(vector *v, int index, int id, char* name, char* work, int salary);

void save_in_file(vector *v, char* str);

void read_in_file(vector *v, char* str);
