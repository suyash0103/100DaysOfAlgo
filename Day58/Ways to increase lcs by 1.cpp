// https://www.geeksforgeeks.org/count-ways-increase-lcs-length-two-strings-one/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int i = n, j = m;
    string lcs = "";

    while(i > 0 && j > 0)
    {
        if(s1[i - 1] == s2[j - 1])
        {
            lcs.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i - 1][j] >= dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << lcs << endl;

    i = 0;
    j = 0;
    while(i < lcs.length() && j < s1.length())
    {
        if(lcs[i] == s1[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    int pos = j - 1;
    i = 0;
    j = 0;
    
    while(i < lcs.length() && j < s2.length())
    {
        if(lcs[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    int numchars = m - j;
    int ans = numchars * (n - pos);

    cout << ans << endl;
}