// https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/

#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    set<char> st;
    for(int i = 0; i < s2.length(); i++)
    {
        st.insert(s2[i]);
    }

    map<char, int> mp;
    set<char> s;
    int ans = INT32_MAX;

    int start = 0;
    int end = 0;
    while(end < s1.length())
    {
        cout << start << " " << end << endl;
        mp[s1[end]]++;
        if(st.find(s1[end]) != st.end())
        {
            s.insert(s1[end]);   
        }
        while(s.size() == st.size() && start <= end)
        {
            ans = min(ans, end - start + 1);
            mp[s1[start]]--;
            if(mp[s1[start]] == 0)
            {
                mp.erase(s1[start]);
                s.erase(s1[start]);
            }
            start++;
        }
        end++;
    }

    cout << ans << endl;
}