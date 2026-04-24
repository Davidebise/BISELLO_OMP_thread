
#include "Ex.6.h"
#include <iostream>
#include<thread>
#include<omp.h>

using namespace std;

void Exercise6() {
    int a1[] = { 1,68,5,4,2,7,2,545,7,12,47,9,10,6,3,42,89,67,1234,51,2};
    int size = sizeof(a1)/sizeof(int);
    int n_pari = 0;
#pragma omp parallel for
    for(int i=0;i<size;i++) {
#pragma omp critical
        {
            if (a1[i] % 2 == 0) {
                n_pari++;
            }
        }
    }
    cout<<"Numero di elementi pari:"<<n_pari<<endl;
}