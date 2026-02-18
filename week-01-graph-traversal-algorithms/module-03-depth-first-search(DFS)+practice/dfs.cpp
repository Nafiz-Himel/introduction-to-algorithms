#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
int vis[1005];

void dfs(int scr)
{
    cout << scr << " ";
    vis[scr] = true;

    for(auto child: adj_list[scr])
        if(!vis[child])
            dfs(child);
}

int main()
{
    int n,e;
    cin >> n >> e;

    while(e--)
    {
        int a,b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis,false,sizeof(vis));
    dfs(0);
    return 0;
}