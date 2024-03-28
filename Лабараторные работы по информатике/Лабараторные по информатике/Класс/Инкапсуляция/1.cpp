#include <iostream>
#include <string>
using namespace std;

class student {
public:
    string name = "";
    int age = 18;
    student(string name_, int age_, int ball_){
        name = name_;
        age = age_;
        ball = ball_;
        cout << name <<" is born" << endl;
    }
    student(string name_, int age_){
        name = name_;
        age = age_;
        cout << name <<" is born" << endl;
    }
    student(string name_){
        name = name_;
        cout << name <<" is born" << endl;
    }
    student(){
    }
    void drink(int litres){
        age += litres;
        ball -= litres * 2;
    }
    int get_ball(){
        return ball;
    }
    void set_ball(int ball_){
        if ((ball >= 1) && (ball_ <= 10)){
            ball = ball_;
        }
        else{
            cout << "wrong value of ball" << endl;
        }
    }
    ~student(){
        cout << name << " is died" << endl;
    }
private:
    int ball = 10;
};

int main(){
    {
        student Vasia("Vasia", 19);
    }

    student Petia("Petia", 20);
    student Ivan("Ivan", 21);

    //cout << Vasia.age << endl;
    /*Vasia.drink(5);
    cout << Vasia.age << " " << Vasia.get_ball() << endl;
    Vasia.set_ball(9);
    cout << Vasia.age << " " << Vasia.get_ball() << endl;
    Vasia.set_ball(-1);*/
    return 0;
}
