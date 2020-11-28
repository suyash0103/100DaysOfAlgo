#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int s, d;
    cin >> s >> d;

    vector<vector<int> > g(n);

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    queue<pair<int, vector<int> > > q;
    vector<int> temp;
    temp.push_back(s);
    pair<int, vector<int> > p;
    p.first = s;
    p.second = temp;
    q.push(p);

    vector<int> vis(n, 0);

    while(!q.empty())
    {
        p = q.front();
        q.pop();

        int node = p.first;
        // cout << node << endl;

        vis[node] = 1;

        if(node == d)
        {
            for(int i = 0; i < p.second.size(); i++)
            {
                cout << p.second[i] << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < g[node].size(); i++)
        {
            if(vis[g[node][i]] == 1)
            {
                continue;
            }

            vector<int> tempv = p.second;
            tempv.push_back(g[node][i]);
            pair<int, vector<int> > p1;
            p1.first = g[node][i];
            p1.second = tempv;

            q.push(p1);
        }
    }
}