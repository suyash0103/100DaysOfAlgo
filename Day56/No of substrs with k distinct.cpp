// https://www.geeksforgeeks.org/count-number-of-substrings-with-exactly-k-distinct-characters/

#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    int ans = 0;
    map<char, int> mp;
    set<char> st;

    int start = 0;
    int end = 0;

    for(int i = 0; i < s.length(); i++)
    {
        st.insert(s[i]);
        mp[s[i]]++;
        if(st.size() == k)
        {
            ans++;
        }
        for(int j = i + 1; j < s.length(); j++)
        {
            mp[s[j]]++;
            st.insert(s[j]);
            if(st.size() == k)
            {
                ans++;
            }
        }
        mp.clear();
        st.clear();
    }

    // while(end < s.length())
    // {
    //     mp[s[end]]++;
    //     st.insert(s[end]);

    //     while(st.size() == k && start <= end)
    //     {
    //         ans++;
    //         mp[s[start]]--;
    //         if(mp[s[start]] == 0)
    //         {
    //             mp.erase(s[start]);
    //             st.erase(s[start]);
    //         }
    //         start++;
    //     }

    //     end++;
    // }

    cout << ans << endl;
}