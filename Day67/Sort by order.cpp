#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> mp;

struct comp
{
    bool operator()(char& c1, char& c2)
    {
        return mp[c1] < mp[c2];
    }
};


int main()
{
    string pat, str;
    cin >> pat >> str;

    for(int i = 0; i < pat.length(); i++)
    {
        mp[pat[i]] = i;
    }

    sort(str.begin(), str.end(), comp());

    cout << str << endl;
}