
#include "Ex.5.h"
#include <iostream>
#include<thread>
#include<omp.h>

using namespace std;

void Exercise5() {
    int a1[] = { 1,67,5,4,2,7,2,545,7,12,47,9,10,6,3,42,89,67,1234,51,2};
    int size = sizeof(a1)/sizeof(int);
    int max = 0;
#pragma omp parallel for num_threads(2)  //decisione arbitraria di usare solo 2 thread
    for(int i=0;i<size;i++) {
#pragma omp critical
        {
            if (a1[i] > max) {

                max = a1[i];

            }
        }
    }
    cout<<"Elemento massimo:"<<max<<endl;
}