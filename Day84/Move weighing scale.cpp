#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool dfs(vector<int>& v, int n, int current, int steps, int left, int right, int side)
{
    cout << current << " " << steps << " " << left << " " << right << " " << side << endl;
    if(steps == 0)
    {
        return true;
    }

    for(int i = 0; i < n; i++)
    {
        if(i == current)
        {
            continue;
        }

        if(side == 0 && left + v[i] > right && dfs(v, n, i, steps - 1, left + v[i], right, 1) == true)
        {
            return true;
        }

        if(side == 1 && right + v[i] > left && dfs(v, n, i, steps - 1, left, right + v[i], 0) == true)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int steps;
    cin >> steps;

    for(int i = 0; i < n; i++)
    {
        if(dfs(v, n, i, steps - 1, v[i], 0, 1) == true)
        {
            cout << "true" << endl;
            return 1; 
        }
    }

    cout << "false" << endl;
}