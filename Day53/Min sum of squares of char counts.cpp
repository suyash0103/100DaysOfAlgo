#include<bits/stdc++.h>

using namespace std;

struct comp 
{
	bool operator()(pair<char, int> const& p1, pair<char, int> const& p2)
	{
		return p1.second < p2.second;
	}
};

int main()
{
	string s;
	cin >> s;
	
	int k;
	cin >> k;
	
	priority_queue<pair<char, int>, vector<pair<char, int>, comp > pq;
	
	map<char, int> mp;
	for(int i = 0; i < s.length(); i++)
	{
		mp[s[i]]++;
	}
	
	map<char, int> :: iterator it;
	it = mp.begin();
	while(it != mp.end())
	{
		pq.push({it->first, it->second});
		it++;
	}
	
	while(k--)
	{
		pair<char, int> p = pq.top();
		pq.pop();
		p.second--;
		if(p.second > 0)
		{
			pq.push(p);
		}
	}
	
	int ans = 0;
	while(!pq.empty())
	{
		pair<char, int> p = pq.top();
		pq.pop();
		
		ans += pow(p.second, 2);
	}
	
	cout << ans;
}
