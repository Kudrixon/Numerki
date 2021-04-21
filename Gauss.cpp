#include <iostream>


using namespace std;

bool calculate(int n, double** Array, double* X)
{

    int i, j, k;
    double m, t;


    for (i = 0; i < n - 1; i++)
    {
        if ((Array[i][i]) == 0 ) return false;
        for (j = i + 1; j < n; j++)
        {
            m = -Array[j][i] / Array[i][i];
            for (k = i + 1; k <= n; k++)
                Array[j][k] += m * Array[i][k];
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        t = Array[i][n];
        for (j = n - 1; j >= i + 1; j--) {
            t -= Array[i][j] * X[j];
        }
        if ((Array[i][i]) == 0) return false;
        X[i] = t / Array[i][i];
    }
    return true;
}


int main()
{
    // Tworzenie tablicy 2 wymairowej
    double** Array, * X;
    int      n, i, j;
    
    // wprowadź ilość rozwiązań
    cout << "wprowadz ilosc rozwiazan" << endl;
    cin >> n;

    Array = new double* [n];
    X = new double[n];

    cout << "wprowadz wspolczynniki x1,x2,x3... " << endl;
    for (i = 0; i < n; i++) Array[i] = new double[n + 1];

    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++) {
            //wprowadź wspolczynniki
            cin >> Array[i][j];
        }

    if (calculate(n, Array, X))
    {
        for (i = 0; i < n; i++)
            cout << "x" << i + 1 << " = " << X[i]
            << endl;
    }
    else
        cout << "Dzielenie przez zero nie mozna wkonac" << endl;


    for (i = 0; i < n; i++) {
        delete[] Array[i];
    }
    //USUWANIE TABLIC Z PAMIECI
    delete[] Array;
    delete[] X;

    return 0;
}
