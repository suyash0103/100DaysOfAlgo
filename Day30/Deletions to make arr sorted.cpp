#include<bits/stdc++.h>

using namespace std;

int ans = 0;

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

void find(vector<int>& v, int i, vector<int>& sort)
{
//	cout << i << endl;
	if(i == v.size())
	{
		if(sorted(sort))
		{
			int n = sort.size();
			ans = max(ans, n);
		}
		return;
	}
	
	sort.push_back(v[i]);
	find(v, i + 1, sort);
	sort.pop_back();
	find(v, i + 1, sort);
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
	
	find(v, 0, sort);
	cout << v.size() - ans;
}
