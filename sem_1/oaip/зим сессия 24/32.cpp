#include "iostream"
#include "cmath"
#include "iomanip"
using namespace std;

double y(double x, double* res)
{
    *res = (2 * x * x - 1) * exp(x);
    return *res;
}
int main()
{
    for (double x = 0.2; x <= 0.9; x += 0.073)
    {
        double res;
        cout << setw(15) << x << setw(15) << y(x, &res) << "\n";
    }
}
