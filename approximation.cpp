#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

float sum1(vector<float> x,vector<float> y, float n)
{
	float suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += x[i-1] * y[i-1];
	}
	return suma;
}
float sum2(vector<float> y, float n)
{
	float suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += y[i-1];
	}
	return suma;
}
float sum3(vector<float> x, float n)
{
	float suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += x[i-1];
	}
	return suma;
}
float sum4(vector<float> x, float n)
{
	float suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += pow(x[i-1], 2);
	}
	return suma;
}

int main() {
	int c;
	cout << "podaj ilosc danych" << endl;
	cin >> c;
	vector<float> x, y;
	float a, b, d, p;
	float s1, s2, s3, s4;
	float temp1, temp2;

	for (int i = 0; i < c; i++)
	{
		cout << "podaj " << i + 1 << " x:";
		cin >> temp1;
		x.push_back(temp1);
		cout << "podaj " << i + 1 << " y:";
		cin >> temp2;
		y.push_back(temp2);
	}

	s1 = sum1(x, y, c);
	s2 = sum2(y, c);
	s3 = sum3(x, c);
	s4 = sum4(x, c);

	a = (c * s1 - s2 * s3) / (c * s4 - pow(s3, 2));
	b = (s4 * s2 - s3 * s1) / (c * s4 - pow(s3, 2));
	cout << "a jest rowne:" << a << endl;
	cout << "b jest rowne:" << b << endl;
	return 0;
}
