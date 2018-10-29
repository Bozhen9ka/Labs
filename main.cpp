#include <stdio.h>
#include <math.h>

#include <iostream>

double functoionY(double X);
double getSumElement(int n, double x);
double getSumN(int n, double x);
double getSumE(double epsilon, double x, int n);
void printData(double startX, double endX);
int factorial(int n);

int main()
{
	printData(0.1, 0.8);

	system("pause");
	return 0;
}

double functoionY(double X)
{
	return 2 * (pow(cos(X), 2) - 1);
}

double getSumElement(int n, double x)
{
	return pow(-1, n)*pow((2 * x), 2 * n) / factorial(2 * n);
}

double getSumN(int n, double x)
{
	if (n == 0) return 0;
	else return getSumElement(n, x) + getSumN(n - 1, x);
}

double getSumE(double epsilon, double x, int n)
{
	if (abs(getSumElement(n, x)) < epsilon) return 0;
	return getSumElement(n, x) + getSumE(n + 1, epsilon, x);
}

void printData(double startX, double endX)
{
	const double i = (endX - startX) / 10;

	for (; startX <= endX; startX += i)
	{
		printf("X = %f     ", startX);
		printf("SumN = %f     ", getSumN(10, startX));
		printf("SumE = %f     ", getSumE(0.0001, startX, 1));
		printf("Y = %f\n", functoionY(startX));

	}
}

int factorial(int n)
{
	if (n == 0) return 1;
	else return factorial(n - 1)*n;
}
