#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int ans = 0;

void dfs(vector<vector<int> >& v, vector<int>& vis, int n1, int n2)
{
    if(n1 == n2)
    {
        ans++;
        return;
    }

    vis[n1] = 1;

    for(int i = 0; i < v[n1].size(); i++)
    {
        if(vis[v[n1][i]] == 0)
        {
            dfs(v, vis, v[n1][i], n2);
        }
    }

    vis[n1] = 0;

}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int> > v;
    v.resize(n);

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    int n1, n2;
    cin >> n1 >> n2;

    vector<int> vis(n, 0);

    dfs(v, vis, n1, n2);

    cout << ans << endl;
}