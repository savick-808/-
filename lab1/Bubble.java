public class SelectionSortExample {

    // Метод сортировки массива целых чисел методом выбора
    public static void selectionSort(int[] array) {
        int n = array.length;                     // Определяем длину массива
        
        // Перебираем массив от первого до предпоследнего элемента
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;                     // Индекс минимального элемента
            
            // Находим минимальный элемент в оставшейся части массива
            for (int j = i + 1; j < n; j++) {
                if (array[j] < array[minIndex]) { // Если нашли элемент меньше текущего минимального,
                    minIndex = j;                 // запоминаем его индекс
                }
            }
            
            // Меняем местами найденный минимальный элемент с текущим
            int temp = array[i];                  // Сохраняем текущее значение
            array[i] = array[minIndex];           // Ставим минимальный элемент на место текущего
            array[minIndex] = temp;               // Восстанавливаем предыдущее значение на новом месте
        }
    }

    // Тестовая функция для проверки работы сортировки
    public static void printArray(int[] array) {
        System.out.print("Отсортированный массив: ");
        for (int value : array) {
            System.out.print(value + " ");         // Печать элементов массива
        }
        System.out.println();                      // Переход на новую строку
    }

    // Главная точка входа программы
    public static void main(String[] args) {
        int[] exampleArray = {64, 25, 12, 22, 11};
        System.out.print("Исходный массив: ");
        for (int value : exampleArray) {
            System.out.print(value + " ");         // Печать начального состояния массива
        }
        System.out.println();
        
        selectionSort(exampleArray);              // Выполняем сортировку выбором
        printArray(exampleArray);                 // Выводим отсортированный массив
    }
}