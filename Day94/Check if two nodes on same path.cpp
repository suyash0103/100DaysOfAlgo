#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

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

    int root, s, d;
    cin >> root >> s >> d;

    queue<int> q;
    q.push(s);

    vector<int> vis(n, 0);
    vis[s] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        vis[node] = 1;

        if(node == d)
        {
            cout << "true" << endl;
            return 1;
        }

        for(int i = 0; i < v[node].size(); i++)
        {
            if(v[node][i] != root && vis[v[node][i]] == 0)
            {
                q.push(v[node][i]);
            }
        }
    }

    cout << "no" << endl;
    return 0;
}