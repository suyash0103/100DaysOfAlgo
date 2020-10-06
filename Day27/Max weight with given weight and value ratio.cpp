#include<bits/stdc++.h>

using namespace std;

int ans = 0;
int k;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(vector<int>& w, vector<int>& v, int i, int j, int sumW, int sumV)
{
//	cout << i << " " << j << " " << sumW << " " << sumV << endl;
	if(sumV != 0 && (double)sumW / (double)sumV == k)
	{
		ans = max(ans, sumW);
		return sumW;
	}
	
	if(i >= w.size() && j >= v.size())
	{
		return -1;
	}
	
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	int a = -1;
	
	if(i == w.size())
	{
		a = max(a, find(w, v, i, j + 1, sumW, sumV + v[j]));
		a = max(a, find(w, v, i, j + 1, sumW, sumV));
		return a;
	}
	
	if(j == v.size())
	{
		a = max(a, find(w, v, i + 1, j, sumW + w[i], sumV));
		a = max(a, find(w, v, i + 1, j, sumW, sumV));
		return a;
	}
	
	a = max(a, find(w, v, i + 1, j + 1, sumW, sumV));
	a = max(a, find(w, v, i + 1, j + 1, sumW + w[i], sumV + v[j]));
	
	a = max(a, find(w, v, i + 1, j, sumW, sumV));
	a = max(a, find(w, v, i + 1, j, sumW + w[i], sumV));
	
	a = max(a, find(w, v, i, j + 1, sumW, sumV));
	a = max(a, find(w, v, i, j + 1, sumW, sumV + v[j]));
	
	dp[i][j] = a;
	
	return a;
}

int main()
{
	int n;
	cin >> n >> k;
	
	vector<int> w(n);
	vector<int> v(n);
	
	for(int i = 0; i < n; i++)
		cin >> w[i];
		
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	cout << find(w, v, 0, 0, 0, 0) << endl;
	cout << ans;
}

//3
//2
//4 8 9
//2 4 6
