#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if(s[i - 1] == s[j - 1] && i != j)
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

    cout << dp[n][n] << endl;
}