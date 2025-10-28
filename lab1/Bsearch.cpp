#include <iostream>
#include <vector>

// Функция бинарного поиска
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;                  // Нижняя граница диапазона поиска
    int high = arr.size() - 1;    // Верхняя граница диапазона поиска
    
    // Основное тело поиска
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Вычисляем центральную точку
        
        // Если центральный элемент равен цели, возвращаем его индекс
        if (arr[mid] == target) {
            return mid;
        }
        
        // Если цель меньше центрального элемента, сужаем диапазон поиска влево
        if (arr[mid] > target) {
            high = mid - 1;
        }
        // Если цель больше центрального элемента, сужаем диапазон поиска вправо
        else {
            low = mid + 1;
        }
    }
    
    // Если элемент не найден, возвращаем -1
    return -1;
}

// Функция для вывода массива
void printArray(const std::vector<int>& arr) {
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Основная программа
int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};  // Исходный отсортированный массив
    int target = 10;                           // Целевое значение для поиска
    
    std::cout << "Исходный массив: ";
    printArray(arr);
    
    int result = binarySearch(arr, target);     // Вызов функции поиска
    
    if (result != -1) {
        std::cout << "Элемент найден на позиции " << result << "." << std::endl;
    } else {
        std::cout << "Элемент не найден." << std::endl;
    }
    
    return 0;
}