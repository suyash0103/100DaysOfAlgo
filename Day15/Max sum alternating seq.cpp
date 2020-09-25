#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<int> lis(n, 1);
	vector<vector<int> > sum(n, vector<int>(2, 0));
	
	for(int i = 1; i < n; i++)
	{
//		cout << "i : " << i << endl;
		for(int j = 0; j < i; j++)
		{
//			cout << j << " ";
			if(j == 0 && v[i] < v[j])
			{
				sum[i][0] = max(sum[i][0], v[i] + v[j]);
			}
			else if(j != 0)
			{
				if(v[i] < v[j])
				{
					sum[i][0] = max(sum[i][0], sum[j][1] + v[i]);
				}
				else
				{
					sum[i][1] = max(sum[i][1], sum[j][0] + v[i]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
//		cout << sum[i][0] << " " << sum[i][1] << endl;
		ans = max(ans, max(sum[i][0], sum[i][1]));
	}
	
	cout << ans;
}
