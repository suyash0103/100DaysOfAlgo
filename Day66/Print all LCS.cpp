#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<string> ansset;

int find(vector<vector<int> >& dp, int n, int m, string s1, string s2, string s)
{ 
    if(n == 0 || m == 0)
    {
        if(s.length() != dp[s1.length()][s2.length()])
        {
            return 1;
        }
        reverse(s.begin(), s.end());
        // cout << s << endl;
        ansset.insert(s);
        return 1;
    }

    // cout << n << " " << m << endl;

    if(s1[n - 1] == s2[m - 1])
    {
        s.push_back(s1[n - 1]);
        find(dp, n - 1, m - 1, s1, s2, s);
    }
    else
    {
        find(dp, n, m - 1, s1, s2, s);
        find(dp, n - 1, m, s1, s2, s);
    }

    return 1;
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

    // for(int i = 0; i <= n; i++)
    // {
    //     for(int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    find(dp, n, m, s1, s2, "");

    set<string> :: iterator it;
    it = ansset.begin();
    while(it != ansset.end())
    {
        cout << *it << endl;
        it++;
    }
}