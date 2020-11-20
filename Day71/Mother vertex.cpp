#include <iostream>
#include <vector>

using namespace std;

int t = 0;

void dfs(vector<vector<int> >& v, vector<pair<int, int> >& times, vector<int>& vis, int node)
{
    vis[node] = 1;
    times[node].first = t;
    t++;

    for(int i = 0; i < v[node].size(); i++)
    {
        if(vis[v[node][i]] == 0)
        {
            dfs(v, times, vis, v[node][i]);
        }
    }
    
    times[node].second = t;
    t++;
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

    vector<pair<int, int> > times(n);
    vector<int> vis(n, 0);

    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(v, times, vis, i);
        }
    }

    int maxtime = -1;
    int node;
    for(int i = 0; i < times.size(); i++)
    {
        if(maxtime < times[i].second)
        {
            maxtime = times[i].second;
            node = i;
        }
    }

    cout << node << endl;
}