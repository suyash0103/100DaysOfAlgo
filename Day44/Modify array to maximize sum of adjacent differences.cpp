#include<bits/stdc++.h>

using namespace std;

int ans = 0;

map<pair<vector<int>, int>, int> mp;

int find(vector<int>& v, int i, int sum)
{
	if(i == v.size())
	{
		for(int j = 0; j < v.size(); j++)
			cout << v[j] << " ";
		cout << endl;
		ans = max(ans, sum);
		return ans;
	}
	
	if(mp.find({v, i}) != mp.end())
	{
		return mp[{v, i}];
	}
	
	int a = 0;
	
	if(i == 0)
	{
		int temp = v[i];
		v[i] = 1;
		a = max(a, find(v, i + 1, sum));
		v[i] = temp;
		a = max(a, find(v, i + 1, sum));
	}
	else
	{
		int temp = v[i];
		v[i] = 1;
		a = max(a, find(v, i + 1, sum + abs(v[i]-  v[i - 1])));
		v[i] = temp;
		a = max(a, find(v, i + 1, sum + abs(v[i]-  v[i - 1])));
	}
	
	mp[{v, i}] = a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	find(v, 0, 0);
	cout << ans;
}
