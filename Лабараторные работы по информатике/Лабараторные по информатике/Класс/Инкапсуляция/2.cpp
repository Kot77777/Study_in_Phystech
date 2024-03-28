#include <iostream>
#include <string>

using namespace std;

class vector_ {
public:
    double x=0, y=0, z=0, scalar = 0;
    void sum(vector_& v1, vector_& v2) {
        x = v1.x + v2.x;
        y = v1.y + v2.y;
        z = v1.z + v2.z;
    }
    void minuss(vector_ v1, vector_ v2) {
        x = v1.x - v2.x;
        y = v1.y - v2.y;
        z = v1.z - v2.z;
    }
    void scal(vector_ v1, vector_ v2){
        scalar = v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
    }
    void vect(vector_ v1, vector_ v2){
        x = v1.y*v2.z - v2.y*v1.z;
        y = v1.x*v2.z - v2.x*v1.z;
        z = v1.x*v2.y - v2.x*v1.y;
    }
};

int main () {
    vector_ v1 = {1,2,3};
    vector_ v2 = {2,0,0};
    vector_ v;
    v.sum(v1, v2);
    cout << v.x << " " << v.y << " " << v.z << endl;
    v.minuss(v1, v2);
    cout << v.x << " " << v.y << " " << v.z << endl;
    v.scal(v1, v2);
    cout << v.scalar << endl;
    v.vect(v1, v2);
    cout << v.x << " " << v.y << " " << v.z << endl;
    return 0;
}
