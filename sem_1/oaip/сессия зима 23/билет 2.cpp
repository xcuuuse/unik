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

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            sum += arr[i];
        }
        if (arr[i] < 0)
        {
            arr[i] += 4;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    int* newArr = new int[n];
    int newSize = 0;
    newArr[newSize++] = arr[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] + arr[i + 1] <= 12)
        {
            newArr[newSize++] = arr[i];
        }
    }
    newArr[newSize++] = arr[n - 1];

    for (int i = 0; i < newSize; i++)
    {
        cout << newArr[i] << " ";
    }
    cout << "\n";
    
    cout << sum;

    delete[] arr;
    delete[] newArr;

    return 0;
}
