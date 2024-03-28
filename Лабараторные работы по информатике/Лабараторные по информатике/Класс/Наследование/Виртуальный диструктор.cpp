#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Vydelit Pamyt" << endl;
    }
    virtual ~A()
    {
        cout << "Osvobogdeny Pamyt" << endl;
    }
};

class B: public A
{
public:
    B()
    {
        cout << "Vydelit Pamyt" << endl;
    }
    ~B() override
    {
        cout << "Osvobogdeny Pamyt" << endl;
    }
};

int main()
{
    A *bptr = new B;// так как используем базовый класс то используем virtual чтобы переопределить это в классах наследниках

    delete bptr;
    return 0;
}
