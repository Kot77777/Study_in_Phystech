#include <iostream>
#include <string>
using namespace std;

class Msg
{
public:
    Msg(string msg)
    {
        this->msg = msg;
    }

    virtual string GetMsg()
    {
        return msg;
    }
private:
    string msg;

};

class Printer
{
public:
    void Print(Msg* msg)
    {
        cout << msg->GetMsg() << endl;
    }
};

class BraketsMsg : public Msg
{
public:
    BraketsMsg(string msg):Msg(msg)
    {

    }
    string GetMsg() override
    {
        return "[" + ::Msg::GetMsg() + "]"; //ÈÌÅÍÍÎ ÁÀÇÎÂÎÃÎ ÊËÀÑÑÀ
    }
};

int main()
{
   BraketsMsg m("Ïðèâåò");

   Printer p;
   p.Print(&m);

    return 0;
}
