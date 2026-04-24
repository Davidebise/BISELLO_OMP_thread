
#include "Ex.12.h"

#include <iostream>
#include <omp.h>
using namespace std;

void Exercise12() {
    int righe = 1000;
    int colonne = 1000;

    int matrix[righe][colonne];

#pragma omp parallel for  //non serve il critical , ogni thread scrive in una cella diversa perchè omp suddivide gli indici tra
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            matrix[i][j] = i * j;
        }
    }

    cout<<"cella casuale:"<<matrix[356][234];
}