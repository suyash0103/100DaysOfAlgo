#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	for(int i = 2; i < n; i++)
	{
		v[i] = min(v[i - 1], v[i - 2]) + v[i];
	}
	
	cout << min(v[n - 1], v[n - 2]);
}
