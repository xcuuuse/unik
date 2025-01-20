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
   int pr = 1, k = 0;
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < n; j++)
       {
           if (arr[i][j] > 0)
           {
               //pr = 1;
               pr *= arr[i][j];
           }
           if (arr[i][j] < 0)
           {
               continue;
           }
           if (arr[i][j] != 0)
           {
               k++;
           }
       }
   }
   int *b = new int[n];
   int r = 0;
   for (int i = 0; i < n; i++)
   {
       bool flag = true;
       for (int j = 0; j < n; j++)
       {
           if (arr[i][j] < 0)
           {
               flag = false;
               break;
           }
       }
       if (flag)
       {
           b[r++] = 0;
       }
       else
       {
           b[r++] = 1;
       }
   }
   cout << pr << " " << k <<"\n";
   for (int i = 0; i < n; i++)
   {
       cout << b[i] << " ";
   }
   delete[]b;
   for (int i = 0; i < n; i++)
   {
       delete[] arr[i];
   }
   delete[] arr;

}
