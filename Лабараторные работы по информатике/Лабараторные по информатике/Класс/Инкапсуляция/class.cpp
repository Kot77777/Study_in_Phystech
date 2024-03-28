#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
    int age; // поля класса
	int weight;
	string name;
public: // модификатор доступа
 // свойства/поля класса

    void Print()
    {
        cout << "Name " << name << "\nWeight " << weight << "\nAge " << age << endl;
    }
};
void f(Human & k){
        cout << k.age;
    }


class Point
{
public:
    int x;
    int y;
    void Print()
    {
       cout << "y= " <<  y << "\nx = " << x << "\n" << "z = " << z << endl;
       PrintY();
    }
private:
    int z;

    void PrintY()
    {
     cout << y << endl;
    }
};

void Print()
{


}
int main()
 {
    setlocale(LC_ALL, "ru");
    Human firstHuman;


    Point a;
    a.Print();
	return 0;
}
