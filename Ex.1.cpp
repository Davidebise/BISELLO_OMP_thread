#include <iostream>
#include <vector>
#include<thread>
#include "Ex.1.h"
using namespace std;
void Exercise1() {
    int somma=0;
    vector<int> array= {3,4,5,6,7,8,2,6,1,7,4,7,2,46,6,635,62,6,42,67,35,2356,8,78,4,335,7,6,453,7,88,6};
    int n = array.size();
#pragma omp parallel for
    for(int i = 0; i < n; i++) {

#pragma omp critical
        {
            somma+=array[i];
        }
    }
    cout<<somma<<endl;
}