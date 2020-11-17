#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    int ans = 1;
    int l = -1;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            l++;
        }
        else if(s[i] == ')')
        {
            l--;
        }

        if(l == k && s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * (s[i] - '0');
        }
    }

    cout << ans << endl;
}