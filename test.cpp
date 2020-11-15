#include <iostream>
#include <time.h>
#include <cblas.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
#define SIZE 1000

int main() {
    float** m1;
    m1 = new float* [SIZE];
    for (int i = 0; i < SIZE; i++)
        m1[i] = new float[SIZE];

    float** m2;
    m2 = new float* [SIZE];
    for (int i = 0; i < SIZE; i++)
        m2[i] = new float[SIZE];

    float** m3;
    m3 = new float* [SIZE];
    for (int i = 0; i < SIZE; i++)
        m3[i] = new float[SIZE];

    m1[0][0]=2.2;
    m2[0][0]=2.2;

    clock_t start, finish;
    double totaltime;
    start = clock();

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    finish = clock();
    totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "version1: "<<endl;
    cout << "Time: " << totaltime << "s！" << endl;


    float* a = new float[SIZE*SIZE];
    float* b = new float[SIZE*SIZE];
    float* c = new float[SIZE*SIZE];
    a[0]=2.2;
    b[0]=2.2;

    start = clock();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, SIZE, SIZE, SIZE, 1.0, a, SIZE, b, SIZE, 0.0, c, SIZE);
    finish = clock();
    totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "openblas: "<<endl;
    cout << "Time: " << totaltime << "s！" << endl;
    delete []a;
    delete []b;
    delete []c;

    m1[0][0]=2.2;
    m2[0][0]=2.2;
    m3[0][0]=0;
    start = clock();
    for(int i=0;i<SIZE;++i) {
        for (int k = 0; k < SIZE; ++k) {
            float s = m1[i][k];
            for (int j = 0; j < SIZE; ++j)
                m3[i][j] += s * m2[k][j];
        }
    }

    finish = clock();
    totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "version2: "<<endl;
    cout << "Time: " << totaltime << "s！" << endl;


    for (int i = 0; i < 10; i++)
        delete[] m1[i];
    delete[] m1;

    for (int i = 0; i < 10; i++)
        delete[] m2[i];
    delete[] m2;

    for (int i = 0; i < 10; i++)
        delete[] m3[i];
    delete[] m3;
}

