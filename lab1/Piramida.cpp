#include <iostream>
#include <vector>

// Функция выравнивает кучу снизу вверх (heapify downwards)
void heapify(std::vector<int>& arr, int n, int root) {
    int largest = root;           // На начальном этапе корень считается наибольшим
    int left_child = 2 * root + 1;// Формула расчета левого ребенка
    int right_child = 2 * root + 2;// Формула расчета правого ребенка
    
    // Если левый ребенок существует и больше корня
    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;
    
    // Если правый ребенок существует и больше самого большого элемента
    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;
    
    // Если самый большой элемент не является корнем, меняем их местами
    if (largest != root) {
        std::swap(arr[root], arr[largest]);
        // Рекурсивно восстанавливаем структуру дерева под новым корнем
        heapify(arr, n, largest);
    }
}

// Основная функция пирамидальной сортировки
void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Строим max-кучу (перестроение дерева сверху вниз)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Один за другим извлекаем элементы из кучи и переносим их в конец массива
    for (int i = n - 1; i > 0; i--) {
        // Меняем местами первый и последний элементы
        std::swap(arr[0], arr[i]);
        // Исправляем дерево (heapify), учитывая уменьшение размера кучи
        heapify(arr, i, 0);
    }
}

// Функция для вывода массива
void printArray(const std::vector<int>& arr) {
    for (auto& elem : arr)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// Основная программа
int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    std::cout << "Исходный массив: ";
    printArray(arr);
    
    heapSort(arr);  // Вызов функции сортировки
    
    std::cout << "Отсортированный массив: ";
    printArray(arr);
    
    return 0;
}