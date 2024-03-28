#include <iostream>
#include <string>
using namespace std;

class Point
{
private: //не должны быть доступны
    int x;
    int y;

public:

    Point(int valueX, int valueY) //конструктор класса
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

class CoffeeGrinder
{
private:

    bool CheckVoltage()
    {
        return false;
    }

public:
    void Start()
    {
        bool voltageIsNormal = CheckVoltage();

        if(voltageIsNormal)
        {
            cout << "Vjuhhh !" << endl;
        }
        else
        {
            cout << "Beep Beep" << endl;
        }
    }

};

int main()
 {
    Point a(5, 44);
    a.Print();

    Point b(3, 6);
    b.Print();
	return 0;
}
