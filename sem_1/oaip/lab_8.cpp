#include "bits/stdc++.h"

using namespace std;

double rec(int value, double sum) //рекурсивная функция
{
    return value == 0 ? sqrt(sum) : rec(value - 1, value + sqrt(sum));
}

double sqrt_2(double n) // стандартная функция
{
  double res = 0;
  for (int i = n; i >= 1; i--)
  {
      res = sqrt(i + res);
  }
  return res;
}

int main()
{
    double n;
    cin >> n;

    double ans1 = rec(n - 1, n); //+
    double ans2 = sqrt_2(n); //+
    cout << ans1 << "\n" << ans2;


}
