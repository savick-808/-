def shell_sort(arr):
    # Изначальная длина массива
    n = len(arr)
    
    # Выбор величины промежутков (gap) по формуле gap = floor(gap / 2)
    gap = n // 2
    
    # Главный цикл уменьшения расстояния (gap)
    while gap > 0:
        # Работаем с группами, подобными вставкам
        for i in range(gap, n):
            # Берём текущий элемент для вставки
            current_value = arr[i]
            position = i
            
            # Перемещаемся назад, пока встреченный элемент больше текущего
            while position >= gap and arr[position - gap] > current_value:
                # Перекидываем элемент вперед
                arr[position] = arr[position - gap]
                position -= gap
                
            # Вставляем текущий элемент на правильное место
            arr[position] = current_value
        
        # Уменьшение интервала
        gap //= 2


# Пример использования
if __name__ == "__main__":
    # Исходный массив
    my_list = [64, 34, 25, 12, 22, 11, 90]
    print("Исходный массив:", my_list)
    
    # Сортировка
    shell_sort(my_list)
    
    # Результат
    print("Отсортированный массив:", my_list)