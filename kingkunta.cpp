#include<iostream>


using namespace std;

float f(float x, float y)
{
	return ((x-1)/(y*y));
}

int main()
{
	float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
	int i, n;

	cout << "Podaj warunki wejściowe dla x i y" << endl;
	cout << "x0 = ";
	cin >> x0;
	cout << "y0 = ";
	cin >> y0;
	cout << "Szukany x = ";
	cin >> xn;
	cout << "Podaj liczbe krokow ";
	cin >> n;


	h = (xn - x0) / n;

	for (i = 0; i < n; i++)
	{
		k1 = h * (f(x0, y0));
		k2 = h * (f((x0 + h / 2), (y0 + k1 / 2)));
		k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
		k4 = h * (f((x0 + h), (y0 + k3)));
		k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		yn = y0 + k;
		x0 = x0 + h;
		y0 = yn;
	}

	cout << "\n Wartość w punkcie x:" << xn << " wynosi " << yn;

	return 0;
}
