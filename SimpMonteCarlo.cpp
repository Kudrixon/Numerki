#include <iostream>
#include <math.h>


using namespace std;


double f(double x) {
	return 1/x - 1/2;
}

void monteCarlo(double a, double b, int n) {


	double s = 0;
	double randNum, v;

	int i = 0;

	while (i < n - 1)
	{
		randNum = a + (float(rand()) / RAND_MAX) * (b - a);

		v = f(randNum);

		s += v;

		i++;
	}
	double result = (b - a) * s / n;

	cout << "Wynik Monte Carlo: " << result << endl;
}

void simpsonsRule(double a, double b, int n) {
	double h = abs(b - a) / n;
	double ifx = 0;

	ifx = ifx + f(a) + f(b);
	for (double i = a + h; i < b;) {
		ifx = ifx + (4 * f(i));
		i = i + (2 * h);
	}
	for (double i = a + (2 * h); i < b;) {
		ifx = ifx + (2 * f(i));
		i = i + (2 * h);
	}
	ifx = ifx * h / 3;
	cout << "Wynik Simpson: " << ifx << endl;
}

int main() {

	double a, b;
	int n;

	cout << "Podaj przedzial calkowania: ";

	cin >> a >> b;
	cout << "Ilosc podprzedzialow ";

	cin >> n;

	simpsonsRule(a, b, n);
	monteCarlo(a, b, n);
}

