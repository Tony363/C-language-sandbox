#include <stdio.h>
#include <tinyexpr.h>

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
    char *str;
    const char *expr = fgets(str,10,stdin);
    printf("Evaluating:\n\t%s\n",expr);
    
    double x,y,e;
    te_variable var[] = {{"x",&x},{"y",&y},{"e",&e}};
    
    int err;
    te_expr *n = te_compile(expr,var,3,&err);
    
    if (n){
        x = scanf("Enter [X]: %lf\n",&x);
        y = scanf("Enter [Y]: %lf\n",&y);
    } else{
        printf("\t%*s^\nError near here", err-1, "");
    }
    double area_of_trapezoid = integrate_by_trapezoidal_rule(fx,5,10,100);
    double area_of_midpoint =  integrate_by_midpont(fx,5,10,100);
    printf("%lf\n",area_of_trapezoid);
    printf("%lf\n",area_of_midpoint);
    return 0;
}