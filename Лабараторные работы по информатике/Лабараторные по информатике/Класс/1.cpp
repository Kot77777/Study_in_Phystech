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
    string planets[11] = {"MERCURY", "VENUS", "EARTH", "MARS", "JUPITER", "SATURN", "URANUS", "NEPTUNE", "PLUTO", "MOON", "SUN"};
    cout << planets[5];

    return 0;
}
