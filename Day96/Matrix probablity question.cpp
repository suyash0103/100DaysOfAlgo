#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

double dfs(int n, int m, int i, int j, int moves)
{
    if(i < 0 || j < 0 || i >= n || j >= m)
    {
        return 0.0;
    }

    if(moves == 0)
    {
        return 1.0;
    }

    double ans = 0;

    ans += (dfs(n, m, i + 1, j, moves - 1) * 0.25);
    ans += (dfs(n, m, i - 1, j, moves - 1) * 0.25);
    ans += (dfs(n, m, i, j + 1, moves - 1) * 0.25);
    ans += (dfs(n, m, i, j - 1, moves - 1) * 0.25);

    return ans;
}

int main()
{
    int n, m, moves, i, j;
    cin >> n >> m >> i >> j >> moves;

    cout << dfs(n, m, i, j, moves) << endl;
}