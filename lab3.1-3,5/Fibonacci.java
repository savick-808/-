import java.util.Arrays;

class FibonacciSearch {
    // Генерирует числа Фибоначчи вплоть до указанного предела
    private static int fibonacciNumber(int k) {
        if (k <= 1) return k;
        return fibonacciNumber(k - 1) + fibonacciNumber(k - 2);
    }

    // Основная функция поиска по Фибоначчи
    public static int fibonacciSearch(int[] arr, int target) {
        int m = 0; // Индекс числа Фибоначчи
        while (fibonacciNumber(m) < arr.length) {
            m++;
        }

        // Расширяем массив искусственно до ближайшего числа Фибоначчи
        int offset = -1;
        int fMinus2 = fibonacciNumber(m - 2); // F[m-2]
        int fMinus1 = fibonacciNumber(m - 1); // F[m-1]
        int fCurrent = fibonacciNumber(m);    // F[m]

        // Искусственное расширение массива нулями
        while (fCurrent > 1) {
            int i = Math.min(offset + fMinus2, arr.length - 1);
            if (arr[i] < target) {
                fCurrent = fMinus1;
                fMinus1 = fMinus2;
                fMinus2 = fCurrent - fMinus1;
                offset = i;
            } else if (arr[i] > target) {
                fCurrent = fMinus2;
                fMinus1 = fMinus1 - fMinus2;
                fMinus2 = fCurrent - fMinus1;
            } else {
                return i; // Элемент найден
            }
        }

        // Если не найден, возвращаем -1
        return (fMinus1 == 1 && arr[offset + 1] == target) ? offset + 1 : -1;
    }

    