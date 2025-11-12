import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<ArrayList<String>> nestedList = new ArrayList<>();
        
        // Добавляем элементы в списки
        nestedList.add(new ArrayList<>(List.of("apple", "banana")));
        nestedList.add(new ArrayList<>(List.of("cherry", "grape")));
        nestedList.add(new ArrayList<>(List.of("mango", "kiwi")));
        
        System.out.println(nestedList.get(0).get(1));  // выводит 'banana'
    }
}