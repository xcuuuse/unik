#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

int main()
{
    const int n = 1100;
    for (double x = 0.3; x <= 1.7; x += 0.093)
    {
        cout << fixed << setprecision(5) << x << setw(10) << 2 * (cos(x) * cos(x) - 1) << "\n";
    }
    double r = 1, s = 1;
    double x = 0.2;
    for (double m = 1; m <= n; m++)
    {
        r *= ((4 * x * x) / m * (m - 1));
        s += r;
    }
    cout << s;
}
