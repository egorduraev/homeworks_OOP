package homework03.task02;
import java.util.Arrays;

/*Создайте класс Employee с полями name, age и salary.
Реализуйте интерфейс Comparable<Employee> для сравнения сотрудников по их возрасту.
Создайте компаратор EmployeeSalaryComparator, который будет сравнивать сотрудников по их зарплате.
Напишите тестовый класс для проверки сортировки массива сотрудников с использованием как Comparable, 
так и Comparator. */

public class Main {
    public static void main(String[] args) {
        Employee[] employees = new Employee[3];
        employees[0] = new Employee("Krzysztof", 22, 4000);
        employees[1] = new Employee("Jacek", 28, 7500);
        employees[2] = new Employee("Mateusz", 23, 5200);

        System.out.println("Сортировка по возрасту:");
        Arrays.sort(employees);
        for (Employee emp : employees) {
            System.out.println(emp);
        }

        System.out.println("Сортировка по зарплате");
        Arrays.sort(employees, new EmployeeSalaryComparator());
        for (Employee emp : employees) {
            System.out.println(emp);
        }
    }
}
