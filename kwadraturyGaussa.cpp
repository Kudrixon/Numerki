#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int i; int j;
	double xksi, yksi, xni, yni, pow = 0.0;
	double X[] = { 1,0,0,0 },  Y[] = { 0,0,0,0 };
	double punkt[2], pksi[2][4], pni[2][4], fun[2][2], waga[2];
	waga[0] = 1.0;
	waga[1] = 1.0;
	punkt[0] = -0.5773502692;
	punkt[1] = 0.5773502692;

	for (j = 0; j < 2; j++) {
		for (i = 0; i < 2; i++) {

			pksi[j][0] = -0.25 * (1 - punkt[j]);
			pksi[j][1] = 0.25 * (1 - punkt[j]);
			pksi[j][2] = 0.25 * (1 + punkt[j]);
			pksi[j][3] = -0.25 * (1 + punkt[j]);

			pni[i][0] = -0.25 * (1 - punkt[i]);
			pni[i][1] = -0.25 * (1 + punkt[i]);
			pni[i][2] = 0.25 * (1 + punkt[i]);
			pni[i][3] = 0.25 * (1 - punkt[i]);

			xksi = pksi[j][0] * X[0] + pksi[j][1] * X[1] + pksi[j][2] * X[2] + pksi[j][3] * X[3];
			yksi = pksi[j][0] * Y[0] + pksi[j][1] * Y[1] + pksi[j][2] * Y[2] + pksi[j][3] * Y[3];

			xni = pni[i][0] * X[0] + pni[i][1] * X[1] + pni[i][2] * X[2] + pni[i][3] * X[3];
			yni = pni[i][0] * Y[0] + pni[i][1] * Y[1] + pni[i][2] * Y[2] + pni[i][3] * Y[3];

			fun[i][j] = xksi * yni - xni * yksi;
		}
	}

	for (j = 0; j < 2; j++) {
		for (i = 0; i < 2; i++) {

			pow = pow + abs(fun[i][j]) * waga[i] * waga[j];
		}
	}

	cout << "Pole powierzchni: " << pow << endl;

}
