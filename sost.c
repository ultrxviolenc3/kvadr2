#include <stdio.h>
#include <math.h>
double f1(double x)
{
	return sin(x);
	}
	double f2(double x)
	{
		return 1.0 / x;
		}
		double f3(double x)
		{
			return 10.0/(1.0 +25.0*x*x);
			}
double exact_integral1(double a,double b) 
{
   return -cos(b)+cos(a);
}
double exact_integral2(double a,double b) 
{
   return log(fabs(b))-log(fabs(a));
}
double exact_integral3(double a,double b) 
{
  return 2*atan(5*b)-2*atan(5*a);
}
double chebyshev_integral(double a,double b,double (*f)(double)) {
    double sqrt2 = sqrt(2.0);
    double x1=(a+b)/2.0-(sqrt2/4.0)*(b-a);
    double x2=(a+b)/2.0;
    double x3=(a+b)/2.0 +(sqrt2 / 4.0)*(b-a);
    double w=(b-a)/3.0;
    return w*(f(x1)+ f(x2)+f(x3));
}
int main() {
	double a1,a2,a3,b1,b2,b3; double h;double ex,pog;  int N;
	double app=0.0;
	a1=0; b1=M_PI; 
	a2=1; b2=2;
	a3=-1; b3=1;
	N=10;
	h=(b1-a1)/(N-1);
	ex=exact_integral1(a1,b1);
	while(a1<b1)
	{
		app+=chebyshev_integral(a1,a1+h,f1);
		a1+=h;
		}
		pog=fabs(ex-app);
	printf("sinx        Priblij: %.6f        Tocnoe: %.6f       Pogr: %.6f\n",app,ex,pog);
	h=(b2-a2)/(N-1); app=0.0;
	ex=exact_integral2(a2,b2);
	while(a2<b2)
	{
		app+=chebyshev_integral(a2,a2+h,f2);
		a2+=h;
		}
		pog=fabs(ex-app);
		printf("1/x        Priblij: %.6f        Tocnoe: %.6f       Pogr: %.6f\n",app,ex,pog);
		h=(b3-a3)/(N-1); app=0.0;
		ex=exact_integral3(a3,b3);
		
		while(a3<b3)
	{
		app+=chebyshev_integral(a3,a3+h,f3);
		a3+=h;
		}
		pog=fabs(ex-app);
		printf("10/(1+25*x^2)        Priblij: %.6f        Tocnoe: %.6f       Pogr: %.6f\n",app,ex,pog);
 return 0;
}

