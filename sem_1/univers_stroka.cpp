#include <iostream>

using namespace std;

int main() {
    const int n = 100;
    char s[n];
    cin.getline(s, n);

    int start = 0;
    while (s[start] == ' ' && s[start] != '\0')
    {
        start++;
    }
    for (int i = start; s[i] != '\0'; i++)
    {

        if (s[i] == ' ' || s[i + 1] == '\0')
        {
            int end = 0;
            if (s[i] == ' ')
            {
                end = i - 1;
            }
            else
            {
                end = i;
            }
            if (end > start && s[start] != s[end] && s[start + 1] == s[start + 2])
            {
                for (int j = start; j <= end; j++)
                {
                    cout << s[j];
                }
                cout << ' ';
            }
            start = i + 1;
            while (s[start] == ' ')
            {
                start++;
            }
        }
    }

    return 0;
}
