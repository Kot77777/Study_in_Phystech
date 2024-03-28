#include <iostream>
#include <string>
using namespace std;

class Weapon
{
private:
    int x;
public:
    Weapon (int x)
    {
        this->x = x;
    }
    int Get()
    {
        return this->x;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Weapon** sp;
    sp = new Weapon*[3];
    for(int i = 0; i < 3; i++)
    {
        sp[i] = new Weapon;
        for (int j = 0; j < 3; j++)
        {
            Weapon k(6);
            sp[i][j] = k;
        }
    }
    Weapon n(5);
    cout << n.Get();

    return 0;
}
