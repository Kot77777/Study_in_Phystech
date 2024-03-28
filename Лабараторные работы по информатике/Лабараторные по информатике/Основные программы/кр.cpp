#include <iostream>
using namespace std;
struct gen{
    char p;
    char v;
};
int main()
{
    int n, m;
    bool B = false;
    gen a[100], b[100], c[100];
    char d[100][4][2];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].p >> a[i].v;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i].p >> b[i].v;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> c[i].p >> c[i].v;
    }
    for(int i = 0; i < n; i++){
        d[i][0][0] = a[i].p;
        d[i][0][1] = a[i].v;

        d[i][1][0] = a[i].p;
        d[i][1][1] = b[i].v;

        d[i][2][0] = b[i].p;
        d[i][2][1] = a[i].v;

        d[i][3][0] = b[i].p;
        d[i][3][1] = b[i].v;
    }
    int A = 0;
    for (int i = 0; i < n-m+1; i++){
        for(int l = 0; l < m; l++){
            for (int j = 0; j < 4; j++){
                if (d[i+l][j][0] == c[l].p && d[i+l][j][1] == c[l].v){
                    A += 1;
                    break;}
            }}
            if (A==m){
                cout << i;
                B = true;
                break;
            }
            else{
                A = 0;
            }
        }
    if(B==false){
        cout << "no danger";
    }
    return 0;
}
