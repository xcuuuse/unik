#include "bits/stdc++.h"

#define int int64_t

using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    int m = n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int sum = 1;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > 0)
            {
                sum *= arr[i][j];
                k++;
            }
        }
    }
    cout << sum << " " << k << "\n";

    int* b = new int[n];
    for (int i = 0; i < n; i++)
    {
        bool allPositive = true;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] <= 0)
            {
                allPositive = false;
                break;
            }
        }
        b[i] = allPositive ? 0 : 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";

    delete[] b;
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
