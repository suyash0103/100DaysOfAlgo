#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int> > g(n);

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    vector<vector<int> > t(n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            t[g[i][j]].push_back(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for(int j = 0; j < t[i].size(); j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}