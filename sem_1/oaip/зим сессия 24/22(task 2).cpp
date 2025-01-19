#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    const int x = 100;
    int kolvo[x + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0 && arr[i] <= 100)
        {
            kolvo[arr[i]]++;
        }
    }
    int most = 0;
    int count = 0;
    for (int i = 0; i <= x; i++)
    {
        if (kolvo[i] > count)
        {
            count = kolvo[i];
            most = i;
        }
    }
    cout << most;
    delete[] arr;
    return 0;
}
