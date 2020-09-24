#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	vector<int> l2r(n, 0);
	vector<int> r2l(n, 0);
	r2l[n - 1] = n - 1;
	vector<int> l2rsum(n, 1);
	vector<int> r2lsum(n, 1);
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[i] > v[j] && l2rsum[j] + 1 > l2rsum[i])
			{
				l2rsum[i] = l2rsum[j] + 1;
				l2r[i] = j;
			}
		}
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		for(int j = n - 1; j > i; j--)
		{
			if(v[i] > v[j] && r2lsum[j] + 1 > r2lsum[i])
			{
				r2lsum[i] = r2lsum[j] + 1;
				r2l[i] = j;
			}
		}
	}
	
	int maxind = 0;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(l2rsum[i] + r2lsum[i] - 1 > sum)
		{
			sum = max(l2rsum[i] + r2lsum[i] - 1, sum);
			maxind = i;
		}
	}
	
	vector<int> ans;
	ans.push_back(v[maxind]);
	int maxindcpy = maxind;
	
	while(l2r[maxind] != maxind)
	{
		maxind = l2r[maxind];
		ans.push_back(v[maxind]);
	}
	
	reverse(ans.begin(), ans.end());
	maxindcpy = r2l[maxindcpy];
	ans.push_back(v[maxindcpy]);
	
	while(r2l[maxindcpy] != maxindcpy)
	{
		maxindcpy = r2l[maxindcpy];
		ans.push_back(v[maxindcpy]);
	}
	
	cout << sum << endl;
	
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}










