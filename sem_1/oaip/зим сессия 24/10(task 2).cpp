#include <iostream>

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
    int mini = arr[0][0], maxi = arr[0][0];
    int minindex =  0, maxindex = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > maxi)
            {
                maxi = arr[i][j];
                maxindex = j;
            }
            if (arr[i][j] < mini)
            {
                mini = arr[i][j];
                minindex = j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i][minindex];
        arr[i][minindex] = arr[i][maxindex];
        arr[i][maxindex] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
