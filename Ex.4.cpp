
#include "Ex.4.h"
#include <iostream>
#include<thread>
#include<vector>
#include<omp.h>

using namespace std;

void Exercise4() {
    vector<vector<int>> a1= {
        {3, 4, 5},
        {6, 7, 8},
        {2, 6, 1}
    };
    vector<vector<int>> a2= {
        {3, 4, 5},
        {6, 7, 8},
        {2, 6, 1}
    };
    int n = a1.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
#pragma omp critical
            {
                result[i][j] = a2[i][j]*a1[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<result[i][j]<<"  ";
        }
        cout<<endl;
    }
}