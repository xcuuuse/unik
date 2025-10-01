#include "bits/stdc++.h"

using namespace std;

double f_min(double x, double y)
{
    return x < y ? x : y;
}

double f_max(double x, double y)
{
    return x > y ? x : y;
}

int main()
{
    double x, y, z;
    cin >> x >> y >> z;
    double temp = f_max(y, z);
    double temp1 = f_min(f_min(x, y), f_min(y, z));
    cout << temp / temp1;
}
