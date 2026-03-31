#include "bd.hpp"



void init_smart_array(smart_array *v){
    v->capacity = 32;
    v->size = 0;
    v->arr = new Emp[v->capacity];
    if (v->arr == nullptr) {
        cout << "MEM_ERROR";
        return;
    }
}



void delete_v(smart_array *v){
    delete[] v->arr;
    v->size = 0;
    v->capacity = 0;
}



void push_back(smart_array *v, Emp value){

    if (v->capacity == v->size) {
        unsigned int new_capacity = v->capacity * 2;
        Emp* new_arr = new Emp[new_capacity];
        if (new_arr == nullptr) { 
            cout << "MEM_ERROR"; 
            return;
        }
        for (unsigned int i = 0; i < v->size; i++) {
            new_arr[i] = v->arr[i];
        }
        delete[] v->arr;
        v->arr = new_arr;
        v->capacity = new_capacity;
        
    }
    v->arr[v->size] = value;
    v->size++;
}



void v_remove(smart_array *v, int id){

    if (id >= v->size) {
        cout << "UNCORRECT INDEX";
        return;
    }    
    if (v->arr == nullptr) {
        cout << "VOID_ERROR";
        return;
    }
    for (int i = id; i < v->size - 1; i++) {
        v->arr[i] = v->arr[i + 1];
    }

    v->size--;
}



void print_db(smart_array *v){

    if (v == nullptr || v->arr == nullptr) {
        cout << "STRUCT IS NULL";
        return;
    }
    cout << "---------------\n";
    for (int i = 0; i < v->size; i++) {
        cout << "ID: " << v->arr[i].id << "\n";
        cout << "Name: " << v->arr[i].name << "\n";
        cout << "Work: " << v->arr[i].work <<  "\n";
        cout << "Salary: " << v->arr[i].salary << "\n";
        cout << "---------------\n";
    }
    cout << "\n";
}



void find_name_work(smart_array *v, char* findname, char* findwork) {

    if (v == nullptr || v->arr == nullptr) {
        cout << "STRUCT IS NULL";
        return;
    }
    int cnt = 0;
    for (int i = 0; i < v->size; i++) {
        bool nameeq = (std::strcmp(findname, v->arr[i].name) == 0);
        bool workeq = (std::strcmp(findwork, v->arr[i].work) == 0);
        if (nameeq  && workeq) {
            cout << "###############\n";
            cout << "Elements was found\n";
            cout << "index of element: " << i << "\n";
            cout << "ID: " << v->arr[i].id << "\n";
            cout << "Name: " << v->arr[i].name << "\n";
            cout << "Work: " << v->arr[i].work <<  "\n";
            cout << "Salary: " << v->arr[i].salary << "\n";
            cout << "###############\n";
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "###############\n";
        cout << "Not found\n";
        cout << "###############\n";
    }
}


void edit_element(smart_array *v, int index, int id, char* name, char* work, int salary) {

    if (v == nullptr || v->arr == nullptr) {
        cout << "STRUCT IS NULL\n";
        return;
    }

    if (index >= v->size || index < 0) {
        cout << "OUT OF RANGE\n";
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
        fill(begin(v->arr[index].name), end(v->arr[index].name), '\0');
        copy_n(name, min(strlen(name), sizeof(v->arr[index].name) - 1), v->arr[index].name);
    }
    if (flag_work) {
        fill(begin(v->arr[index].work), end(v->arr[index].work), '\0');
        copy_n(work, min(strlen(work), sizeof(v->arr[index].work) - 1), v->arr[index].work);
    }
    if (flag_salary) {
        v->arr[index].salary = salary;
    }
}



void save_in_file(smart_array *v, string& str) {

    ofstream f(str, ios::binary);
    if (!f.is_open()) {
        std::cout << "File_Error";
        return;
    }

    f.write(reinterpret_cast<const char*>(&v->size), sizeof(v->size));
    f.write(reinterpret_cast<const char*>(v->arr), sizeof(Emp) * v->size);

    cout << "Save success\n";
}

void read_in_file(smart_array *v, string& str) {

    if (v-> arr == nullptr) {
        init_smart_array(v);
    }

    std::ifstream f(str, std::ios::binary);
    if (!f.is_open()) {
        std::cout << "File_Error";
        return;
    }
    v->size = 0;
    unsigned int size = 0;
    if (!f.read(reinterpret_cast<char*>(&size), sizeof(unsigned int))) {
        return;
    }

     for (unsigned int i = 0; i < size; i++) {
        Emp emp;
        if (!f.read(reinterpret_cast<char*>(&emp), sizeof(Emp))) {
            std::cout << "Error reading employee " << i << "\n";
            return;
        }
        push_back(v, emp);
    }

    cout << "Read from file\n";
}