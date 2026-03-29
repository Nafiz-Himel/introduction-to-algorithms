// problem link- https://leetcode.com/problems/max-area-of-island/description/

class Solution
{
public:
    bool vis[55][55];

    int cnt;

    vector<pair<int, int>> d = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    int n, m;
    bool valid(int i, int j)
    {
        if (i >= n || i < 0 || j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
                dfs(ci, cj, grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int big = 0;
        n = grid.size();
        m = grid[0].size();

        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j])
                {
                    cnt = 0;
                    dfs(i, j, grid);
                    if(cnt > big)
                        big = cnt;
                }
            }
        }
        return big;
    }
};