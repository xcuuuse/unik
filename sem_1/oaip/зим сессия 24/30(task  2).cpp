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
    int k = 1;
    for (int i = start; s[i] != '\0'; i++) {
        if (s[i] == ' ' || s[i + 1] == '\0') {
            int end = 0;
            if (s[i] == ' ') {
                end = i - 1;
            } else {
                end = i;
            }
            if (end >= start && s[end] == 'y' && s[end - 1] == 'b') {
                    cout << k << " ";

            }
            start = i + 1;
            while (s[start] == ' ') {
                start++;
            }
            k++;
        }
    }
    delete[] s;
}
