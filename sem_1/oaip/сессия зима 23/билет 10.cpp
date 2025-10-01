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

    int sum = 0;
    for (int j = 0; j < m; j++)
    {
        sum += arr[1][j];
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] < 0)
            {
                k++;
            }
        }
    }

    int minCol = 0, maxCol = 0;
    int minVal = arr[0][0], maxVal = arr[0][0];

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] < minVal)
            {
                minVal = arr[i][j];
                minCol = j;
            }
            if (arr[i][j] > maxVal)
            {
                maxVal = arr[i][j];
                maxCol = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        swap(arr[i][minCol], arr[i][maxCol]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << sum / n << "\n";

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
