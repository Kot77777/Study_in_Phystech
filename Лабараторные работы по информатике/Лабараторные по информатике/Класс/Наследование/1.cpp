#include <iostream>
#include <string>
using namespace std;

class C1 {
protected:
    int a;
};
class C2 : private C1 {
public:
    C2() {
        a = 42;
    }
};

int main()
{
     C2 data;

    return 0;
}
