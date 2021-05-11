#include <iostream>
#include <math.h>

#define dokladnosc 0.000000000000001

using namespace std;
double phi = 0.61803398;

double f(double x) {
	return log(x);
}

double golden(double a, double b, double &xl, double &xp) {
	xl = b - phi * (b - a);
	xp = a + phi * (b - a);

	while ((b - a) >= dokladnosc) {
		xl = b - phi * (b - a);
		xp = a + phi * (b - a);

		if (f(xl) >= f(xp)) {
			a = xl;
		}
		else if (f(xl) <= f(xp)) {
			b = xp;
		}
	}

	return xp;
}

int main() {

	double a, b, xl, xp;

	cout << "Podaj przedzial : ";

	cin >> a >> b;

	cout << "MINIMUM ZNAJDUJE SIE W PKT :" << golden(a, b, xl, xp);
}
