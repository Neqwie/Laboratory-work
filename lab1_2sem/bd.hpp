#include <bits/stdc++.h>

/*

Бд компании по найму сотрудников

Умный массив 

Бинарный

*/

using namespace std;

class Emp{
public:
    int id;
    char name[64];
    char work[64];
    int salary;

    Emp () {
        id = 0;
        name[0] = '\0';
        work[0] = '\0';
    }
};

class smart_array {
public:
    Emp* arr;
    unsigned int size;
    unsigned int capacity;

    smart_array () {
        arr = nullptr;
        size = 0;
        capacity = 0;
    }

};

/*typedef struct Emp {
    int id;
    char name[32];
    char work[32];        CREATED thru class
    int salary;
} Emp;*/

/*typedef struct smart_array {
    Emp* arr;
    unsigned int size;          CREATED thru class
    unsigned int capacity;
} smart_array;*/




void init_smart_array(smart_array *v);

void delete_v(smart_array *v);

void push_back(smart_array *v, Emp value);

void v_remove(smart_array *v, int id);

void print_db(smart_array *v);

void find_name_work(smart_array *v, char* findname, char* findwork);

void edit_element(smart_array *v, int index, int id, char* name, char* work, int salary);

void save_in_file(smart_array *v, string& str);

void read_in_file(smart_array *v, string& str);