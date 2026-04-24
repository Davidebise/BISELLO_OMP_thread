
#include "Ex.9.h"
#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void Exercise9() {
    int a[] = {4, 5, 3, 2, 7, 8, 4, 2, 5, 4, 3};
    int n = sizeof(a) / sizeof(int);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {

    #pragma omp parallel for  //suddivido in pari e dispari perchè altrimenti il parallel non ha senso
            for (int i = 0; i < n; i += 2) {
                if (a[i] > a[i + 1]) {
                    int temp = a[i + 1];
                    a[i + 1] = a[i];
                    a[i] = temp;
                }
            }
        } else {
            // Fase Dispari
#pragma omp parallel for
            for (int i = 1; i < n - 1; i += 2) {
                if (a[i] > a[i + 1]) {
                    int temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                }
            }
        }
    }

    // Stampa il risultato
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
}