#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<string> ansset;

void find(vector<vector<int> >& dp, int n, int m, string s1, string s2, string s)
{
    if(n == 0 || m == 0)
    {
        reverse(s.begin(), s.end());
        ansset.insert(s);
        return;
    }

    if(dp[n][m] == dp[n - 1][m - 1] + 1 && s1[n - 1] == s2[m - 1])
    {
        s.push_back(s1[n - 1]);
        find(dp, n - 1, m - 1, s1, s2, s);
    }
    else
    {
        find(dp, n - 1, m, s1, s2, s);
        find(dp, n, m - 1, s1, s2, s);
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    find(dp, n, m, s1, s2, "");

    set<string> :: iterator it;
    // auto it = ansset.begin();
    while(it != ansset.end())
    {
        cout << *it << endl;
    }
}