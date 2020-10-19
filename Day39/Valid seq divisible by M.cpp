#include<bits/stdc++.h>

using namespace std;

int ans = 0;

map<pair<int, int>, int> mp;

bool find(vector<int>& v, int m, int i, int sum)
{
//	cout << i << " " << sum << endl;
	
	if(i == v.size())
	{
		if(sum % m == 0)
		{
			ans = 1;
			return true;
		}
		return false;
	}
	
	if(mp.find({i, sum}) != mp.end())
	{
		return mp[{i, sum}];
	}
	
	bool a = false;
	
	a = a || find(v, m, i + 1, sum + v[i]);
	a = a || find(v, m, i + 1, sum - v[i]);
	
	mp[{i, sum}] = a;
	
	return a;
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	cout << find(v, m, 1, v[0]) << endl;
	cout << ans;
}
