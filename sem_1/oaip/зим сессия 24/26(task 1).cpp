#include "iostream"

using namespace std;


int main()
{
   const int n = 100;
   char *s = new char[n];

   cin.getline(s, n);

   char *s1 = new char[n];
   int r = 0;
   for (int i = 0; s[i] != '\0'; i++)
   {
       if ((s[i] == 'a' || s[i] == 'A') && (i == 0 || s[i - 1] == ' '))
       {
           int j = i;
           while(s[j] != ' ' && s[j] != '\0')
           {
               s1[r++] = s[j++];
           }
           s1[r++] = ' ';
       }
   }
   for (int i = 0; i < r; i++)
   {
       cout << s1[i];
   }
   delete[] s1;
   delete[] s;
}
