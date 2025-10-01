#include "iostream"

using namespace std;

int main()
{
    const int n = 100;
    char *s = new char[n];
    cin.getline(s, n);
    int start = 0;
    while(s[start] == ' ' && s[start] != '\0')
    {
        start++;
    }
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' || s[i + 1] == '\0')
        {
            int end;
            if (s[i] == ' ')
            {
                end = i - 1;
            }
            else
            {
                end = i;
            }
            if (end > start && s[start] == 'a' && s[start + 1] == 'p')
            {
                for (int j = start; j <= end; j++)
                {
                    cout << s[j];
                }
                cout << ' ';
            }
            if (end >= start && s[start] == s[end])
            {
                k++;
            }
            start = i + 1;
            while(s[start] == ' ')
            {
                start++;
            }
        }
    }
    cout << k;
    delete[] s;
}
