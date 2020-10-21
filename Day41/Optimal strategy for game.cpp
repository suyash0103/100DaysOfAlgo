#include<bits/stdc++.h>

using namespace std;

int ans = 0;

map<pair<int, int>, int> mp;

int find(vector<int>& v, int i, int j, int sum)
{
	cout << i << " " << j << " " << sum << endl;
	
	if(i == j)
	{
		sum += v[i];
		return sum;
	}
	
	if(i == j - 1)
	{
		sum += max(v[i], v[j]);
		return sum;
	}
	
	if(mp.find({i, j}) != mp.end())
	{
		return mp[{i, j}];
	}
	
	int a = 0;
	
	a = max(min(find(v, i + 1, j - 1, sum + v[i]), find(v, i + 2, j, sum + v[i])), 
			min(find(v, i + 1, j - 1, sum + v[j]), find(v, i, j - 2, sum + v[j])));
			
	mp[{i, j}] = a;
			
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	cout << find(v, 0, n - 1, 0) << endl;
	cout << ans;
}
