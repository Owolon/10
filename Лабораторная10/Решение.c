#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define _USE_MATH_DEFINES 
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
	double sin=0.;
	for (int k = 1; k <= N; k++) 
	{
		int c = 2 * k - 1;
		sin = x - (pow(-1, k - 1) * (pow(x, c)/factor(c)));
	}
	return sin;
}
double epssin(double x, double eps)//������� � ��������.
{
	double x2 = 0;
	int k = 1;
	while (fabs(x) > eps)
	{
		int c = 2 * k - 1;
		x2 = x - (pow(-1, k - 1) * (pow(x, c) / factor(c)));
		k++;
	}
	return x2;
}
float area_tringle(float a, float b)
{
	return;
}
void risunok(int R, char symvol)
{
	char symv = symvol;
	int osn = 2 * R;
	int c = (int)(R * cos(30));
	int y = (int)R / 3;
	int q = 0;
	for (int i = 0; i <= c; i += 2)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == osn || j == osn - 1)
			{
				printf("%c", symv);
			}
			else
			{
				printf(" ");
			}
			printf(" %c", symv);
		}
		printf("\n");
	}
	for (int i = osn / y; i > 0; i--)
	{
		for (int j = 0; j <= i; j += 2)
		{
			q = j;
			if (j == osn || j == osn - 1)
			{
				printf("%c", symv);
			}
			else
			{
				printf(" ");
			}
			printf("%c", symv);
		}
		printf("\n");
	}
}
int funcS(int R) 
{
	int a = R * 2;
	int b = R * cos(30);
	int c = R * cos(60);
	int S = (a * b * c) / 4 * R;
	return S;
}
void name(int an) {
	if (an == 1) printf("��� �����");
	if (an == 2) printf("��� ����");
	if (an == 3) printf("��� ����������");
}
void main()//�������� ���� ����
{
	setlocale(LC_CTYPE, "RUS");
	while (1)
	{
		double x,eps;
		int N;
		char a;
		printf("������� x:");
		scanf_s("%lf", &x);
		printf("������� eps (������: 0.001):");
		scanf_s("%lf", &eps);
		printf("������� N:");
		scanf_s("%d", &N);
		printf("f1(x) = %lf\t f2(x) = %lf", fa(x), fb(x));//����� ��������
		printf("\n������������ = %lf\t �������� = %lf\t ��������� = %lf", fa(x) * fb(x), fa(x) + fb(x), fa(x) - fb(x));//����� ������������, ��������, �������� 
		printf("\n");

		double result = epssin(x, eps);

		//����� �������� \/
		printf(" �����  ���������  ���������� ");
		for (int i = 1; i <= N; i++){
			double res = sinus_n(x, i);
			printf("\n%4.d | \t%lf | %e ", i, res, sin(x) - res);
		}
		
		char l;
		char symvol;
		int q = 0, an = 0;
		int R;
		int y = 0, c = 0, d = 0;

		printf("\n������� ������:");
		scanf_s("%d", &R);
		printf("\n������� ����� ������:");
		scanf_s("%d", &an);
		printf("\n������� ������ ��� ���������� ������:");
		scanf_s(" %c", &symvol);
		printf("\n�������� �������� ��� �������: \n\t1)��������� �������\n\t2)������� ����������� ������\n\t3)���������� ������\n");
		scanf_s(" %�", &l);
		switch (l)
		{
		case '1':
			printf("������ ������� �������");
			funcS(R);
			break;
		case '2':
			printf("����� ����������� ������\n");
			name(an);
			break;
		case '3':
			printf("���������� ������\n");
			risunok(R, symvol);
			break;
		default:
			printf("�� ����� ������ �����");
			break;
		}

		printf("\n���������� ? (��-y / ���-n)");
		scanf_s(" %c", &a);
		if ((a = getchar()) == 'n')break;
	}
	
}