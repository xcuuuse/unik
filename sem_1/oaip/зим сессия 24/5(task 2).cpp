    #include <iostream>

    using namespace std;

    int main() {
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
        int *x = new int[n];
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            bool check = true;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] < 0)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                x[r] = 0;
                r++;
            }
            else
            {
                x[r] = 1;
                r++;
            }
        }
        for (int i = 0; i < r; i++)
        {
            cout << x[i] << " ";
        }
        delete[] x;
        for (int i = 0; i < n; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
