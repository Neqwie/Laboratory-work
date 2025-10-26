#include <stdio.h>
// Задание 10

/*
1. Найти сумму отрицательных элементов на побочной
диагонали;
2. Найти наибольший элемент 2-го столбца и его
местоположение;
3. Заменить найденный максимальный элемент во 2-ом
столбце на значение суммы.
*/

int main () {

int sum_minus = 0;
int mx_j2 = -10000000;//типо минимальный элемент
int locatemx = 0;

char* str = (char*)malloc(sizeof(char));//создание динамической строки
printf("Write name your file\n");
scanf("%s", str);
FILE *file = fopen(str, "r");

if (file == NULL) {//обработка ошибки на существование файла
    printf("ERROR file");
    fclose(file);
    free(str);
    return 0;
}
int n, m;
fscanf(file, "%i %i", &n, &m);
int matrix[n][m];
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        fscanf(file, "%i", &matrix[i][j]);
    }
}//считывание самой матрицы
fclose(file);//нам уже не нужен поток, поэтому закрываем его

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if ((i+j == n-1) && (n == m) && (matrix[i][j] < 0)) {
            sum_minus += matrix[i][j];//считывание суммы отрицательных чисел, стоящих на побочной диагонали у квадратной матрицы
        }
        if (j == 1 && mx_j2 < matrix[i][j]) {
            mx_j2 = matrix[i][j];
            locatemx = i;//нахождение максимального элемента и его расположение по строке, так как по условию мы знаем что он точно во 2 столбце, то не считываем положение в строке
        }

    }
}

printf("MAX ELEMENT: %i\n", mx_j2);//вывод самого максимального элемента
printf("LOCATION IT: %i 2\n", locatemx+1);//выводим положение строка столбец максимального элемента

printf("MAX ELEMENT HAS CHANGED IN MATRIX OR NOT?\n");//вывод измененной матрицы, если она была квадратной, то увидим, что не изменилась, так как побочная диагональ только у квадратной матрицы
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] == mx_j2 && sum_minus != 0) {
            printf("%i ",sum_minus);
        } else {
            printf("%i ", matrix[i][j]);
        }
    }
    printf("\n");
}


free(str);
return 0;
}
