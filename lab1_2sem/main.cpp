#include "bd.hpp"

int main() {

    smart_array BD;
    init_smart_array(&BD);
    set<int> uniq_ID;
    
    int k;
    cout << "Приветствуем в контекстном меню БД\n";
    cout << "У Вас есть выбор команд(номера и названия):\n";
    cout << "0 - Выход\n";
    cout << "1 - Добавление рабочего\n";
    cout << "2 - Вывод БД на экран\n";
    cout << "3 - Изменение элемента БД\n";
    cout << "4 - Удаление по индексу\n";
    cout << "5 - Поиск по имени и профессии\n";
    cout << "6 - Сохранение БД в файл\n";
    cout << "7 - Загрузка из файла\n";

    if (!(cin >> k)) {
        cout << "!      Input_Error      !\n";
        cout << "Brake up";
        cin.clear();
        cin.ignore(10000, '\n');
        return 1;
    }
    while (k != 0) {
        switch (k) {
        case 0:
            k = 0;
            break;
        case 1: {
            cout << "Введите в следующем порядке: id(int), name(string), work(string), salary(int)\n";
            Emp e;
            if (!(cin >> e.id >> e.name >> e.work >> e.salary)) {
                cout << "!      Input_Error      !\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            while (!uniq_ID.insert(e.id).second) {
                cout << "Данный id уже есть, введите другой id(int)\n";
                if (!(cin >> e.id)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
            push_back(&BD, e);
            break;
        }
        case 2: {
            print_db(&BD);
            break;
        }
        case 3: {
            cout << "Введите в следующем порядке: index(int), id(int), name(string), work(string), salary(int), если не хотите изменять типы int пишите -1, если же типы string пишите 0\n";
            int id;
            int index;
            char name[64];
            char work[64];
            int salary;
            if (!(cin >> index >> id >> name >> work >> salary)) {
                cout << "!      Input_Error      !\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            edit_element(&BD, index, id, name, work, salary);
            break;
        }
        case 4: {
            cout << "Введите индекс элемента, который хотите удалить\n";
            int index;
            cin >> index;
            v_remove(&BD, index);
            break;
        }
        case 5: {
            cout << "Введите в начале имя, a потом и название профессии работника\n";
            char name[64];
            char work[64];
            cin >> name >> work;
            find_name_work(&BD, name, work);
            break;
        }
        case 6: {
            cout << "Введите название файла(.bin), куда хотите сохранить БД\n";
            string str;
            cin >> str;
            save_in_file(&BD, str);
            break;
        }
        case 7: {
            cout << "Введите название файла(.bin), откуда хотите считать данные в БД\n";
            string str;
            cin >> str;
            read_in_file(&BD, str);
            }
        }
        cout << "0 - Выход\n";
        cout << "1 - Добавление рабочего\n";
        cout << "2 - Вывод БД на экран\n";
        cout << "3 - Изменение элемента БД\n";
        cout << "4 - Удаление по индексу\n";
        cout << "5 - Поиск по имени и профессии\n";
        cout << "6 - Сохранение БД в файл\n";
        cout << "7 - Загрузка из файла\n";
        if (!(cin >> k)) { 
            break;
        }
    }
    delete_v(&BD);
    cout << "End of the program";
    return 0;
}
