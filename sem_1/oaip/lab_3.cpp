#include "bits/stdc++.h"

using namespace std;

double s(double x, double n)
{
double sum = 0;
for (int k = 1; k <= n; k++)
{
sum = pow(-1, (k + 1)) * (pow(x, (2 * k + 1))) / (4 * pow(k, 2) - 1);
}
return sum;
}

double y(double x)
{
double ans = 0;
ans += ((1 + pow(x, 2)) / 2) * atan(x) - x / 2;
return ans;
}

int main() {
    double x1, x2;
    double a = 0.1, b = 1, h = 0.1;
    for (double i = a; i <= b; i += h) {
        x1 = 0;
        x2 = y(i);
        for (double k = 0;; k++) {
            x1 += s(i, k);
            if (fabs(x2 - x1) < 0.00001) {
                break;
            }
        }

        cout << fixed << setprecision(9) << x2 << " " << x1 << " " << fabs((x2 - x1)) << "\n";
    }

}
