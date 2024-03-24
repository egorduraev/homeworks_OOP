/*Задание актуально, Успехов)

```задание, включающее в себя использование абстрактных классов,
интерфейсов и принципов ООП (инкапсуляции, наследования и полиморфизма):

Задание: Разработка системы управления транспортными средствами

Создайте систему управления транспортными средствами с использованием
принципов объектно-ориентированного программирования. В системе должны
присутствовать следующие классы и интерфейсы:

Абстрактный класс Vehicle:
Содержит общие свойства и методы для всех видов транспортных средств.
Свойства: int id (уникальный идентификатор), String brand (марка),
String model (модель), int year (год выпуска).
Методы:
void startEngine() - запуск двигателя (реализация в подклассах).
void stopEngine() - остановка двигателя (реализация в подклассах).
void accelerate(int speed) - увеличение скорости на указанное значение
(реализация в подклассах).
void brake() - прекращение движения (реализация в подклассах).
abstract void displayInfo() - вывод информации о транспортном средстве
(реализация в подклассах).

Интерфейс Flyable (летающие транспортные средства):
Методы: void takeOff(), void land().

Интерфейс Swimmable (плавающие транспортные средства):
Методы: void startSwimming(), void stopSwimming().

Класс Car (автомобили):
Наследует от Vehicle.
Реализует методы абстрактного класса displayInfo.
Добавляет свойства: int fuelCapacity (емкость топливного бака),
int currentFuelLevel (текущий уровень топлива).
Реализует методы:
void startEngine() - запуск двигателя автомобиля.
void stopEngine() - остановка двигателя автомобиля.
void accelerate(int speed) - увеличение скорости автомобиля на указанное значение.
void brake() - прекращение движения автомобиля.
void refuel(int liters) - заправка автомобиля (увеличение уровня топлива).

Класс Aircraft (самолеты):
Наследует от Vehicle.
Реализует методы абстрактного класса displayInfo.
Реализует методы интерфейса Flyable.
Добавляет свойства: int maxAltitude (максимальная высота полета),
boolean isFlying (флаг состояния полета).
Реализует методы:
void startEngine() - запуск двигателя самолета.
void stopEngine() - остановка двигателя самолета.
void takeOff() - взлет самолета.
void land() - посадка самолета.

Класс Boat (лодки):
Наследует от Vehicle.
Реализует методы абстрактного класса displayInfo.
Реализует методы интерфейса Swimmable.
Добавляет свойства: int maxSpeed (максимальная скорость на воде),
boolean isSailing (флаг состояния движения по воде).
Реализует методы:
void startEngine() - запуск двигателя лодки.
void stopEngine() - остановка двигателя лодки.
void startSwimming() - начало движения лодки по воде.
void stopSwimming() - прекращение движения лодки по воде.

Главный класс Main для проверки:
Создайте объекты различных транспортных средств (автомобиль, самолет, лодка).
Продемонстрируйте их работу, вызывая соответствующие методы (запуск двигателя,
движение, взлет, посадка и т.д.).
Выведите информацию о каждом транспортном средстве с использованием метода displayInfo.*/

#include <iostream>
#include <cmath>

using namespace std;

class Vehicle {
public:
    int m_id;
    string m_brand;
    string m_model;
    int m_year;
    bool m_engineStatus = false;
    int m_speed = 0;

    Vehicle(int id, string brand, string model, int year) : m_id(id), m_brand(brand), m_model(model), m_year(year) {}

    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void accelerate(int speed) = 0;
    virtual void brake() = 0;
    virtual void displayInfo() = 0;
};

class IFlyable {
public:
    virtual void takeOff() = 0;
    virtual void land() = 0;
};

class ISwimmable {
public:
    virtual void startSwimming() = 0;
    virtual void stopSwimming() = 0;
};

class Car : public Vehicle {
private:
    int m_fuelCapacity;
    int m_currentFuelLevel;
public:
    Car(int id, string brand, string model, int year, int fuelCapacity, int currentFuelLevel) : Vehicle(id, brand, model, year), m_fuelCapacity(fuelCapacity), m_currentFuelLevel(currentFuelLevel) {}

    void startEngine() override {
        m_engineStatus = true;
        cout << "The car engine is running" << endl;
    }
    void stopEngine() override {
        m_engineStatus = false;
        m_speed = 0;
        cout << "The car engine is stopped" << endl;
    }
    void accelerate(int speed) override {
        if (m_engineStatus) m_speed += speed;
        else cout << "The car engine is not running" << endl;
    }
    void brake() override {
        m_speed = 0;
    }
    void refuel(int liters) {
        if (liters + m_currentFuelLevel >= m_fuelCapacity) {
            m_currentFuelLevel = m_fuelCapacity;
            cout << "Full tank!" << endl;
        } else {
            m_currentFuelLevel += liters;
            cout << "Fuel level: " << m_currentFuelLevel << endl;
        }
    }
    void motion(int distance) {
        float currentFuel = m_currentFuelLevel;
        float diff = ((currentFuel / distance) * 100);
        int i_diff = round(diff);
        m_currentFuelLevel = m_currentFuelLevel - i_diff;
    }
    void displayInfo() override {
        cout << "Automobile" << endl
             << "Unique identificator: " << m_id << endl
             << "Brand: " << m_brand << endl
             << "Model: " << m_model << endl
             << "Year of issue: " << m_year << endl
             << "Engine is " << (m_engineStatus ? "working" : "stopped") << endl
             << "Current speed: " << m_speed << endl
             << "Fuel level: " << m_currentFuelLevel << " liters" << endl << endl;
    }
};

class Aircraft : public Vehicle, public IFlyable {
private:
    int m_maxAltitude;
    bool m_isFlying = false;
public:
    Aircraft(int id, string brand, string model, int year, int maxAltitude) : Vehicle(id, brand, model, year), m_maxAltitude(maxAltitude) {}

    void startEngine() override {
        m_engineStatus = true;
        cout << "Aircraft engine started" << endl;
    }
    void stopEngine() override {
        m_engineStatus = false;
        cout << "Airplane engine stopped" << endl;
    }
    void accelerate(int speed) override {
        if (m_engineStatus) m_speed += speed;
        else cout << "The aircraft engine is not running" << endl;
    }
    void brake() override {
        m_speed = 0;
    }
    void takeOff() override {
        m_isFlying = true;
        cout << "The aircraft took off"<< endl;
    }
    void land() override {
        m_isFlying = false;
        cout << "The aircraft landed"<< endl;
    }
    void displayInfo() override {
        cout << "Aircraft" << endl
             << "Unique identificator: " << m_id << endl
             << "Brand: " << m_brand << endl
             << "Model: " << m_model << endl
             << "Year of issue: " << m_year << endl
             << "Maximum height: " << m_maxAltitude << endl
             << "Engine is " << (m_engineStatus ? "working" : "stopped") << endl
             << "Current speed: " << m_speed << endl
             << "Aircraft " << (m_isFlying ? "in the air" : "on the ground") << endl << endl;
    }
};

class Boat : public Vehicle, public ISwimmable {
private:
    int m_maxSpeed;
    bool m_isSailing = false;
public:
    Boat(int id, string brand, string model, int year, int maxSpeed) : Vehicle(id, brand, model, year), m_maxSpeed(maxSpeed) {}

    void startEngine() override {
        m_engineStatus = true;
        cout << "Boat engine started" << endl;
    }
    void stopEngine() override {
        m_engineStatus = false;
        cout << "Boat engine stopped" << endl;
    }
    void accelerate(int speed) override {
        if (m_engineStatus) m_speed += speed;
        else cout << "The boat engine is not running" << endl;
    }
    void brake() override {
        m_speed = 0;
    }
    void startSwimming() override {
        m_isSailing = true;
        cout << "The boat floats"<< endl;
    }
    void stopSwimming() override {
        m_isSailing = false;
        cout << "The boat doesn't float"<< endl;
    }
    void displayInfo() override {
        cout << "Boat" << endl
             << "Unique identificator: " << m_id << endl
             << "Brand: " << m_brand << endl
             << "Model: " << m_model << endl
             << "Year of issue: " << m_year << endl
             << "Maximum speed: " << m_maxSpeed << endl
             << "Engine is " << (m_engineStatus ? "working" : "stopped") << endl
             << "Boat " << (m_isSailing ? "floats" : "doesn't float") << endl << endl;
    }
};


int main() {
    Car car(1, "Volkswagen", "Passat", 2012, 80, 44);
    car.displayInfo();
    car.refuel(10);
    car.displayInfo();
    car.accelerate(30);
    car.startEngine();
    car.accelerate(30);
    car.displayInfo();
    car.motion(120);
    car.displayInfo();
    car.refuel(90);
    car.accelerate(80);
    car.displayInfo();
    car.brake();
    car.stopEngine();
    car.displayInfo();
    Aircraft aircraft(2, "Lockheed Martin", "F-35B", 2015, 16000);
    aircraft.displayInfo();
    aircraft.startEngine();
    aircraft.accelerate(190);
    aircraft.takeOff();
    aircraft.displayInfo();
    aircraft.accelerate(1100);
    aircraft.displayInfo();
    aircraft.land();
    aircraft.brake();
    aircraft.stopEngine();
    Boat boat(3, "Fregat", "310 Air", 2021, 40);
    boat.displayInfo();
    boat.startEngine();
    boat.accelerate(20);
    boat.startSwimming();
    boat.displayInfo();
    boat.accelerate(10);
    boat.displayInfo();
    boat.stopSwimming();
    boat.brake();
    boat.stopEngine();
    return 0;
}
