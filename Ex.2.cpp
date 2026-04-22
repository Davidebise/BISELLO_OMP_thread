
#include "Ex.2.h"

#include <iostream>
#include<thread>
#include<vector>
#include<omp.h>

using namespace std;

void Exercise2() {
    int somma=0;
    vector<int> a1= {3,4,5,6,7,8,2,6,1};
    vector<int> a2= {4,8,3,4,6,1,3,6,7};
#pragma omp parallel for
    for (int i = 0; i < 10; i++) {
#pragma omp critical
        {
            somma+= a1[i] * a2[i];
        }
    }
    cout<<somma<<endl;
}