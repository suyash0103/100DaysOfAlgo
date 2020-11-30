#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void dfs(vector<vector<pair<int, int> > >& g, vector<int>& vis, int node, int& sum)
{
    vis[node] = 1;

    for(int i = 0; i < g[node].size(); i++)
    {
        if(vis[g[node][i].first] == 0)
        {
            sum += g[node][i].second;
            dfs(g, vis, g[node][i].first, sum);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int> > > g(n);

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(make_pair(b, 0));
        g[b].push_back(make_pair(a, 1));
    }

    int ans = INT32_MAX;
    int ansNode;

    for(int i = 0; i < n; i++)
    {
        vector<int> vis(n, 0);
        int sum = 0;
        dfs(g, vis, i, sum);
        cout << "i: " << i << "->" << sum << endl;
        if(sum < ans)
        {
            ans = sum;
            ansNode = i;
        }
    }

    cout << ansNode << "--" << ans << endl;

}