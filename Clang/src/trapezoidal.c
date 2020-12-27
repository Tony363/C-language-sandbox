#include <stdio.h>

//https://stackoverflow.com/questions/21146540/integrate_by_trapezoidal_rule-rule-in-python

double fx(double x){
    return x*x;
}

double integrate_by_trapezoidal_rule(double (*f)(double),double Ubound,double Lbound,double n){
    double range = (Lbound - Ubound) / n;
    double area = 0.0;
    area += range * f(Ubound)/2.0;
    for(int i=1;i<n;i++){
        area += f(Ubound + i*range);
    }
    area += f(Lbound)/2.0;
    return area * range;
}

double integrate_by_midpont(double (*fx)(double),double Ubound,double Lbound,double n){
    double range = (Lbound - Ubound)/n;
    double area = 0.0;
    for (int i=0;i<n;i++){
        area += fx((Ubound + range/2.0)+i*range);
    }
    area *= range;
    return area;
}

int main (void){
    double area_of_trapezoid = integrate_by_trapezoidal_rule(fx,5,10,100);
    double area_of_midpoint =  integrate_by_midpont(fx,5,10,100);
    printf("%lf\n",area_of_trapezoid);
    printf("%lf\n",area_of_midpoint);
    return 0;
}