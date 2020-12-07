#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<set<int> > g(n);

    map<int, vector<int> > mp;

    for(int i = 0; i < n; i++)
    {
        if(mp.find(v[i]) != mp.end())
        {
            for(int j = 0; j < mp[v[i]].size(); j++)
            {
                g[i].insert(mp[v[i]][j]);
                g[mp[v[i]][j]].insert(i);
            }
        }
        else
        {
            mp[v[i]].push_back(i);
        }

        if(i - 1 >= 0)
        {
            g[i].insert(i - 1);
        }
        if(i + 1 < n)
        {
            g[i].insert(i + 1);
        }
    }

    for(int i = 0; i < n; i++)
    {
        auto it = g[i].begin();
        cout << i << ": ";
        while (it != g[i].end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));

    vector<int> vis(n, 0);

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int node = p.first;
        int d = p.second;

        vis[node] = 1;

        if(node == n - 1)
        {
            cout << d << endl;
            break;
        }

        auto it = g[node].begin();
        while(it != g[node].end())
        {
            if(vis[*it] == 0)
            {
                q.push(make_pair(*it, d + 1));
            }

            it++;
        }
    }
     
}