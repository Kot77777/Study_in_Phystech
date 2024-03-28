#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    Car()
    {
        cout << "Constructor car" << endl;
    }
    ~Car()
    {
        cout << "Destructor car" << endl;
    }
    string str1 = "Car hill";
    void Drive()
    {
        cout << "I go" << endl;
    }
};

class Airplane
{
public:
    Airplane()
    {
        cout << "Constructor airplane" << endl;
    }
    ~Airplane()
    {
        cout << "Destructor airplane" << endl;
    }
    string str2 = "Fly hill";
    void Fly()
    {
        cout << "I fly" << endl;
    }
};

class FlyingCar: public Car, public Airplane
{
public:
    FlyingCar()
    {
        cout << "Constructor Flyingcar" << endl;
    }
    ~FlyingCar()
    {
        cout << "Destructor Flyingcar" << endl;
    }

};

int main()
{

   FlyingCar fc;

    return 0;
}
