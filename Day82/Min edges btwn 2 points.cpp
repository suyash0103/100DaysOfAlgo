#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int> > g(n);

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int u, v;
    cin >> u >> v;

    queue<pair<int, int> > q;
    vector<int> vis(n, 0);

    pair<int, int> p;
    p.first = u;
    p.second = 0;
    q.push(p);
    int ans = 0;

    while (!q.empty())
    {
        int node = q.front().first;

        int edges = q.front().second;

        q.pop();

        cout << node << "--" << edges << endl;

        vis[node] = 1;

        if(node == v)
        {
            cout << edges << endl;
            break;
        }

        for(int i = 0; i < g[node].size(); i++)
        {
            if(vis[g[node][i]] == 0)
            {
                vis[g[node][i]] = 1;
                p.first = g[node][i];
                p.second = edges + 1;
                q.push(p);
            }
        }
    }
    
}