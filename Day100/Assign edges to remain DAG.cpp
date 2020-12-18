#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct comp
{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2)
    {
        return p1.second > p2.second;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int> > v(n);
    vector<int> deg(n, 0);

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);

        deg[b]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;

    for(int i = 0; i < n; i++)
    {
        if(deg[i] == 0)
        {
            pq.push(make_pair(i, 0));
        }
    }

    vector<int> topo;
    vector<int> vis(n, 0);

    while (!pq.empty())
    {
        pair<int, int> p1 = pq.top();
        pq.pop();

        cout << p1.first << "->" << p1.second << endl;

        vis[p1.first] = 1;

        topo.push_back(p1.first);

        for(int i = 0; i < v[p1.first].size(); i++)
        {
            if(vis[v[p1.first][i]] == 0)
            {
                deg[v[p1.first][i]]--;
                // pq.push(make_pair(v[p1.first][i], deg[v[p1.first][i]]));
                if(deg[v[p1.first][i]] == 0)
                {
                    pq.push(make_pair(v[p1.first][i], deg[v[p1.first][i]]));
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << topo[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int flag = 0;
            for(int k = 0; k < v[topo[i]].size(); k++)
            {
                if(v[topo[i]][k] == topo[j])
                {
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
            {
                cout << topo[i] << "->" << topo[j] << endl;
            }
        }
    }
    

}