// https://www.geeksforgeeks.org/count-distinct-substrings-string-using-suffix-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<string> suff;
    for(int i = 0; i < s.length(); i++)
    {
        string sub = s.substr(i);
        suff.push_back(sub);
    }

    sort(suff.begin(), suff.end());

    int ans = 0;
    for(int i = 0; i < suff.size(); i++)
    {
        ans += suff[i].length();
        if(i > 0)
        {
            int j = 0;
            int k = 0;
            int comm = 0;
            while(j < suff[i - 1].length() && k < suff[i].length() && suff[i - 1][j] == suff[i][k])
            {
                j++;
                k++;
                comm++;
            }

            ans -= comm;
        }
    }

    cout << ans << endl;
}