#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	
	int fact[n + 1];
	fact[0] = 1;
	fact[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		fact[i] = fact[i - 1] * i;
	}
	
	double ans = 0.0;
	int coff = n - 1;
	for(int i = 1; i <= n; i++)
	{
		int mul = fact[coff] / (fact[i - 1] * fact[coff - i + 1]);
		ans += (double)(sum * mul) / (double)(i);
	}
	
	cout << ans;
	
}
