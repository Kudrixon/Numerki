#include <iostream>

int main()
{

	int n;
	float xInterpoled, yInterpoled = 0, x[50], y[50], l, min, max;

	std::cout << "Ilosc wprowadzanych wartosci funkcji \"n\":";
	std::cin >> n;

	while (n <= 0) {
		printf("Ilosc pkt nie moze byc rowna lub mniejsza niz zero: ");
		std::cin >> n;
	}

	std::cout << "Wprowadz dane x oraz f\(x\), wartosci x nie moga sie powtarzac:" << std::endl;
	for (int i = 1; i <= n; i++)
	{
		printf("x%d = ", i);
		std::cin >> x[i];
		printf("f[x%d] = ", i);
		std::cin >> y[i];

		if (i == 1) {
			min = x[i];
			max = x[i];
		}
		else if (x[i] < min) {
			min = x[i];
		}
		else if (x[i] > max) {
			max = x[i];
		}
	}

	printf("Wprowadz punkt interpolacji: ");
	std::cin >> xInterpoled;

	while (xInterpoled > max || xInterpoled < min) {
		printf("Punkt z poza przedzialu wprowadz ponownie: ");
		std::cin >> xInterpoled;
	}

	//Pętla z interpolacją
	for (int i = 1; i <= n; i++)
	{
		l = 1;
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				l = l * (xInterpoled - x[j]) / (x[i] - x[j]);
			}
		}
		yInterpoled = yInterpoled + l * y[i];
	}
	printf("Wartosc interpolowana funkcji w punkcie %f wynosi %f \n", xInterpoled, yInterpoled);

}
