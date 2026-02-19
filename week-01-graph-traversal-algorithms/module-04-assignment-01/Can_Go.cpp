#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> p = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int ai, int aj)
{
    queue<pair<int, int>> q;
    q.push({ai, aj});
    vis[ai][aj] = true;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();

        int p_i = par.first;
        int p_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = p_i + p[i].first;
            int cj = p_j + p[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'B'))
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    int ai, aj, bi, bj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }

            if (grid[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    bfs(ai, aj);

    if (vis[bi][bj])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
