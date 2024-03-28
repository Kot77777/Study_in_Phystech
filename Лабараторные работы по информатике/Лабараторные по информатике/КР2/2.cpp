#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    float total = 0, k = 0;
    int counter = 0, counter1 = 0;
    for (int i = 0; i < N; i++){
        if (a[i] <= 5) {
                counter = 0;
                counter1++;
        }
        else
        {
            counter++;
            if (counter == 6){
                for (int j = 0; j < 6; j++){
                    total += a[i - j];
                    k += 1;
                }
            }
            if (counter > 6){
                total += a[i];
                k += 1;
            }
        }
    }
    if (total == 0) cout << "0.0";
    else{
        cout << fixed << setprecision(1);
        cout << total/(k+counter1);
    }
    delete[] a;
    return 0;

}
