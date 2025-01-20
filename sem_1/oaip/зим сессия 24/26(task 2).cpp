#include "iostream"

using namespace std;

int strlen(char *s){
    int len = 0;
    while(s[len] != '\0')
    {
        len++;
    }
    return len;
}
int main()
{
    const int n = 100;
    char *s = new char[n];
    cin.getline(s, n);

    int start = 0;
    int maxIndex = 0;
    int maxLen = 0;
    int curIndex = 0;

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
            int length = end - start + 1;
            if (length > maxLen)
            {
                maxLen = length;
                maxIndex = curIndex + 1;
            }

            start = i + 1;
            curIndex++;
        }
    }

   cout << maxIndex;

    delete[] s;
    return 0;
}
