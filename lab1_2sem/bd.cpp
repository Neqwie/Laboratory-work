#include "bd.hpp"

namespace bd {

ostream& operator<<(ostream& out, const Emp& emp) {
    out << "ID: " << emp.id << "\n";
    out << "Name: " << emp.name << "\n";
    out << "Work: " << emp.work << "\n";
    out << "Salary: " << emp.salary << "\n";
    return out;
}

istream& operator>>(istream& is, Emp& emp) {
    is >> emp.id >> emp.name >> emp.work >> emp.salary;
    return is;
}


void smart_array::push_back(Emp value){

    if (capacity == size) {
        unsigned int new_capacity = capacity * 2;
        Emp* new_arr = new Emp[new_capacity];
        if (new_arr == nullptr) { 
            cout << "MEM_ERROR"; 
            return;
        }
        for (unsigned int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
        
    }
    arr[size] = value;
    size++;
}



void smart_array::v_remove(int id){

    if (id >= size) {
        cout << "UNCORRECT INDEX";
        return;
    }    
    if (arr == nullptr) {
        cout << "VOID_ERROR";
        return;
    }
    for (int i = id; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}



void smart_array::print_db(){

    if (arr == nullptr) {
        cout << "STRUCT IS NULL";
        return;
    }
    cout << "---------------\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        cout << "---------------\n";
    }
    cout << "\n";
}



void smart_array::find_name_work(const string& findname, const string& findwork) {

    if (arr == nullptr) {
        cout << "STRUCT IS NULL";
        return;
    }
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        bool nameeq = (findname == arr[i].getName());
        bool workeq = (findwork == arr[i].getWork());
        if (nameeq  && workeq) {
            cout << "###############\n";
            cout << "Elements was found\n";
            cout << "index of element: " << i << "\n";
            cout << arr[i];
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


void smart_array::edit_element(int index, int id, string name, string work, int salary) {

    if (arr == nullptr) {
        cout << "STRUCT IS NULL\n";
        return;
    }

    if (index >= size || index < 0) {
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
        arr[index].setId(id);
    }
    if (flag_name) {
        arr[index].setName(name);
    }
    if (flag_work) {
        arr[index].setWork(work);
    }
    if (flag_salary) {
        arr[index].setSalary(salary);
    }
}



void smart_array::save_in_file(string& str) {

    std::ofstream f(str, std::ios::binary);
    if (!f) { 
        std::cout << "File_Error\n"; 
        return; 
    }

    f.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (unsigned int i = 0; i < size; ++i) {
        Emp& e = arr[i];

        int id = e.getId();
        int salary = e.getSalary();
        f.write(reinterpret_cast<const char*>(&id), sizeof(id));
        f.write(reinterpret_cast<const char*>(&salary), sizeof(salary));

        const std::string& name = e.getName();
        size_t name_len = name.size();
        f.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
        f.write(name.data(), name_len);

        const std::string& work = e.getWork();
        size_t work_len = work.size();
        f.write(reinterpret_cast<const char*>(&work_len), sizeof(work_len));
        f.write(work.data(), work_len);
    }

    std::cout << "Save success\n";

}

void smart_array::read_in_file(string& str) {

    ifstream f(str, ios::binary);
    if (!f) { cout << "File_Error\n"; return; }

    unsigned int new_size = 0;
    f.read(reinterpret_cast<char*>(&new_size), sizeof(new_size));

    size = 0;
    for (unsigned int i = 0; i < new_size; i++) {
        Emp e;
        int id, salary;
        f.read(reinterpret_cast<char*>(&id), sizeof(id));
        f.read(reinterpret_cast<char*>(&salary), sizeof(salary));
        e.setId(id);
        e.setSalary(salary);

        size_t name_len;
        f.read(reinterpret_cast<char*>(&name_len), sizeof(name_len));
        string name(name_len, ' ');
        f.read(&name[0], name_len);
        e.setName(name);

        size_t work_len;
        f.read(reinterpret_cast<char*>(&work_len), sizeof(work_len));
        string work(work_len, ' ');
        f.read(&work[0], work_len);
        e.setWork(work);

        push_back(e);
    }
    cout << "Read from file\n";
}

}