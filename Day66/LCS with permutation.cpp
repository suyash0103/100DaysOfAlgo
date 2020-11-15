#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    map<char, int> mp1;
    map<char, int> mp2;

    for(int i = 0; i < s1.length(); i++)
    {
        mp1[s1[i]]++;
    }

    for(int i = 0; i < s2.length(); i++)
    {
        mp2[s2[i]]++;
    }

    string ans = "";
    for(int i = 0; i < s1.length(); i++)
    {
        if(mp2.find(s1[i]) != mp2.end())
        {
            int t = min(mp2[s1[i]], mp1[s1[i]]);
            while(t--)
            {
                ans.push_back(s1[i]);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << "HERE: " << ans;
}