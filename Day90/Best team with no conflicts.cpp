// https://leetcode.com/problems/best-team-with-no-conflicts/

#include <iostream>
#include <vector>

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int> > v;
        
        for(int i = 0; i < scores.size(); i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        
        sort(v.begin(), v.end());
        
        vector<int> lis(ages.size(), 0);
        
        
        
        for(int i = 0; i < ages.size(); i++)
        {
            cout << v[i].first << " ";
        }
        
        cout << endl;
        for(int i = 0; i < ages.size(); i++)
        {
            cout << v[i].second << " ";
        }
        cout << endl;
        
        lis[0] = v[0].second;
        
        int ans = lis[0];
        
        for(int i = 1; i < ages.size(); i++)
        {
            lis[i] = v[i].second;
            ans = max(ans, lis[i]);
            for(int j = 0; j < i; j++)
            {
                if(v[i].second >= v[j].second)
                {
                    lis[i] = max(lis[i], v[i].second + lis[j]);
                    ans = max(ans, lis[i]);
                }
            }
            ans = max(ans, lis[i]);
        }
        
        return ans;
    }

    int main() {
        
    }
};