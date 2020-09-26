#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	vector<int> sum(n, 1);
	vector<int> ele(n, 0);
	
	ele[0] = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[i] > v[j] && sum[j] + v[i] > sum[i])
			{
				sum[i] = sum[j] + v[i];
				ele[i] = j;
			}
		}
	}
	
	vector<int> ans;
	int maxsum = sum[0];
	int pos = 0;
	for(int i = 0; i < n; i++)
	{
		if(sum[i] > maxsum)
		{
			maxsum = max(maxsum, sum[i]);
			pos = i;
		}
	}
	
	ans.push_back(v[pos]);
	
	while(pos != ele[pos])
	{
		pos = ele[pos];
		ans.push_back(v[pos]);
	}
	
	reverse(ans.begin(), ans.end());
	
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] <<" ";
	}
}













