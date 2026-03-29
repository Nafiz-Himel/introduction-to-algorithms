#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long int dis[1005];
vector<Edge> edge_list;
int n, e;

bool cycle = false;    


void bellman_ford()
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    for (auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
        // edge_list.push_back(Edge(b,a,c)); undirected
    }

    int src, tc;
    cin >> src >> tc;

    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[src] = 0;

    bellman_ford();

    while(tc--)
    {
        int des;
        cin >> des;

        if(cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
        else
        {
            if(dis[des] == LLONG_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[des] << endl;
            }
        }
    }

    return 0;
}