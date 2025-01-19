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
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        if (arr[i] < 0)
        {
            for (int j = i; j > k; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[k] = temp;k++;
        }

    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
