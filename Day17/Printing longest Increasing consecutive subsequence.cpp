#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	set<int> st;
	map<int, int> mp;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		mp[v[i]] = 1;
		st.insert(v[i]);
	}
		
	vector<int> sum(n, 1);
	
	int ans = 1;
	int ele;
	
	for(int i = 0; i < n; i++)
	{
		if(mp.find(v[i] - 1) != mp.end())
		{
			mp[v[i]] = mp[v[i] - 1] + 1;
			if(ans < mp[v[i]])
			{
				ans = mp[v[i]];
				ele = v[i];
			}
		}
	}
	
	while(ans--)
	{
		cout << ele << " ";
		ele--;
	}
}
