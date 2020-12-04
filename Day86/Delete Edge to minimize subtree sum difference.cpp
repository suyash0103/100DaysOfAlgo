#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int sum = 0;

void dfs(vector<vector<int> >& g, vector<int>& vis, vector<int>& wt, int a, int b)
{
    vis[a] = 1;

    for(int i = 0; i < g[a].size(); i++)
    {
        if(vis[g[a][i]] == 0 && g[a][i] != b)
        {
            sum += wt[g[a][i]];
            dfs(g, vis, wt, g[a][i], b);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> wt(n);
    for(int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    vector<vector<int> > g(n);

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = INT32_MAX;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            int a = i;
            int b = g[i][j];

            sum = 0;
            vector<int> vis(n, 0);
            dfs(g, vis, wt, a, b);

            int sum1 = sum;

            vis.clear();
            sum = 0;
            dfs(g, vis, wt, b, a);

            int sum2 = sum;

            // cout << a << " " << b << " " << sum1 << " " << sum2 << endl;

            ans = min(ans, abs(sum1 - sum2));
        }
    }

    cout << ans << endl;
}