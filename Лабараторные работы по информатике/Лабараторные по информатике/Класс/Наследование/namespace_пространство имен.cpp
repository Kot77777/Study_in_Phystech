#include <iostream>
#include <string>
using namespace std;

namespace firstNS
{
    void Foo()
    {
       cout << 1 << endl;
    }
}

namespace secondNS
{
    void Foo()
    {
        cout << 2 << endl;
    }
}

int main()
{
    secondNS::Foo();
    return 0;
}
