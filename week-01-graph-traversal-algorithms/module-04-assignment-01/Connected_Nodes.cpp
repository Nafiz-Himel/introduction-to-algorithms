#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    // int a[n];
    vector<int> adj_list[n]; // array of vctor
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // undirected
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;

        vector<int> v;

        for (int x : adj_list[n])
        {
            v.push_back(x);
        }

        sort(v.begin(), v.end(), greater<int>());

        if (v.empty())
            cout << "-1";
        else
            for (int x : v)
            {
                cout << x << " ";
            }
        cout << endl;
    }
    return 0;
}