#include <iostream>


using namespace std;


double f(double x)
{
	return(7*x + 3);
}


double rectangle(int n, double xp, double xk, double dx) {
	double s = 0.0;

	for (int i = 1; i < n; i++) {
		s += f(xp + i * dx);

	}

	s *= dx;
	return s;
}


double trapezee(int n, double xp, double xk, double h)
{
	double s = 0.0;
	double base_a = f(xp), base_b;

	for (int i = 1; i <= n; i++)
	{
		base_b = f(xp + h * i);
		s += (base_a + base_b);
		base_a = base_b;
	}
	return s * 0.5 * h;
}

int main() {
	double xp, xk, dx;
	int n;
	cout << "Podaj liczbe przedzialow";
	cin >> n;
	cout << "Podaj poczatek przedzialu calkowania";
	cin >> xp;
	cout << "Podaj koniec przedzialu calkowania";
	cin >> xk;

	dx = (xk - xp) / n;


	cout << "Całka metoda prostokatow wynosi: " << rectangle(n, xp, xk, dx) << endl;
	cout << "Całka metoda trapezow wynosi: " << trapezee(n, xp, xk, dx) << endl;

	system("pause");

	}
