#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int> > g;
    g.resize(n);

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> vis(n, 0);

    queue<pair<int, int> > q;
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    q.push(p);

    while(!q.empty())
    {
        int node = q.front().first;
        int l = q.front().second;
        q.pop();

        vis[node] = 1;

        cout << node << ": " << l << endl;

        for(int i = 0; i < g[node].size(); i++)
        {
            if(vis[g[node][i]] == 0)
            {
                p.first = g[node][i];
                p.second = l + 1;
                q.push(p);
            }
        }
    }
}