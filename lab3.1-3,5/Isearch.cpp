#include <iostream>
#include <vector>

// Функция интерполирующего поиска
int interpolationSearch(const std::vector<int>& arr, int target) {
    int low = 0;                   // Нижняя граница диапазона поиска
    int high = arr.size() - 1;     // Верхняя граница диапазона поиска
    
    // Главное тело поиска
    while ((low <= high) && (target >= arr[low]) && (target <= arr[high])) {
        // Проверка случая одинаковых границ
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        
        // Вычисляем следующую позицию с помощью интерполяционной формулы
        int pos = low + (((double)(high - low) /
                         (arr[high] - arr[low])) *
                        (target - arr[low]));
        
        // Если элемент найден, возвращаем его индекс
        if (arr[pos] == target) {
            return pos;
        }
        
        // Если элемент меньше предполагаемого, двигаемся влево
        if (arr[pos] < target) {
            low = pos + 1;
        }
        // Если элемент больше предполагаемого, двигаемся вправо
        else {
            high = pos - 1;
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
    std::vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int target = 18;               // Целевой элемент для поиска
    
    std::cout << "Исходный массив: ";
    printArray(arr);
    
    int result = interpolationSearch(arr, target);  // Вызов функции поиска
    
    if (result != -1) {
        std::cout << "Элемент найден на позиции " << result << "." << std::endl;
    } else {
        std::cout << "Элемент не найден." << std::endl;
    }
    
    return 0;
}