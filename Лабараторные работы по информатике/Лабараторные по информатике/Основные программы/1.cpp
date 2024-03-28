#include <iostream>
using namespace std;
int maximum(int n, int m){
    if (n > m)
        return n;
    return m;
}
void sorty(int a[20][20], int N, int M, int b[20][20]){
     b[0][0] = a[0][0];
     for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (i==0 && j > 0)
                b[i][j] = b[i][j-1] + a[i][j];
            if (j == 0 && i > 0)
                b[i][j] = b[i-1][j] + a[i][j];
            if (i!=0 && j!=0)
                b[i][j] = a[i][j] + maximum(b[i-1][j], b[i][j-1]);
        }
    }
    a[N-1][M-1] = 0;
    int i = N -1;
    int j = M - 1;
    while(i!=0 || j!=0){
        if (i==0){
            a[i][j-1] = 0;
            j=j-1;
        }
        else if (j==0){
            a[i-1][j] = 0;
            i = i - 1;
        }
            else if (b[i-1][j] >= b[i][j-1]){
                a[i-1][j] = 0;
                i = i - 1;}
                else{ a[i][j-1] = 0;
                        j = j - 1;}
    }
}
int main(){
    int N, M, i = 0, j = 0, A, total = 0;
    cin >> M >> N;
    int a[20][20];
    int b[20][20];
    int a_res[20][20];
    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            a_res[i][j] = a[i][j];
        }
    }
    total += a[0][0];
    cin >> A;
    i = 0;
    j = 0;
    while(A!=0){
        for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            a_res[i][j] = a[i][j];
        }
    }
        sorty(a, N, M, b);
        if(i == N-1){
                j+=1;
                total+=a_res[i][j+1];
                A-=1;
        }
        else{ if (j==M-1){
                i+=1;
                total+=a_res[i+1][j];
                A-=1;
        }
        else{
            while(((i+1)!=(N-1)) || ((j+1)!=(M-1))){
            if(a[i+1][j] != 0 || a[i][j+1] != 0){
            if (a[i+1][j] == 0){
                i+=1;
                total+=a_res[i+1][j];
                A-=1;
            }
            else{ if (a[i][j+1] == 0){
                j+=1;
                total+=a_res[i][j+1];
                A-=1;
        }}}
        else{
            if(a_res[i+1][j]!=a[i+1][j]){
                i+=1;
                total+=a_res[i+1][j];
                A-=1;
            }
            else{
                j+=1;
                total+=a_res[i][j+1];
                A-=1;
            }
        }
        if(A==0){
            break;
        }
    }
        }
        }
        cout << total << " ";}
    cout << total;
    return 0;
}
