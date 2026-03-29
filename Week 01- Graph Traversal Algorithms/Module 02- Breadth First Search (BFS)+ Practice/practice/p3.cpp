#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];

void bfs(int src, int dst)
{

    queue<int> q;
    q.push(src);
    vis[src] = true;

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
                parent[child] = par;
            }
        }
    }

    if (vis[dst])
    {
        vector<int> path;
        int node = dst;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        for (int child : path)
        {
            cout << child << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;
        memset(vis, false, sizeof(vis));
        memset(parent, -1, sizeof(parent));
        bfs(src, dst);
    }
    return 0;
}