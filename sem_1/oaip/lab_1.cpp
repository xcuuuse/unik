#include "bits/stdc++.h"

using namespace std;

int main()
{
    double x, y, z;
    cin >> x >> y >> z;
    double ans = 0;
    ans += fabs(pow(x, y / x) - pow(y / x, 1/3.)) + (y - x) * (cos(y) - z/(y - x)) / (1 + pow(y - x, 2));
    cout <<fixed << setprecision(4) <<  ans;

}
