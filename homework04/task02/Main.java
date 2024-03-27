package homework04.task02;

public class Main {
    public static void main(String[] args) {
        // Создание контейнера для строк
        DataContainer<String> stringContainer = new DataContainer<>();

        // Добавление элементов в контейнер
        stringContainer.add("Apple");
        stringContainer.add("Banana");
        stringContainer.add("Orange");

        // Получение и удаление элемента по индексу
        String fruit = stringContainer.get(1);
        System.out.println("Fruit at index 1: " + fruit);
        stringContainer.remove(1);

        // Вывод размера контейнера
        System.out.println("Size of container: " + stringContainer.getSize());
    }
}
