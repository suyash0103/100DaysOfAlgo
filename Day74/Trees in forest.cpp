#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void dfs(vector<vector<int> >& g, vector<int>& vis, int n)
{
    vis[n] = 1;

    for(int i = 0; i < g[n].size(); i++)
    {
        if(vis[g[n][i]] == 0)
        {
            dfs(g, vis, g[n][i]);
        }
    }
}

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
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(g, vis, i);
            ans++;
        }
    }

    cout << ans << endl;

}