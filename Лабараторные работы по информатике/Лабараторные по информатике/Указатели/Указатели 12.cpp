#include <iostream>
using namespace std;
struct Coon {
    unsigned int id;
	char name[100];
    double weight;
	double food;
};
Coon* find_the_most_fed_cat(Coon* atc, unsigned int n_cats){
    int c = 0;
    for(int i = 1; i < n_cats; i++){
        if ((((*(atc+c)).food)/((*(atc+c)).weight)) < (((*(atc+i)).food)/((*(atc+i)).weight))){
            c = i;
        }
    }
    return (atc+c);
}
int main()
{
    Coon all_the_coons[1000];
    unsigned int n;
    cin >>n;
    for (unsigned int i = 0; i < n; i++)
        cin >>all_the_coons[i].id >>all_the_coons[i].name >>all_the_coons[i].weight >>all_the_coons[i].food;
    cout <<find_the_most_fed_cat(all_the_coons, n)->name <<endl;
    return 0;
}
