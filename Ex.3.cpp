#include "Ex.3.h"

#include <iostream>
#include<thread>
#include<vector>
#include<omp.h>

using namespace std;

void Exercise3() {
    int somma=0;
    vector<vector<int>> a1= {
        {3, 4, 5},
        {6, 7, 8},
        {2, 6, 1}
    };
    vector<int> a2= {1,2,3};
#pragma omp parallel for
    for (int i = 0; i < a1.size(); i++) {
        for (int j = 0; j < a1.size(); j++) {
            #pragma omp critical
            {
                somma += a2[i]*a1[i][j];
            }
        }
    }
    cout<<somma<<endl;
}