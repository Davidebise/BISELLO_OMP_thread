#include <iostream>
#include<thread>
#include<omp.h>

using namespace std;

int main() {
    int somma=0;
    int array[]= {3,4,5,6,7,8,2,6,1,7,4,7,2,46,6,635,62,6,42,67,35,2356,8,78,4,335,7,6,453,7,88,6};
    #pragma omp parallel for
    for(const int i : array) {

        #pragma omp critical
        {
            somma+=i;
        }
    }
}