// https://www.geeksforgeeks.org/count-characters-string-distance-english-alphabets/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    map<int, char> mp;
    for(int i = 0; i < s.length(); i++)
    {
        mp[i] = s[i];
    }

    int ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = 97; j <= 122; j++)
        {
            char c1 = s[i];
            char c2 = char(j);

            if(c1 == c2)
            {
                continue;
            }

            int a1 = int(s[i]);
            int d = abs(a1 - j);

            if(d + i < s.length() && s[d + i] == c2)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;

}