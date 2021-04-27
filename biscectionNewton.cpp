#include <iostream>
#include <cmath>

using namespace std;

//dokładność do 15 miejsca po przecinku
double dokladnosc = 1e-10;

double f(double x)
{
    return x + 3;
}


//do Metody Raphsona
double df(double x)
{
    return 1;
}


void bisection(double a, double b, double &fx, double &x0, bool &error, int & iterator) {
    double fa, fb;

    fa = f(a);
    fb = f(b);

    if (fa * fb > 0) {
        cout << "Funkcja nie przyjmuje roznych wartości na krancach przedzialu, nie mozna wykonac";

    }
    else
    {
        error = true;

        while (true)
        {

            iterator++;
            x0 = (a + b) / 2;

            if (fabs(a - x0) < dokladnosc) {
                break;
            }

            fx = f(x0);

            if (fabs(fx) < dokladnosc) {
                break;
            }

            if (fa * fx < 0) {
                b = x0;
            }
            else
            {
                a = x0;
                fa = fx;
            }
        }
    }

}

double newtonRaphon(double a, int &z) {
    z++;
    double x = a - f(a) / df(a);
    if (fabs(f(a)) <= dokladnosc)
        return x;
    if (fabs(x - a) <= dokladnosc)
        return x;
    return newtonRaphon(x, z);
}

int main()
{

    double fx, x0;
    int i = 0;
    int z = 0;
    bool error = false;

    double a, b;

    cout << "Podaj a";
    cin >> a;
    cout << "Podaj b";
    cin >> b;

    bisection(a, b, fx, x0, error, i);
    newtonRaphon(a, z);
    

    cout << "Pierwiastek : " << x0 << endl;
    cout << "Wartosc : " << fx << endl;
    cout << i << endl;
    cout << "--------Metoda Raphsona--------" << endl;
    cout << "Pierwiastek: " << newtonRaphon(a ,z) << endl;
    cout << z << endl;

}
