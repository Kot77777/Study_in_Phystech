#include <iostream>
#include <string>
using namespace std;

class Human
{
public:
    Human(string Name)
    {
        this->Name = Name;
        this->Age = 0;
        this->Weight = 0;
    }

    Human(string Name, int Age):Human(Name)
    {
        this->Age = Age;
    }

    Human(string Name, int Age, int Weight):Human(Name, Age)
    {
        this->Weight = Weight;
    }

    string Name;
    int Age;
    int Weight;
};

int main()
{
   Human h("Аристарх", 30, 70);

    return 0;
}
