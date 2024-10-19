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
        if (arr[i] < 0)
        {
            sum += arr[i];
        }
        if (arr[i] % 2 == 0)
        {
            arr[i] += 4;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n" << sum << "\n";

    int* brr = new int[n];
    int brrSize = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            brr[brrSize++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            brr[brrSize++] = arr[i];
        }
    }

    for (int i = 0; i < brrSize; i++)
    {
        cout << brr[i] << " ";
    }
    cout << "\n";

    delete[] arr;
    delete[] brr;

    return 0;
}
