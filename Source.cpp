#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#inlcude <math.h>
#define SIZE 1000
using namespace std;

double square(int num, double resolution);
double complex cubicroot(double complex num, double resolution);


int main() {
    double resolution = 0.00001;
    double r1 = 1;
    double complex r2 = -0.5 + sqrt(3) / 2 * I;
    double complex r3 = -0.5 - sqrt(3) / 2 * I;
    double picture[SIZE][SIZE];
    int temp = 0;
    double complex z;
    for (int i = -SIZE / 2; i < SIZE / 2; i++) {
        for (int j = -SIZE / 2; j < SIZE / 2; j++) {
            z = cubicroot(i + j * I);
            //printf("Z = %.2f %+.2fi\n", creal(z), cimag(z));
            if (z == r1) {
                picture[i + SIZE / 2][j + SIZE / 2] = 80;
            }
            else if (z == r2) {
                picture[i + SIZE / 2][j + SIZE / 2] = 160;

            }
            else if (z == r3) {
                picture[i + SIZE / 2][j + SIZE / 2] = 240;
            }
            else {
                picture[i + SIZE / 2][j + SIZE / 2] = 0;
            }
        }
        temp = i + SIZE / 2;
        printf("%d\n", temp);
    }
    shraniBMP(picture, SIZE, SIZE, "slikca.bmp");
    return 0;
}




double square(int num, double resolution) {
    double root = 1;
    double ort = 0;
    while ((root - resolution) > ort) {
        ort = root;
        root = ((num / root) + root) / 2;
    }
    return root;
}

double complex cubicroot(double complex num, double resolution) {
    float complex ort = 0;
    double complex root = num;
    while ((root - resolution) > ort) {
        ort = root;
        root = ort - (ort - 1 / (ort * ort)) / 3;

    }
    return root;
}