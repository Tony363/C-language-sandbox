//FFT.cpp

#include<iostream>
// #include<conio.h>
#include<curses.h>
#include<math.h>
#include<dos.h>
#include<complex.h>
#define pi  3.141592654

void main()
{
clrscr();
int i,x,y,j,k,j1;
float o,o1;
complex p,q,r,s,w,m,n,alpha,beta,gamma1[10],gamma2[10];
complex y1[10],b[10],a[10],c[10],d[10],gamma[10],u[10],b2[10];
cout<<"Enter the elements of the array(upto 8 inputs):  "<<endl;

for(i=0;i<=7;i++)
{
      cin>>a[i];
}
cout<<endl<<endl<<endl;
cout<<"INPUT SIGNAL:   "<<endl<<endl;
for(i=0;i<=7;i++)
{
   cout<<a[i]<<endl;
}
for(i=0;i<=3;i++)
{
   b[i]=a[2*i];
}
for(i=4,j=3;i<=7,j>=0;i=i+1,j=j-1)
{
   b[i]=a[i-j];
}
for(i=0;i<=1;i++)
{
   c[i]=b[2*i];
}
for(i=2,j=1;i<=3,j>=0;i++,j--)
{
   c[i]=b[i-j];
}
for(i=4,j=0;i<=5,j<=1;i++,j++)
{
    c[i]=b[i+j];
}
for(i=6,j=1;i<=7,j>=0;i++,j--)
{
    c[i]=b[i-j];
}
for(i=0;i<=6;i=i+2)
{
    m=c[i];
    n=c[i+1];
    alpha=m+n;
    beta=m-n;
    b[i]=alpha;
    b[i+1]=beta;
}
for(i=0;i<=4;i=i+4)
{
    p=b[i];
    q=b[i+1];
    r=b[i+2];
    s=b[i+3];
for(k=0+i,j1=0;k<=2+i,j1<=2;k=k+2,j1=j1+2)
 {
	o=cos((2*pi*j1)/4);
	o1=sin((2*pi*j1)/4);
	w=complex(o,-o1);
	gamma[k]=p+real(w)*r;
 }
for(k=1+i,j1=1;k<=3+i,j1<=3;k=k+2,j1=j1+2)
{
	o=cos((2*pi*j1)/4);
	o1=sin((2*pi*j1)/4);
	w=complex(o,-o1);
	gamma[k]=q+(w)*s;
}
}
cout<<endl<<endl<<endl<<endl;
cout<<"FFT OUTPUT:";
cout<<endl<<endl;
for(i=0;i<=7;i=i+1)
{
      y1[i]=gamma[i];
}

								for(k=j1=0;k<=3,j1<=3;k++,j1++)
	{
             	o=cos((2*pi*j1)/8);
		o1=sin((2*pi*j1)/8);
		w=complex(o,-o1);
		gamma1[k]=y1[k]+w*y1[k+4];
	}
	for(k=j1=4;k<=7,j1<=7;k++,j1++)
	{
		o=cos((2*pi*j1)/8);
		o1=sin((2*pi*j1)/8);
		w=complex(o,-o1);
		gamma1[k]=w*y1[k]+y1[k-4];
	}
	for(i=0;i<=7;i++)
	{
		b2[i]=gamma1[i];
		cout<<b2[i]<<endl;
	}
	            getch();
            } 
