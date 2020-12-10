#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int minNode = INT_MAX;

void dfs(vector<vector<int> >& v, vector<int>& vis, vector<int>& w, int node)
{
    vis[node] = 1;
    minNode = min(minNode, w[node]);

    for(int i = 0; i < v[node].size(); i++)
    {
        if(vis[v[node][i]] == 0)
        {
            dfs(v, vis, w, v[node][i]);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int> > v(n);
    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> w(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int ans = 0;

    vector<int> vis(n, 0);

    for(int i = 0; i < n; i++)
    {
        minNode = INT_MAX;
        if(vis[i] == 0)
        {
            dfs(v, vis, w, i);
            ans += minNode;
        }
    }

    cout << ans << endl;
}