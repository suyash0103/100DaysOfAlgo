#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    map<char, int> mp;

    for(int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    string ans = "";

    for(int i = 0; i < s.length(); i++)
    {
        if(mp[s[i]] >= k)
        {
            ans.push_back(s[i]);
        }
    }

    cout << ans << endl;
}