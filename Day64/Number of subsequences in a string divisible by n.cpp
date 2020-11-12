// https://www.geeksforgeeks.org/number-subsequences-string-divisible-n/

#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(string s, int n, int i, int sum)
{
    if(sum % n == 0)
    {
        if(sum == 0 && i > 0)
        {
            ans++;
        }
    }

    if(i == s.length())
    {
        return 0;
    }

    if(dp[i][sum] != -1)
    {
        return dp[i][sum];
    }

    int a = 0;

    a += find(s, n, i + 1, sum);
    a += find(s, n, i + 1, sum + (s[i] - '0'));

    dp[i][sum] = a;
    return a;
}

int main()
{
    string s;
    cin >> s;

    int n;
    cin >> n;

    find(s, n, 0, 0);

    cout << ans << endl;
}