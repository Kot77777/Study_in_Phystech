#include <iostream>
#include <string>
using namespace std;

class Gun
{
public:
    virtual void Shoot()
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

class Bazooka: public Gun
{
public:
    void Shoot() override
    {
        cout << "BANDBUM" << endl;
    }
};

class Player
{
public:
    void Shoot(Gun* gun)
    {
       gun->Shoot();
    }
};
int main()
{
    Gun gun;
    SubmachinGun machingun;
    Bazooka bazooka;

    Player player;
    player.Shoot(&bazooka);
    return 0;
}
