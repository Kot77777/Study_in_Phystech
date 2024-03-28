#include <iostream>
#include <string>
using namespace std;

class A
{
protected:
    int x, y;
public:
    A(int a, int b) : x(a), y(b) {};
};

int main() {
    A a1(1, 1);
    A a2 = A(1,1);
    A a3 = {1, 1};
    return 0;
}
