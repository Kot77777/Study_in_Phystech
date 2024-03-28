#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    void Use()
    {
        cout << "I go" << endl;
    }
};

class Airplane
{
public:
    void Use()
    {
        cout << "I fly" << endl;
    }
};

class FlyingCar: public Car, public Airplane
{

};


int main()
{
    FlyingCar fc;

    ((Car)fc).Use();// приведение типа к Car
    ((Airplane)fc).Use();

    return 0;
}
