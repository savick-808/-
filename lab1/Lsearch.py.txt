def linear_search(arr, target): 
 
    # Проходим по всему списку с индексами
    for index, element in enumerate(arr):
        # Если текущий элемент совпадает с искомым
        if element == target:
            return index  # Возвращаем индекс совпадающего элемента
    return None  # Если элемент не найден, возвращаем None

# Пример использования
if __name__ == "__main__":
    # Исходный список
    data = [4, 2, 7, 1, 9, 3]
    search_target = 7
    
    result = linear_search(data, search_target)
    
    if result is not None:
        print(f"Элемент {search_target} найден на позиции {result}.")
    else:
        print(f"Элемент {search_target} не найден.")