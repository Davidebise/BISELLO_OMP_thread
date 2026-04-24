
#include "Exercise7.h"
#include <iostream>
#include<thread>
#include<omp.h>

using namespace std;

void Exercise7() {
    float sum=0;  //serie di leibniz tende a pi/4
    bool sign=true; //true +, false -
#pragma omp parallel for num_threads(2)
    for(int i=1;i<100;i+=4) {
#pragma omp critical
        {
            sum+=(float)1/i;
        }
    }
#pragma omp parallel for num_threads(2) //servono due for, uno per sottrarre e uno per aggiungere le frazioni
    for(int i=3;i<100;i+=4) {
#pragma omp critical
        {
            sum-=(float)1/i;
        }
    }
    cout<<"Approssimazione:"<<sum*4<<endl;
}