#include <iostream>
#include <cmath>
using namespace std;
double recRoot(double (*f)(double), double a, double b, double eps)
{ 
	const double MyNull = 1e-12;
    double fa = f(a), fb = f(b), c, fc;
if (fa * fb > 0)
{
	cout << "неверный отрезок\n";
	return -999.0;
}
c = (a + b) / 2.0;
fc = f(c);
if ((fabs(fc) <= MyNull) || (b - a <= eps))
return c;
return
(fa * fc <= 0.0) ? recRoot(f, a, c, eps) : recRoot(f, c, b, eps);
}
int main()
{
	setlocale(LC_ALL, ".1251");
	double root,
		a = 0.1, //левая граница отрезка
		b = 3.5, //правая граница отрезка
		eps = 1e-5; //точность вычислений
	double fun(double);//прототип функции
	root = recRoot(fun, a, b, eps);
	cout << "\n корень=" << root << "\n";
	return 0;
}
double fun(double x) // функция
{
	return(2.0 / x * cos(x / 2.0));
}