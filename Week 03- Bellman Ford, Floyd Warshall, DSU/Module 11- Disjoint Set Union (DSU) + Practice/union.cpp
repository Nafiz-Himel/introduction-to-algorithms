#include <bits/stdc++.h>
using namespace std;
int par[1005];
int grp_size[1005];

int find(int node) // O(logN)
{
    // cout << node << endl;
    if (par[node] == -1)
        return node;

    int leader = find(par[node]);
    par[node] = leader;

    return leader;
    // while(par[node] != -1)
    // {
    //     cout << node << endl;
    //     node = par[node];
    // }
    // return node;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (grp_size[leader1] >= grp_size[leader2])
    {
        par[leader2] = leader1;
        grp_size[leader1] += grp_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        grp_size[leader2] += grp_size[leader1];
    }
}

int main()
{
    memset(par, -1, sizeof(par));
    memset(grp_size, 1, sizeof(grp_size));
    dsu_union(1, 2);
    dsu_union(2, 0);
    dsu_union(3, 1);

    for (int i = 0; i < 6; i++)
        cout << i << "->" << par[i] << endl;
    return 0;
}