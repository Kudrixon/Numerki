#include <iostream>


using namespace std;

float forFirst(float* x, float *y, int i) {

	return (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
}

float newtonInterpolation(float* x, float* y, int d, int i) {
	if (d == 0) {
		return 1;
	}

	if (d == 1) {
		return forFirst(x, y, i);
	}

	return	(newtonInterpolation(x, y, d - 1, i + 1) - newtonInterpolation(x, y, d - 1, i)) / (x[i + d] - x[i]);

}

int main() {
	int tmp; // potrzebny do pozniejszego obliczania w pętli for
	float xInterpoled, yInterpoled ;
	cout << "Liczba punktow";
	int n;
	cin >> n;
	cout << "Podaj x interpolowany";
	cin >> xInterpoled;


	float* x = new float[n]; //dynamiczne tablice na wspolrzedne
	float* y = new float[n];


	for (int i = 0; i < n; i++)
	{
		printf("x%d = ", i);
		cin >> x[i];
		printf("f[x%d] = ", i);
		cin >> y[i];
	}

	yInterpoled = y[0];
	for (int i = 0; i < n; i++)
	{
		tmp = 0;
		for (int j = 0; j < i; j++) {
			if (j == 0)tmp = xInterpoled - x[0];
			else tmp *= xInterpoled - x[j];
		}
		yInterpoled += tmp * newtonInterpolation(x, y, i, 0);
	}
		cout << "dla x rownego = " << xInterpoled << " f(xInterpoled) = " << yInterpoled << endl;

		system("pause");
	}
