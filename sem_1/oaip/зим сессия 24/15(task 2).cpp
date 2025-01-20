#include "iostream"

using namespace std;

int main()
{
    int n;
    cin >> n;
    int **arr = new int * [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int *b = new int[n];
    int r = 0;
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i][j];
        }
        if (sum / n > 7)
        {
            b[r] = 0;
            r++;
        }
        else
        {
            b[r] = 1;
            r++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    delete[] b;
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
