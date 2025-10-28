#include <iostream>
using namespace std;

// Функция объединения двух отсортированных подпоследовательностей
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;                            // Размер левой части
    int n2 = right - mid;                               // Размер правой части
    
    // Создание временных массивов для левого и правого участков
    int L[n1], R[n2];
    
    // Копирование данных в временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Индексы для отслеживания текущей позиции в левом и правом массивах
    int i = 0, j = 0;
    int k = left;                                       // Индекс основного массива
    
    // Объединение элементов из обоих временных массивов в правильный порядок
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {                             // Если левый элемент меньше или равен правому
            arr[k++] = L[i++];                          // Кладём левый элемент в основную последовательность
        } else {
            arr[k++] = R[j++];                          // Иначе кладём правый элемент
        }
    }
    
    // Остаточные элементы из левой части
    while (i < n1) {
        arr[k++] = L[i++];
    }
    
    // Остаточные элементы из правой части
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Рекурсивная функция разделения массива на две части и их сортировки
void mergeSort(int arr[], int left, int right) {
    if (left < right) {                                // Условие остановки рекурсии
        int mid = left + (right - left) / 2;           // Срединный индекс массива
        
        // Рекомбинируем левую половину
        mergeSort(arr, left, mid);
        
        // Рекомбинируем правую половину
        mergeSort(arr, mid + 1, right);
        
        // Объединяем обе половинки
        merge(arr, left, mid, right);
    }
}

// Функция для вывода массива
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Основная программа
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};                // Исходный массив
    int arr_size = sizeof(arr) / sizeof(arr[0]);        // Определение размера массива
    
    cout << "Given array is\n";
    printArray(arr, arr_size);                          // Вывод исходного массива
    
    mergeSort(arr, 0, arr_size - 1);                   // Вызов процедуры сортировки
    
    cout << "\nSorted array is\n";
    printArray(arr, arr_size);                          // Вывод отсортированного массива
    
    return 0;
}