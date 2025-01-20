#include "iostream"
#include "iomanip"
#include "cmath"
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
   int maxi = arr[0][0];
   int index = 0;
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < n; j++)
       {
           if (maxi < arr[i][j])
           {
               maxi = arr[i][j];
               index = i;
           }
       }
   }
   for (int j = 0; j < n; j++)
   {
       arr[index][j] = arr[index + 1][j];
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
