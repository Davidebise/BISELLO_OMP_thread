
#include "Ex.11.h"
#include <iostream>
#include <omp.h>

using namespace std;

void Exercise11() {
    int a[] = {4, 5, 3, 2, 7, 8, 4, 2, 5, 4, 3,6,4,3,5,7,8,2,4,5,6,7,3,9};
    int n = sizeof(a) / sizeof(int);
    int sum=0;
    #pragma omp parallel for num_threads(4) reduction(+:sum)  //reduction è più ottimale, i thread creano copie locali di sum
    for (int i = 0; i < n; i++) {
        sum+=a[i];
    }
    float media=(float)sum/n;
    cout <<"media:"<<media<<endl;
}