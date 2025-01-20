#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

int main()
{
   double s = 1;
   for (double x = 0.2; x <= 1.4; x += 0.043)
   {
       for (double m = 1; m <= 820; m++)
       {
           double r = 2 * m * m + 1;
           r *= ((x * x) / (m * 2)*(m * 2 - 1));
           s += r;
       }
   }
   cout << s;

}
