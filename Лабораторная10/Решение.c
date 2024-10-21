#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "Решение.h"
#define CRT_NO_SECURE_DEPRECATE
#define M_PI 3.1415926535
double factor(int N)//факториал
{
	double c = 1;
	for (int j = 1; j <= N; j++)
	{
		if (j == 1) {
			c = 1;
		}
		else {
			c = c * j;
		}
	}
	return c;
}
double fa(double x)//функция 2
{
	double y;
	if (x <= 3) {
		y = pow(x, 2) - 3 * x + 9;
	}
	if (x > 3) {
		y = 1/(pow(x,3)+3);
	}
	return y;
}
double fb(double x)//функция 1
{
	double y;
	y = x * exp(sin(pow(x, 2)));
	return y;
}

double sinus_n(double x, int N)//основная функция
{
	double s;
	for (int k = 1; k <= N; k++) 
	{
		int c = 2 * k - 1;
		s = x-(pow(-1, k-1)*(pow(x, c) / factor(c)));
	}
	return s;
}

void main()//основное тело кода
{
	setlocale(LC_CTYPE, "RUS");
	while (1)
	{
		double x;
		int N;
		char a;
		printf("Введите x:");
		scanf_s("%lf", &x);
		printf("Введите N:");
		scanf_s("%d", &N);
		printf("f1(x) = %lf\t f2(x) = %lf", fa(x), fb(x));//вывод значений
		printf("\nПроизведение = %lf\t Сложение = %lf\t Вычитание = %lf", fa(x) * fb(x), fa(x) + fb(x), fa(x) - fb(x));//вывод произведения, сложения, разности 
		printf("\n");

		//вывод значений \/
		for (int i = 1; i <= N; i++){
			double res = sinus_n(x, i);
			printf("\n%4.d | \t%lf | %e", i, res, sin(x) - res);
		}

		printf("\nПродолжить ? (Да-y / Нет-n)");
		scanf_s("%c", &a,2);
		if ((a = getchar()) == 'n')break;
	}
}