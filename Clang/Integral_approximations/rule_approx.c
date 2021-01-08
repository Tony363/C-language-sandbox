#include <stdio.h>
#include <tinyexpr.h>

//https://stackoverflow.com/questions/21146540/integrate_by_trapezoidal_rule-rule-in-python



double integrate_by_trapezoidal_rule(const char *expr,double Ubound,double Lbound,double iter){
    double range = (Lbound - Ubound) / iter,area = 0.0,x,y,e;

    te_variable var[] = {{"x",&x},{"y",&y},{"e",&e}};

    int err;
    te_expr *n = te_compile(expr, var, 3, &err);
    if (n){
        x = Ubound;
        const double r = te_eval(n);

        area += range * r/2.0;
        for(int i=1;i<iter;i++){
            x = (Ubound + i*range);
            te_expr *n = te_compile(expr,var,3,&err);
            const double r = te_eval(n);
            area += r;
        }

        x = Lbound;
        te_expr *n = te_compile(expr,var,3,&err);
        const double final = te_eval(n);

        area += final/2.0;
        
        te_free(n);
    }else {
        printf("\t%*s^\nError near here", err-1, "");
        te_free(n);
    }
    return area * range;
}

double integrate_by_midpont(const char *expr,double Ubound,double Lbound,double iter){
    double range = (Lbound - Ubound) / iter,area = 0.0,x,y,e;

    te_variable var[] = {{"x",&x},{"y",&y},{"e",&e}};
    int err;

    for (int i=0;i<iter;i++){
        x = (Ubound + range/2.0)+i*range;
        te_expr *n = te_compile(expr,var,3,&err);
        if(!n){
            printf("\t%*s^\nError near here", err-1, "");
        }
        const double r = te_eval(n);
        area += r;
        te_free(n);
    }
    area *= range;
    return area;
}

int main (int argc,char *argv[]){

    if (argc < 2) {
        printf("Usage: example2 \"expression\"\n");
        return 0;
    }

    const char *expr = argv[1];
    printf("Evaluating:\n\t%s\n", expr);

    int upperbound,lowerbound,section; 
    scanf("%d",&upperbound);
    scanf("%d",&lowerbound);
    scanf("%d",&section);
    
    double area_of_trapezoid = integrate_by_trapezoidal_rule(expr,upperbound,lowerbound,section);
    double area_of_midpoint =  integrate_by_midpont(expr,upperbound,lowerbound,section);
    printf("%lf\n",area_of_trapezoid);
    printf("%lf\n",area_of_midpoint);

    return 0;
}