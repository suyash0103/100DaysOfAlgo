#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> >& v, vector<vector<int> >& closure, int start, int node)
{
    closure[start][node] = 1;

    for(int i = 0; i < v[node].size(); i++)
    {
        if(closure[start][v[node][i]] == 0)
        {
            dfs(v, closure, start, v[node][i]);
        }
    }
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

    vector<vector<int> > closure(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
    {
        dfs(v, closure, i, i);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << closure[i][j] << " ";
        }
        cout << endl;
    }
}