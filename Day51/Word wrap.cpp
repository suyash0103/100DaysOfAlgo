#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int ans = INT_MAX;

int find(string s, int m, int i, int sum)
{
    cout << i << " " << sum << endl;
    if(i >= s.length())
    {
        ans = min(ans, sum);
        return 1;
    }

    int filled = 0;
    int a = INT_MAX;
    while(i < s.length() && filled <= m)
    {
        cout << "A";
        if(s[i] == ' ')
        {
            int q = pow((m - filled), 3);
            a = min(a, find(s, m, i + 1, sum + q));
        }
        i++;
        filled++;
    }

    return a;
}

int main()
{
    int m;
    cin >> m;

    string s;
    cin >> s;

    cout << find(s, m, 0, 0) << endl;
    cout << ans;
}