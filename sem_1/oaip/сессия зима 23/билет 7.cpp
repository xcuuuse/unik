#include "bits/stdc++.h"

#define int int64_t

using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            sum += arr[i];
        }
        if (arr[i] < 0)
        {
            arr[i] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n" << sum << "\n";

    int* brr = new int[n];
    brr[0] = arr[0];
    for (int i = 1; i < n - 1; i++)
    {
        brr[i] = (arr[i - 1] + arr[i + 1]) / 2;
    }
    brr[n - 1] = arr[n - 1];

    for (int i = 0; i < n; i++)
    {
        cout << brr[i] << " ";
    }

    delete[] arr;
    delete[] brr;

    return 0;
}
