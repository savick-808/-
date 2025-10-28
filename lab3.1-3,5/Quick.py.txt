def quicksort(arr):
    if len(arr) <= 1:
        return arr  # Базовый случай: пустой список или список из одного элемента уже отсортированы.
    
    pivot = arr[len(arr) // 2]  # Выбираем опорный элемент (pivot) из середины списка.
    
    # Разделяем элементы на три категории:
    # Элементы меньше pivot, равные pivot и больше pivot.
    less = [x for x in arr if x < pivot]
    equal = [x for x in arr if x == pivot]
    greater = [x for x in arr if x > pivot]
    
    # Рекурсивно сортируем подсписки и соединяем их в нужный порядок.
    return quicksort(less) + equal + quicksort(greater)

# Пример использования
if __name__ == "__main__":
    # Исходный массив
    unsorted_array = [64, 34, 25, 12, 22, 11, 90]
    print("Исходный массив:", unsorted_array)
    
    # Сортировка
    sorted_array = quicksort(unsorted_array)
    
    # Результат
    print("Отсортированный массив:", sorted_array)