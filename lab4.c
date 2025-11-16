#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

long long cnt = 0;

void update_arr(int *arr, int *cp, int n) { //функция перезаписи массива, для того, чтобы на тех же данных проводить 3 сортировки
    memcpy(arr, cp, n * sizeof(int));
}

void swap(int *x, int *y) { //обобщенная функция для перестановки элементов(реализованная для bubble_sort and selection_sort)
    int cash = *x;
    *x = *y;
    *y = cash;
    cnt++;
}

void bubble_sort(int *arr, int n) {//сортировка пузырьком
    int cash;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selection_sort(int arr[], int n) {//сортировка выбором
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));// создание динамических массивов, т.к. данные большие

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            cnt++;
        } else {
            arr[k] = R[j];
            j++;
            cnt++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        cnt++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        cnt++;
    }
    free(L);
    free(R);//освобождение памяти
}

void merge_sort(int arr[], int left, int right) {//сортировка слиянием и там спец. функция для нее выше
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void time_excited(int *arr, int n, const char *str) {
    cnt = 0;
    clock_t t; 
    t = clock();
    if (strcmp(str, "bubble_sort") == 0) {
        bubble_sort(arr, n);
    }
    else if (strcmp(str, "selection_sort") == 0) {
        selection_sort(arr, n);
    } 
    else if (strcmp(str, "merge_sort") == 0) {
        merge_sort(arr, 0, n-1);
    }
    t = clock() - t; 
    double seconds = ((double)t)/CLOCKS_PER_SEC; //подсчет времени исполнения одной из сортировок
    printf("Время исполнения сортировки %s for array with %i elements: %f секунд\n", str, n, seconds);
    printf("Количество перестановок: %lld\n", cnt);//вывод перестановок и времени исполннения той или иной сортировки
}


int main() {

    int *arr1 = (int*)malloc(sizeof(int) * 11);
    int *arr2 = (int*)malloc(sizeof(int) * 1001);
    int *arr3 = (int*)malloc(sizeof(int) * 10001);
    int *arr4 = (int*)malloc(sizeof(int) * 100001);

    int *cp1 = (int*)malloc(sizeof(int) * 11);
    int *cp2 = (int*)malloc(sizeof(int) * 1001);
    int *cp3 = (int*)malloc(sizeof(int) * 10001);
    int *cp4 = (int*)malloc(sizeof(int) * 100001);//выделение динамической памяти для массивов и их копий(для того, чтобы не потерять исходные сгенерированные данные)

    int n1 = 10, n2 = 1000, n3 = 10000, n4 = 100000;//создание переменных для размеров массивов(чтобы проще обращаться)

    for (int i = 0; i < n1; i++) {
        arr1[i] = rand();
        cp1[i] = arr1[i];
    }

    for (int i = 0; i < n2; i++) {
        arr2[i] = rand();
        cp2[i] = arr2[i];
    }

    for (int i = 0; i < n3; i++) {
        arr3[i] = rand();
        cp3[i] = arr3[i];
    }

    for (int i = 0; i < n4; i++) {
        arr4[i] = rand();
        cp4[i] = arr4[i];
    }//заполнение массивов и их копий

    time_excited(arr1, n1, "bubble_sort");
    update_arr(arr1, cp1, n1);
    time_excited(arr1, n1, "selection_sort");
    update_arr(arr1, cp1, n1);
    time_excited(arr1, n1, "merge_sort");
    printf("Waiting next sorting array\n");
    printf(". . .\n");

    time_excited(arr2, n2, "bubble_sort");
    update_arr(arr2, cp2, n2);
    time_excited(arr2, n2, "selection_sort");
    update_arr(arr2, cp2, n2);
    time_excited(arr2, n2, "merge_sort");
    printf("Waiting next sorting array\n");
    printf(". . .\n");

    time_excited(arr3, n3, "bubble_sort");
    update_arr(arr3, cp3, n3);
    time_excited(arr3, n3, "selection_sort");
    update_arr(arr3, cp3, n3);
    time_excited(arr3, n3, "merge_sort");
    printf("Waiting next sorting array\n");
    printf(". . .\n");

    time_excited(arr4, n4, "bubble_sort");
    update_arr(arr4, cp4, n4);
    time_excited(arr4, n4, "selection_sort");
    update_arr(arr4, cp4, n4);
    time_excited(arr4, n4, "merge_sort");
    printf("THE END OF PROGRAM");//реализация вывода данных + вновь заполнение массивов исходными (рандомно сгенерированными) данными

    free(arr1); free(cp1);
    free(arr2); free(cp2);
    free(arr3); free(cp3);
    free(arr4); free(cp4);//освобождение памяти

    return 0;
}