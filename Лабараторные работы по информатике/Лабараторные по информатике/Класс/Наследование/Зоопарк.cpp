#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

class ZooKeeper {
public:
    int count;
public:
    // —оздаЄм смотрител€ зоопарка
    ZooKeeper()
    {
        count = 0;
    }

    // —мотрител€ попросили обработать очередного звер€.
    // ≈сли зверь был опасный, смотритель фиксирует у себ€ этот факт.
    void handleAnimal(Animal* a)
    {
        if (a->isDangerous())
        {
            this->count++;
        }
    }

    // ¬озвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount()
    {
        return count;
    }
};

class Monkey: public Animal
{
    string getType() override
    {
        return "Monkey";
    }
    bool isDangerous() override
    {
        return false;
    }
};

class Lion: public Animal
{
    string getType() override
    {
        return "Lion";
    }
    bool isDangerous() override
    {
        return true;
    }
};

int main()
{
        ZooKeeper z;
    Monkey *m = new Monkey();
    z.handleAnimal(m);
    delete m;
    m = new Monkey();
    z.handleAnimal(m);
    delete m;
    Lion *l = new Lion();
    z.handleAnimal(l);
    delete l;
    cout << z.getDangerousCount() << endl;

    return 0;
}
