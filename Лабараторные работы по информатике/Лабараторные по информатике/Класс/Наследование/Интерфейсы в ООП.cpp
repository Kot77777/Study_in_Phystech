#include <iostream>
#include <string>
using namespace std::cout;

class IBicycle
{
public:
    virtual void TwistTheWheel() = 0;
    virtual void Ride() = 0;
};

class Human
{
public:
    void RideOn(IBicycle & bicycle)
    {
        cout << "Krutim Rul" << endl;
        bicycle.TwistTheWheel();
        cout << endl << "Poechali" << endl;
        bicycle.Ride();
    }
};

class SimpleBicycle: public IBicycle
{
public:
    void TwistTheWheel() override
    {
        cout << "metod TwistWheel() SimpleBycicle" << endl;
    }
    void Ride() override
    {
        cout << "Ride() SimpleBycicle" << endl;
    }
};

class SportBicycle: public IBicycle
{
public:
    void TwistTheWheel() override
    {
        cout << "metod TwistWheel() SportBycicle" << endl;
    }
    void Ride() override
    {
        cout << "Ride() SportBycicle" << endl;
    }
};

int main()
{
    SimpleBicycle sb;
    SportBicycle sportb;

    Human h;
    h.RideOn(sportb);

    return 0;
}
