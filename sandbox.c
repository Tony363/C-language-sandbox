#include<stdio.h>
#include<stdlib.h>

#define MAX 15

int decimals();
int print_int();
int compare_int(int first,int second);
int print_plus();
int print_odd(int m,int n);
int print_20(double a,double b);
int integer_N();
int rectangles();
int read_5();

int main(int argc, char *argv[])
{
    //printf("comparing 2 integers\n");
    //printf("enter 2 values:\n");
    //char _1[MAX],_2[MAX];
    //fgets(_1,MAX,stdin);
    //fgets(_2,MAX,stdin);
    //int first = atoi(_1);
    //int second = atoi(_2);
    //compare_int(first,second);
    
    //printf("printing slight dynamic string\n");    
    //double a,b,number;
    //number = first + second;
    //printf("printing first + second number: %lf\n",number);
   // a = 1000;
   // b = 5555;
   // printf("The Formula is:%lf+%lf=%lf\n",a,b,a+b);

   //char str[MAX];
   //printf("enter character string for fgets sample:\n");
   //fgets(str,MAX,stdin);
   //printf("%s\n",str);
   //decimals();
   //print_int();
   //print_plus();
   //int m,n;
   //printf("even or odd:\n");
   //scanf("%d",&m);
   //scanf("%d",&n);
   //print_odd(m,n);
   //double y,z;
   //printf("enter range between intervals:\n");
   //scanf("%le",&y);
   //scanf("%le",&z);
   //print_20(y,z);
   //printf("Read the integer N as the number of input values:\n");
   //integer_N();
   //rectangles();

    read_5();
    return 0;
}

int read_5(){
    int n,i=0,input=1;
    
    printf("please enter N numbers:\n");
    scanf("%d",&n);
    //printf("\n");
    int array[n];
    
    //scanf("%d",&input);
    printf("\n");
    while(i<n && input>0){
        scanf("%d",&input);
        array[i] = input;
        
        i++;
    }
    printf("\n");
    for(int j=0;j<n;j++){
        printf("%d\n",array[(n-1)-j]);
    }
    return 0;
}

int print_20(double y, double z){
	double interval;
	printf("enter interval:\n");
	scanf("%le",&interval);
	double iter = abs(z-y)/interval;
    double iter1 = (z-y)/interval;
	printf("iterations: %.2le %.2le\n",iter,iter1);
    
    for (int i=0;i<interval;i++){
        y<z? printf("%.2f ",y+(iter*i)) : printf("%.2f ",z+(iter*i));     
        printf("%.2f\n",y+(iter1*((interval-i))));
    }   
	return 0;
}
int integer_N(){
    int N,input,avg,max,min,count=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&input);
        max = (i==0)?input:((input>max)?input:max);
        min = (i==0)?max:((input<min)?input:min);
        count = count + input;
    }
    printf("sum is: %d\n",count);
    printf("average is: %lf\n",(double)count/N);
    printf("min: %d max: %d\n",min,max);
    return 0;
}
int rectangles(){
    int w,h;
    printf("enter width and height\n");
    scanf("%d",&w);
    scanf("%d",&h);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            (i!=0 && i!=(h-1))?((j!=0&&j!=(w-1))?printf(" "):printf("%d",i)):printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
int print_odd(int m,int n){
	//while(m>n){
	//	if(m%n==1){
	//		printf("%d\n",m);
	//	}
	//	m--;
	//}
	//return 0;
	//printf("figuring out user input odd or even\n");
	if (m == n){
		return 0;
	}
	else if (m % 2 == 1){
		printf("%d\n",m);
		m++;
		return print_odd(m,n);
		}
	m++;
	return print_odd(m,n);
}

int print_plus(){
	int input,count=0;
	printf("enter number of plus signs to print\n");
	scanf("%d",&input);
	while(count<input){
		printf("+");
		count++;
	}
	printf("\n");
	return 0;
}
int print_int(){
	int count, m,n;
	printf("enter values for printing in loop:\n");
	scanf("%d",&m);
	scanf("%d",&n);

   // m<n? while(m<n){printf("%d\n",m);m++;}:printf("please enter smaller value first");
	if (m<n){
		while(m<n){
			printf("%d",m);
			m++;
		}
		printf("\n");
	}
	else{
		printf("user entered wrong values\n");
	}
	printf("Values were from %d to %d\n",m,n);
}

int compare_int(int first,int second){
    printf("comparing integers:\n");
    if (first<second){
    	printf("%d is less than %d\n",first,second);
    }
    else{
    	printf("%d is not less than %d\n",first,second);
    }
    return 0;
}

int decimals(){
    printf("slight dynamic comparing floats:\n");
    double a,b;
    scanf("%lf",&a);
    scanf("%lf",&b);
    if (a>b){
    	printf("%lf is greater than %lf\n",a,b);
    }
    else{
	printf("%lf is not greater than %lf\n",a,b);
    }
}
