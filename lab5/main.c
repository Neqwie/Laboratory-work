#include "bd.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector BD;
    init_vector(&BD);
    
    int k;
    printf("Приветствуем в контекстном меню БД\n");
    printf("У Вас есть выбор команд(номера и названия):\n");
    printf("0 - Выход\n");
    printf("1 - Добавление рабочего\n");
    printf("2 - Вывод БД на экран\n");
    printf("3 - Изменение элемента БД\n");
    printf("4 - Удаление по индексу\n");
    printf("5 - Поиск по имени и профессии\n");
    printf("6 - Сохранение БД в файл\n");
    printf("7 - Загрузка из файла\n");
    if (scanf("%i", &k) != 1) {
        printf("!      Input_Error      !\n");
        printf("Brake up");
        while (getchar() != '\n');
    }
    while (k != 0) {
        switch (k) {
        case 0:
            k = 0;
            break;
        case 1: {
            printf("Введите в следующем порядке: id(int), name(string), work(string), salary(int)\n");
            int id;
            char name[32];
            char work[32];
            int salary;
            if (scanf("%i%s%s%i", &id, name, work, &salary) != 4) {
                printf("!      Input_Error      !\n");
                while (getchar() != '\n');
                break;
            }
            Emp e;
            e.id = id;
            strcpy(e.name, name);
            strcpy(e.work, work);
            e.salary = salary;
            push_back(&BD, e);
            break;
        }
        case 2: {
            print_db(&BD);
            break;
        }
        case 3: {
            printf("Введите в следующем порядке: index(int), id(int), name(string), work(string), salary(int), если не хотите изменять типы int пишите -1, если же типы string пишите 0\n");
            int id;
            int index;
            char name[32];
            char work[32];
            int salary;
            if (scanf("%i%i%s%s%i", &index, &id, name, work, &salary) != 5) {
                printf("!      Input_Error      !\n");
                while (getchar() != '\n');
                break;
            }
            edit_element(&BD, index, id, name, work, salary);
            break;
        }
        case 4: {
            printf("Введите индекс элемента, который хотите удалить\n");
            int index;
            if (scanf("%i", &index) != 1) {
                printf("!      Input_Error      !\n");
                while (getchar() != '\n');
                break;
            }
            v_remove(&BD, index);
            break;
        }
        case 5: {
            printf("Введите в начале имя, a потом и название профессии работника\n");
            char name[32];
            char work[32];
            if (scanf("%s%s", name, work) != 2) {
                printf("!      Input_Error      !\n");
                while (getchar() != '\n');
                break;
            }
            find_name_work(&BD, name, work);
            break;
        }
        case 6: {
            printf("Введите название файла(.bin), куда хотите сохранить БД\n");
            char str[64];
            if (scanf("%s", str) != 1) {
                printf("!      Input_Error      !\n");
                while (getchar() != '\n');
                break;
            }
            save_in_file(&BD, str);
            break;
        }
        case 7: {
            printf("Введите название файла(.bin), откуда хотите считать данные в БД\n");
            char str[64];
            if (scanf("%s", str) != 1) {
                printf("!      Input_Error      !\n");
                while (getchar() != '\n');
                break;
            }
            read_in_file(&BD, str);
            }
        }
        printf("0 - Выход\n");
        printf("1 - Добавление рабочего\n");
        printf("2 - Вывод БД на экран\n");
        printf("3 - Изменение элемента БД\n");
        printf("4 - Удаление по индексу\n");
        printf("5 - Поиск по имени и профессии\n");
        printf("6 - Сохранение БД в файл\n");
        printf("7 - Загрузка из файла\n");
        if (scanf("%i", &k) != 1) {
            printf("!      Input_Error      !\n");
            while (getchar() != '\n');
            break;
        }
    }
    free_v(&BD);
    printf("End of the program");
    return 0;
}