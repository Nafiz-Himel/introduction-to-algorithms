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
        // for (int child : path)
        // {
        //     cout << child << " ";
        // }
        // cout << endl;
        cout << path.size() << endl;

    }