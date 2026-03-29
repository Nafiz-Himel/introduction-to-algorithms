#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;
vector<int> level;
vector<int> parent;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj_list.resize(n + 1);
    vis.assign(n + 1, false);
    level.assign(n + 1, -1);
    parent.assign(n + 1, -1);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs(1);

    if (vis[n])
    {
        vector<int> path;
        int node = n;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        reverse(path.begin(), path.end());

        cout << path.size() << endl;

        for (int x : path)
        {
            cout << x << " ";
        }
    }
    else
        cout << "IMPOSSIBLE";
    return 0;
}