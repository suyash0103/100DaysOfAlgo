#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> v(s.length(), 0);
    v[0] = 1;

    map<char, int> mp;
    mp[s[0]]++;

    for(int i = 1; i < s.length(); i++)
    {
        mp[s[i]]++;
        v[i] = (v[i - 1] * 2 + 1) - (mp[s[i]] - 1);
    }

    cout << v[s.length() - 1] + 1 << endl;
}