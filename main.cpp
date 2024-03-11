//Актуальное задание / ```Создайте иерархию классов для представления
//различных геометрических фигур. Каждая фигура должна иметь метод для
//вычисления площади (calculateArea) и метод для вычисления периметра
//(calculatePerimeter). Реализуйте следующие фигуры:

//Круг (Circle):
//Свойства: радиус (radius).
//Методы: calculateArea и calculatePerimeter для вычисления площади и
//периметра соответственно.

//Прямоугольник (Rectangle):
//Свойства: длина (length) и ширина (width).
//Методы: calculateArea и calculatePerimeter для вычисления площади и
//периметра соответственно.

//Квадрат (Square), который является подклассом прямоугольника:
//Свойства: сторона (side).
//Методы: calculateArea и calculatePerimeter для вычисления площади и
//периметра соответственно. И переопределите методы родительского класса,
//чтобы они соответствовали квадрату.

//Формат сдачи:
//Ссылка на гитхаб проект
//Подписать фамилию и номер группы

#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual float calculateArea() = 0;
    virtual float calculatePerimeter() = 0;
};

class Circle : public Figure {
private:
    float radius;
public:
    Circle(float r)
    : radius(r) {}
    float calculateArea() {
        float area = 3.14 * pow(radius, 2);
        cout << "The area of the circle is " << area << endl;
        return area;
    }
    float calculatePerimeter() {
        float perimeter = 2 * 3.14 * radius;
        cout << "The perimeter of the circle is " << perimeter << endl;
        return perimeter;
    }
};

class Parallelogram : public Figure {
private:
    float m_a;
    float m_b;
    float m_height;
protected:
    float getA() const {
        return m_a;
    }
    float getB() const {
        return m_b;
    }
public:
    Parallelogram(float a, float height, float b = 0.0)
        : m_a(a), m_b(b), m_height(height) {}
    float calculateArea() {
        float area = m_a * m_height;
        cout << "The area of the parallelogram is " << area << endl;
        return area;
    }
    float calculatePerimeter() {
        float perimeter = 2 * (getA() + getB());
        cout << "The perimeter of the parallelogram is " << perimeter << endl;
        return perimeter;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(float a, float b)
    : Parallelogram(a, b, b) {}
    float calculateArea() {
        float area = getA() * getB();
        cout << "The area of the rectangle is " << area << endl;
        return area;
    }
    float calculatePerimeter() {
        float perimeter = 2 * (getA() + getB());
        cout << "The perimeter of the rectangle is " << perimeter << endl;
        return perimeter;
    }
};

class Square : public Parallelogram {
public:
    Square(float a, float b)
    : Parallelogram(a, b, b) {}
    float calculateArea() {
        float area = getA() * getB();
        cout << "The area of the square is " << area << endl;
        return area;
    }
    float calculatePerimeter() {
        float perimeter = 4 * getA();
        cout << "The perimeter of the square is " << perimeter << endl;
        return perimeter;
    }
};

int main() {
    Circle circle(13.4);
    Parallelogram parallelogram(12.4, 7.7);
    Rectangle rectangle(14.0, 8.2);
    Square square(17.5, 17.5);
    parallelogram.calculateArea();
    circle.calculateArea();
    rectangle.calculateArea();
    square.calculateArea();
    parallelogram.calculatePerimeter();
    circle.calculatePerimeter();
    rectangle.calculatePerimeter();
    square.calculatePerimeter();
}
