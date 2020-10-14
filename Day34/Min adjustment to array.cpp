#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

void find(vector<int>& v, int t, int i, int sum, int curr)
{
	if(i == v.size() - 1)
	{
		ans = min(ans, sum);
		for(int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		return;
	}
	
	if(abs(v[i] - v[i + 1]) <= t)
	{
		find(v, t, i + 1, sum, 1);
	}
	
	if(curr == 0)
	{
		int diff = abs(v[i] - v[i + 1]);
		diff -= t;
		if(v[i] < v[i + 1])
		{
			v[i + 1] -= diff;
			find(v, t, i + 1, sum + diff, 1);
			v[i + 1] += diff;
			v[i] += diff;
			find(v, t, i + 1, sum + diff, 1);
			v[i] -= diff;
		}
		else
		{
			v[i + 1] += diff;
			find(v, t, i + 1, sum + diff, 1);
			v[i + 1] -= diff;
			v[i] -= diff;
			find(v, t, i + 1, sum + diff, 1);
			v[i] += diff;
		}
	}
	else
	{
		int diff = abs(v[i] - v[i + 1]);
		diff -= t;
		if(v[i] < v[i + 1])
		{
			v[i + 1] -= diff;
			find(v, t, i + 1, sum + diff, 1);
			v[i + 1] += diff;
		}
		else
		{
			v[i + 1] += diff;
			find(v, t, i + 1, sum + diff, 1);
			v[i + 1] -= diff;
		}
	}
}

int main()
{
	int n, t;
	cin >> n >> t;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	find(v, t, 0, 0, 0);
	cout << ans;
}
