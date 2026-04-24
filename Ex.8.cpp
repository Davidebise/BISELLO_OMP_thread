
#include "Ex.8.h"
#include <iostream>
#include<thread>
#include<omp.h>

using namespace std;

void Exercise8() {
    int sum=0;  //serie di leibniz tende a pi/4
    int m[3][3]= {
        {3, 4, 5},
        {6, 7, 8},
        {2, 6, 1}
    };
    int n=sizeof(m[0])/sizeof(m[0][0]); //lunghezza colonna
#pragma omp parallel for num_threads(3)
    for(int i=0;i<n;i++) {
        #pragma omp parallel for num_threads(3)
        for(int j=0;j<n;j++) {
            #pragma omp critical
            {
                sum+=m[i][j];
            }
        }
    }
    cout<<"Somma:"<<sum<<endl;
}