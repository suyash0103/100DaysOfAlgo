#include<bits/stdc++.h>

using namespace std;

int ans = 0;

map<pair<vector<int>, int>, int> mp;

int find(vector<int>& v, int n, int k)
{	
	if(n == 0)
	{
		ans++;
		return 1;
	}
	
	if(mp.find({v, n}) != mp.end())
	{
		return mp[{v, n}];
	}
	
	int a = 0;
	
	if(v.size() <= 1)
	{
		for(int i = 1; i <= k; i++)
		{
			v.push_back(i);
			a += find(v, n - 1, k);
			v.pop_back();
		}
	}
	else
	{
		if(v[v.size() - 1] == v[v.size() - 2])
		{
			for(int i = 1; i <= k; i++)
			{
				if(i == v[v.size() - 1])
				{
					continue;
				}
				else
				{
					v.push_back(i);
					a += find(v, n - 1, k);
					v.pop_back();
				}
			}
		}
		else
		{
			for(int i = 1; i <= k; i++)
			{
				v.push_back(i);
				a += find(v, n - 1, k);
				v.pop_back();
			}
		}
	}
	
	mp[{v, n}] = a;
	return a;
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	vector<int> v;
	cout << find(v, n, k) << endl;
	cout << ans;
}
