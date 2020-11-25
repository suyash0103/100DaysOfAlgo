#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void dfs(vector<vector<int> >& g, vector<int>& vis, vector<int>& v, int index)
{
    // cout << index << " ";
    vis[index] = 1;
    vis[v.size() - index - 1] = 1;

    g[index].push_back(v[v.size() - index - 1]);
    g[v[v.size() - index - 1]].push_back(index);

    if(vis[v[v.size() - index - 1]] == 0)
    {
        dfs(g, vis, v, v[v.size() - index - 1]);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    int j = 0;

    for(int i = 0; i < n; i++)
    {
        if(j == k)
        {
            j = 0;
        }
        v[i] = j;
        j++;
    }

    // for(int i = 0; i < n; i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    vector<vector<int> > g;
    g.resize(n);

    vector<int> vis(n, 0);

    dfs(g, vis, v, 0);

    string str;

    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 1)
        {
            str += "1";
        }
        else
        {
            str += "0";
        }
    }

    cout << str << endl;

}