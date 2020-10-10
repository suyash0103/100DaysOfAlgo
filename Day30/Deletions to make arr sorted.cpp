#include<bits/stdc++.h>

using namespace std;

int ans = 0;

map<pair<int, vector<int> >, int > mp;

bool sorted(vector<int>& sort)
{
	for(int i = 1; i < sort.size(); i++)
	{
		if(sort[i] < sort[i - 1])
		{
			return false;
		}
	}
	return true;
}

int find(vector<int>& v, int i, vector<int>& sort)
{
//	cout << i << endl;
	if(i == v.size())
	{
		if(sorted(sort))
		{
			int n = sort.size();
			ans = max(ans, n);
			return ans;
		}
		return 0;
	}
	
	if(mp.find({i, sort}) != mp.end())
	{
		return mp[{i, sort}];
	}
	
	int a = 0;
	
	sort.push_back(v[i]);
	a = find(v, i + 1, sort);
	sort.pop_back();
	a = max(a, find(v, i + 1, sort));
	
	mp[{i, sort}] = a;
	
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	set<int> st;
	vector<int> sort;
	
	cout << find(v, 0, sort) << endl;
	cout << v.size() - ans;
}
