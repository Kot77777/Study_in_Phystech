#include <iostream>
#include <string>
using namespace std;

class Weapon
{
public:
    virtual void Shoot() = 0; //делаем читсто виртуальной
    void Foo()
    {
        cout << "Foo" << endl;
    }
};

class Gun: public Weapon
{
public:
    void Shoot() override
    {
        cout << "BANG"  << endl;
    }
};

class SubmachinGun: public Gun
{
public:
    void Shoot() override
    {
        cout << "BANG BANG BANG" << endl;
    }
};

class Bazooka: public Weapon
{
public:
    void Shoot() override
    {
        cout << "BANDBUM" << endl;
    }
};

class Knife: public Weapon
{
public:
    void Shoot() override
    {
        cout << "VGUCH" << endl;
    }
};

class Player
{
public:
    void Shoot(Weapon* weapon)
    {
       weapon->Shoot();
    }
};
int main()
{
    Player player;
    Weapon* lists[4];
    lists[0] = new Gun;
    lists[1] = new SubmachinGun;
    lists[2] = new Bazooka;
    lists[3] = new Knife;
    int k = 0;
    string l;
    while (true){
        cout << "Vvedite nomer orygiy" << endl;
        cin >> k;
        player.Shoot(lists[k]);
        cin >> l;
        if (l == "yes")
        {
            break;
        }
    }
    return 0;
}
