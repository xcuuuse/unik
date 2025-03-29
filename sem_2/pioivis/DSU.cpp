
#include "bits/stdc++.h"
#include "DSU.h"

using namespace std;

Dsu::Dsu(int size)
{
    parent.resize(size);
    rank.resize(size, 0);
    for (int i = 0; i < size; i++)
    {
        parent[i] = i;
    }
}

int Dsu::find(int x) // нахождение корня
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void Dsu::unite_two_sets(int x, int y)
{
    int root_x = find(x);
    int root_y = find(y);

    if (root_x != root_y)
    {
        if (rank[root_x] < rank[root_y])
        {
            parent[root_x] = root_y;
        }
        else if (rank[root_x] > rank[root_y])
        {
            parent[root_y] = root_x;
        }
        else
        {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
}

int Dsu::get_set(int x)
{
    return find(x);
}

int Dsu::size() const
{
    return parent.size();
}



