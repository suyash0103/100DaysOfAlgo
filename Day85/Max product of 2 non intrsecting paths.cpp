#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> dis;

int dfs(vector<vector<int> >& v, vector<int>& vis, int og, int a, int b, int sum)
{
    // cout << og << " " << a << " " << b << " " << sum << endl;

    vis[a] = 1;

    int s = 0;

    for(int i = 0; i < v[a].size(); i++)
    {
        int ss = 0;
        if(vis[v[a][i]] == 0 && v[a][i] != b)
        {
            ss = dfs(v, vis, og, v[a][i], b, sum + 1);
            s = max(s, ss);
        }

        if(a == og)
        {
            dis.push_back(ss);
        }
    }

    return max(s, sum);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > v(n);

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = 0;

    set<pair<int, int> > st;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            int a = i;
            int b = v[i][j];

            if(st.find(make_pair(a, b)) != st.end() || st.find(make_pair(b, a)) != st.end())
            {
                continue;
            }

            st.insert(make_pair(a, b));
            st.insert(make_pair(b, a));

            vector<int> vis(n);

            dis.clear();

            dfs(v, vis, a, a, b, 0);

            int a1 = 0;
            int a2 = 0;

            sort(dis.begin(), dis.end());
            if(dis.size() > 1)
            {
                a1 = dis[dis.size() - 1] + dis[dis.size() - 2];
            }
            else
            {
                a1 = dis[dis.size() - 1];
            }
            
            dis.clear();

            dfs(v, vis, b, b, a, 0);

            sort(dis.begin(), dis.end());
            if(dis.size() > 1)
            {
                a2 = dis[dis.size() - 1] + dis[dis.size() - 2];
            }
            else
            {
                a2 = dis[dis.size() - 1];
            }

            // cout << "final: " << a << " " << b << " " << a1 << " " << a2 << endl;

            ans = max(ans, a1 * a2);
        }
    }

    cout << ans << endl;
}