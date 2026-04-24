
#include "Ex.10.h"
#include <iostream>
#include <vector>
#include<random>
#include<math.h>
#include <omp.h>

using namespace std;

void Exercise10() {
    srand(time(NULL));
    int n_tentativi=1000000; //esempio: calcolo del pigreco con lancio dei punti all'interno di un quadrato
    int lato_quad=2;
    float x;
    float y;
    int sum=0;
#pragma omp parallel for
    for (int i = 0; i < n_tentativi; i++) {
        #pragma omp critical
        {
            x = (float)(rand() % lato_quad);
            y = (float)(rand() % lato_quad);
            if ((float)pow(x,2) + (float)pow(y,2) <=1.0f) { //verifico se il punto è all'interno del cerchio
                sum++;
            }
        }
    }
    cout<<"approssimazione pi greco:"<<((float)sum/n_tentativi)*4<<endl;
}