#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

int main()
{
   double s = 1;
   double r = 1;
   for (double x = 0.2; x <= 1.3; x += 0.033)
   {
       cout << fixed << setprecision(5) << x << setw(10) << (exp(x) + exp(-x)) / 2 << "\n";
       for (double m = 1; m <= 790; m++)
       {
            r *= ((x * x) / (m * 2) * (m * 2 - 1));
            s += r;
       }
   }
   cout << s;

}
