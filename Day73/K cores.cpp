#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n, e, k;
    cin >> n >> e >> k;

    vector<set<int> > v;
    v.resize(n);

    vector<int> deg(n, 0);

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);

        deg[a]++;
        deg[b]++;
    }

    priority_queue<int> pq;

    vector<int> vis(n, 0);

    for(int i = 0; i < n; i++)
    {
        if(deg[i] < k)
        {
            pq.push(i);
            vis[i] = 1;
        }
    }

    while(!pq.empty())
    {
        int node = pq.top();
        pq.pop();

        vis[node] = 1;

        set<int> :: iterator it;
        it = v[node].begin();
        while(it != v[node].end())
        {
            deg[*it]--;
            v[*it].erase(node);

            if(vis[*it] == 0 && deg[*it] < k)
            {
                pq.push(*it);
            }

            it++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(deg[i] >= k)
        {
            cout << i << ": ";
            auto it = v[i].begin();
            while(it != v[i].end())
            {
                cout << *it << " ";
                it++;
            }
            cout << endl;
        }
    }
}