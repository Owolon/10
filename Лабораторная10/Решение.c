#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "�������.h"
#define CRT_NO_SECURE_DEPRECATE
#define M_PI 3.1415926535
double factor(int N)//���������
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
double fa(double x)//������� 2
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
double fb(double x)//������� 1
{
	double y;
	y = x * exp(sin(pow(x, 2)));
	return y;
}

double sinus_n(double x, int N)//�������� �������
{
	double s;
	for (int k = 1; k <= N; k++) 
	{
		int c = 2 * k - 1;
		s = x-(pow(-1, k-1)*(pow(x, c) / factor(c)));
	}
	return s;
}

void main()//�������� ���� ����
{
	setlocale(LC_CTYPE, "RUS");
	while (1)
	{
		double x;
		int N;
		char a;
		printf("������� x:");
		scanf_s("%lf", &x);
		printf("������� N:");
		scanf_s("%d", &N);
		printf("f1(x) = %lf\t f2(x) = %lf", fa(x), fb(x));//����� ��������
		printf("\n������������ = %lf\t �������� = %lf\t ��������� = %lf", fa(x) * fb(x), fa(x) + fb(x), fa(x) - fb(x));//����� ������������, ��������, �������� 
		printf("\n");

		//����� �������� \/
		for (int i = 1; i <= N; i++){
			double res = sinus_n(x, i);
			printf("\n%4.d | \t%lf | %e", i, res, sin(x) - res);
		}

		printf("\n���������� ? (��-y / ���-n)");
		scanf_s("%c", &a,2);
		if ((a = getchar()) == 'n')break;
	}
}