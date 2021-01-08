#include <stdio.h>
#include <math.h>

// #define M_PI 3.14159265358979323846

double sphere_volume(double radius){
    double volume;
    volume = ((double)4/(double)3)*(M_PI)*radius*radius*radius;
    return volume;
}

double polynomial(double x){
    double poly;
    poly = (3*x*x*x*x*x) + (2*x*x*x*x) - (5*x*x*x) -(x*x) + (7*x) -6;
    return poly;
}

int main(void){
    double radius = 10;
    printf("%lf\n",sphere_volume(radius));
    printf("%lf\n",polynomial(radius));
    return 0;
}