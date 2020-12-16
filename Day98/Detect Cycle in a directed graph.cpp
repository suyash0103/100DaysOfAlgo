#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int ans = 0;
int timer = 0;

void dfs(vector<vector<int> >& v, int node, vector<int>& vis, vector<int>& startTime, vector<int>& endTime)
{
    vis[node] = 1;
    timer++;
    startTime[node] = timer;

    for(int i = 0; i < v[node].size(); i++)
    {
        if(vis[v[node][i]] == 1)
        {
            if(endTime[v[node][i]] == -1)
            {
                ans = 1;
            }
        }
        else
        {
            dfs(v, v[node][i], vis, startTime, endTime);
        }
    }

    timer++;
    endTime[node] = timer;
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
        // v[b].push_back(a);
    }

    vector<int> vis(n, 0);
    vector<int> startTime(n, -1);
    vector<int> endTime(n, -1);

    dfs(v, 0, vis, startTime, endTime);

    cout << ans << endl;
}