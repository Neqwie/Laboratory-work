#include "bd.h"

void init_vector(vector *v){
    v->capacity = 32;
    v->size = 0;
    v->arr = (Emp*) malloc(sizeof(Emp) * v->capacity);
    if (v->arr == NULL) {
        printf("MEM_ERROR");
        return;
    }
}



void free_v(vector *v){
    free(v->arr);
    v->size = 0;
    v->capacity = 0;
}



void push_back(vector *v, Emp value){
    if (v->capacity == v->size) {
        unsigned int new_capacity = v->capacity * 2;
        Emp* new_arr = (Emp*) realloc(v->arr, new_capacity * sizeof(Emp));
        if (new_arr == NULL) { 
            printf("MEM_ERROR"); 
            return;
        }
        v->arr = new_arr;
        v->capacity = new_capacity;
    }
    v->arr[v->size] = value;
    v->size++;
}



void v_remove(vector *v, int id){
    if (id >= v->size) {
        printf("UNCORRECT INDEX");
        return;
    }    
    if (v->arr == NULL) {
        printf("VOID_ERROR");
        return;
    }
    for (int i = id; i < v->size - 1; i++) {
        v->arr[i] = v->arr[i + 1];
    }

    v->size--;
}



void print_db(vector *v){
    if (v == NULL) {
        printf("STRUCT IS NULL");
        return;
    }
    printf("---------------\n");
    for (int i = 0; i < v->size; i++) {
        printf("ID: %d\nName: %s\nWork: %s\nSalary: %i\n", v->arr[i].id, v->arr[i].name, v->arr[i].work, v->arr[i].salary);
        printf("---------------\n");
    }
    printf("\n");
}



void find_name_work(vector *v, char* findname, char* findwork) {
    if (v == NULL) {
        printf("STRUCT IS NULL");
        return;
    }
    int cnt = 0;
    for (int i = 0; i < v->size; i++) {
        int nameeq = strcmp(findname, v->arr[i].name);
        int workeq = strcmp(findwork, v->arr[i].work);
        if (nameeq == 0 && workeq == 0) {
            printf("###############\n");
            printf("Elements was found\n");
            printf("index of element: %i\n", i);
            printf("ID: %d\nName: %s\nWork: %s\nSalary: %i\n", v->arr[i].id, v->arr[i].name, v->arr[i].work, v->arr[i].salary);
            printf("###############\n");
            cnt++;
        }
    }
    if (cnt == 0) {
        printf("###############\n");
        printf("Not found\n");
        printf("###############\n");
    }
}


void edit_element(vector *v, int index, int id, char* name, char* work, int salary) {
    if (v == NULL) {
        printf("STRUCT IS NULL");
        return;
    }
    bool flag_id = true;
    bool flag_name = true;
    bool flag_work = true;
    bool flag_salary = true;

    if (id == -1) {
        flag_id = false;
    }
    if (name[0] == '0') {
        flag_name = false;
    }
    if (work[0] == '0') {
        flag_work = false;
    }
    if (salary == -1) {
        flag_salary = false;
    }

    if (flag_id) {
        v->arr[index].id = id;
    }
    if (flag_name) {
        strcpy(v->arr[index].name, name);
    }
    if (flag_work) {
        strcpy(v->arr[index].work, work);
    }
    if (flag_salary) {
        v->arr[index].salary = salary;
    }
}



void save_in_file(vector *v, char* str) {
    FILE *f = fopen(str, "wb+");
    if (f == NULL) {
        printf("File_Error");
        return;
    }

    fwrite(&v->size, sizeof(unsigned int), 1, f);
    fwrite(v->arr, sizeof(Emp), v->size, f);

    fclose(f);
    printf("Save success\n");
}

void read_in_file(vector *v, char* str) {
    FILE *f = fopen(str, "rb+");
    if (f == NULL) {
        printf("File_Error");
        return;
    }

    unsigned int size;
    if (fread(&size, sizeof(unsigned int), 1, f) != 1) {
       fclose(f);
       return;
    }

     for (unsigned int i = 0; i < size; i++) {
        Emp emp;
        if (fread(&emp, sizeof(Emp), 1, f) != 1) {
            printf("Error reading employee %u\n", i);
            fclose(f);
            return;
        }
        push_back(v, emp);
    }


    fclose(f);
    printf("Read from file\n");
}
