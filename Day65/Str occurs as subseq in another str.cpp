#include <iostream>
#include <map>
#include <vector>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(string a, string b, int i, int j)
{
    if(j == b.length())
    {
        ans++;
        return 1;
    }

    if(i == a.length())
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int t = 0;
    if(a[i] == b[j])
    {
        t += find(a, b, i + 1, j + 1);
    }
    t += find(a, b, i + 1, j);

    dp[i][j] = t;
    return t;
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << find(a, b, 0, 0) << endl;
    // cout << ans;
}