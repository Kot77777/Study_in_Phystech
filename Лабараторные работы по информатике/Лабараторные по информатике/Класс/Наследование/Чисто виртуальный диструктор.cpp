#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    A()
    {

    }
    virtual ~A() = 0;

};
A::~A() {};

class B: public A
{
public:
    B()
    {

    }
    ~B() override
    {

    }
};

int main()
{
    A *bptr = new B;// так как используем базовый класс то используем virtual чтобы переопределить это в классах наследниках

    delete bptr;
    return 0;
}
