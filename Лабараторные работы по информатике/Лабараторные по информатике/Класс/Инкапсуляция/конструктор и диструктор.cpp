#include <iostream>
#include <string>
using namespace std;

class Point
{
private: //не должны быть доступны
    int x;
    int y;

public:

    Point ()//делаем перегрузку
    {
        x = 0;
        y = 0;
    }

    Point(int valueX, int valueY) //конструктор
    {
        x = valueX;
        y = valueY;
    }

    int GetY()
    {
        return y;
    }

    void SetY(int valueY)
    {
        y = valueY*2;
    }

    int GetX () //получение нашего поля из вне класса
    {
        return x;
    }

    void SetX(int valueX)//устанавливает значение для некоторого поля
    {
        x = valueX;
    }
    void Print()
    {
        cout << "x = " << x << "\t y = " << y << endl;
    }
};

class MyClass
{
private:
    int* data;
public:
    MyClass(int size)
    {
        data = new int[size];

        cout << "Объект" << data << "Вызвался конструктор" << endl;
    }

    ~MyClass() //деструктор(только один и не принимает параметров)
    {
        delete[] data;
        cout << "Объект" << data << "Вызвался деструктор" << endl;
    }
};


int main()
 {
    setlocale(LC_ALL, "ru");
    Point a;
    a.Print();

    Point b(4, 14);
    b.Print();

    MyClass n(5);
    MyClass m(10);

	return 0;
}
