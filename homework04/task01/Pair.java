package homework04.task01;

// Обобщенный класс Pair, который хранит два объекта совместимых типов T и V.
class Pair<T, U> {
    T first;
    U second;
    
    // Конструктор класса Pair, принимающий два объекта совместимых типов.
    Pair(T a, U b) {
        first = a;
        second = b;
    }
    
    // Методы для получения первого и второго объектов.
    T getFirst() {
        return first;
    }
    
    U getSecond() {
        return second;
    }

    // Методы для установления значений первого и второго объектов.
    void setFirst(T f) {
        first = f;
    }
    
    void setSecond(U s) {
        second = s;
    }
}

