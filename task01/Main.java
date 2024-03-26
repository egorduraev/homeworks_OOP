package homework03.task01;

/*Итератор и итерируемость (Iterable):
Создайте класс MyLinkedList, который будет представлять собой простую односвязную цепочку.
Реализуйте интерфейс Iterable для этого класса. Это позволит перебирать элементы списка 
с помощью цикла for-each.
Напишите методы добавления, удаления и получения элементов из списка в классе MyLinkedList.
Создайте тестовый класс для проверки функциональности MyLinkedList, включая использование 
цикла for-each для перебора элементов списка. */

public class Main {
    public static void main(String[] args) {
        MyLinkedList<Integer> myList = new MyLinkedList<>();
    
        myList.add(1);
        myList.add(2);
        myList.add(3);
        myList.add(4);
        myList.add(5);
        System.out.println(myList.get(3));
        myList.remove(4);
        System.out.println(myList.get(3));

        for (Integer fruit : myList) {
            System.out.println(fruit);
        }
    }
}
