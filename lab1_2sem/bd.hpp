#include <iostream>
#include <cstring>
#include <fstream>
#include <set>
#include <string>

/*

Бд компании по найму сотрудников

Умный массив 

Бинарный

*/

using namespace std;

namespace bd{

class Emp{
private:
    int id;
    string name;
    string work;
    int salary;

public:
    Emp () {
        id = 0;
        name = "";
        work = "";
    }

    int getId() {return id;}
    string getName() {return name;}
    string getWork() {return work;}
    int getSalary() {return salary;}

    void setId(int n_id) {
        id = n_id;
    }
    void setSalary(int n_s) {
        salary = n_s;
    }
    void setName(string n_name) {
        name = n_name;
    }
    void setWork(string n_work) {
        work = n_work;
    }

    friend ostream& operator<<(ostream& out, const Emp& emp) {
        out << "ID: " << emp.id << "\n";
        out << "Name: " << emp.name << "\n";
        out << "Work: " << emp.work << "\n";
        out << "Salary: " << emp.salary << "\n";
        return out;
    }

    friend istream& operator>>(istream& is, Emp& emp) {
        is >> emp.id >> emp.name >> emp.work >> emp.salary;
        return is;
    }

};




class smart_array {
private:
    Emp* arr;
    unsigned int size;
    unsigned int capacity;
public:
    smart_array () {
        capacity = 32;
        size = 0;
        arr = new Emp[capacity];
    }

    ~smart_array () {
        delete[] arr;
        arr = nullptr;
        size = 0;
        capacity = 0;
    }


    void push_back(Emp value);
    void v_remove(int index);
    void print_db();
    void find_name_work(string findname, string findwork);
    void edit_element(int index, int id, string name, string work, int salary);
    void save_in_file(string& str);
    void read_in_file(string& str);

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



/*void push_back(smart_array *v, Emp value);

void v_remove(smart_array *v, int id);

void print_db(smart_array *v);

void find_name_work(smart_array *v, char* findname, char* findwork);

void edit_element(smart_array *v, int index, int id, char* name, char* work, int salary);

void save_in_file(smart_array *v, string& str);

void read_in_file(smart_array *v, string& str);*/

}