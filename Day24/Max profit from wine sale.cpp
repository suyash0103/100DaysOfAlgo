#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][100];
vector<string> f;

int find(vector<int>& v, int start, int end, int year, int sum, vector<string>& func)
{
	if(start > end)
	{
		return 0;
	}
	
	if(start == end)
	{
		sum += year * v[start];
		if(ans < sum)
		{
			f = func;
			f.push_back("beg");
			ans = sum;
		}
//		ans = max(ans, sum);
		return sum;
	}
	
	if(dp[start][end][year] != -1)
	{
		return dp[start][end][year];
	}
	
	int a = 0;
	
	func.push_back("beg");
	a += find(v, start + 1, end, year + 1, sum + year * v[start], func);
	func.pop_back();
	
	func.push_back("end");
	a += find(v, start, end - 1, year + 1, sum + year * v[end], func);
	func.pop_back();
	
	dp[start][end][year] = a;
	return a;
}

int main()
{
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			for(int k = 0; k < 100; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<string> func;
	
	find(v, 0, n - 1, 1, 0, func);
	
	for(int i = 0; i < f.size(); i++)
		cout << f[i] << " ";
	cout << endl;
	cout << ans;
}
