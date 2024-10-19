#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> P(n * 2);
    for (int i = 0; i < n * 2; i++)
    {
        cin >> P[i];
    }

    vector<string> Q(n * 2);
    for (int i = 0; i < n * 2; i++)
    {
        cin >> Q[i];
    }

    vector<string> comp;
    for (int i = 0; i < n * 2; i += 2)
    {
        string p1 = P[i];
        string p2 = P[i + 1];

        for (int j = 0; j < n * 2; j += 2)
        {
            string q1 = Q[j];
            string q2 = Q[j + 1];

            if (p2 == q1)
            {
                comp.push_back(p1 + " " + q2);
            }
        }
    }

    for (int i = 0; i < n * 2; i += 2)
    {
        swap(P[i], P[i + 1]);
    }

    for (int i = 0; i < n * 2; i += 2)
    {
        swap(Q[i], Q[i + 1]);
    }

    for (auto i : P)
    {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i : Q)
    {
        cout << i << " ";
    }
    cout << "\n";
    if (comp.empty())
    {
        cout << "No pairs" << "\n";
    }
    else
    {
        for (auto i : comp)
        {
            cout << i << " ";
        }
    }

    return 0;
}
