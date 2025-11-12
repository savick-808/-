import java.util.PriorityQueue;

public class PriorityQueueExample {
    public static void main(String[] args) {
        // Создание приоритетной очереди целых чисел (по умолчанию сортирует по возрастанию)
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Добавление элементов
        pq.add(10);
        pq.add(5);
        pq.add(8);
        pq.add(3);

        // Извлечение элементов (элемент с наименьшим значением будет извлечён первым)
        while (!pq.isEmpty()) {
            System.out.print(pq.poll() + " ");  // Вывод: 3 5 8 10
        }
    }
}