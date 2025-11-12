import java.util.LinkedList;
import java.util.Deque;

public class DequeExample {
    public static void main(String[] args) {
        Deque<Integer> deque = new LinkedList<>();

        // Добавление элементов в конец
        deque.offerLast(1);  // Или addLast()
        deque.offerLast(2);

        // Добавление элементов в начало
        deque.offerFirst(0);  // Или addFirst()

        // Вывод содержимого
        for(Integer num : deque) {
            System.out.print(num + " ");
        }
        System.out.println();  // Выведет: 0 1 2