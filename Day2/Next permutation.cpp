#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll n;
	cin >> n;
	
	vector<ll> v(n);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	int pos = -1;
	for(int i = n - 1; i > 0; i--)
	{
		if(v[i] > v[i - 1])
		{
			pos = i - 1;
			break;
		}
	}
	
	if(pos == -1)
	{
		for(int i = 0; i < n; i++)
			cout << v[i] << " ";
	}
	else
	{
		int pos2 = pos + 1;
		int ele = v[pos + 1];
		for(int i = pos + 1; i < n; i++)
		{
			if(v[i] > v[pos] && v[i] < ele)
			{
				pos2 = i;
				ele = v[i];
			}
		}
		
//		cout << pos << " " << pos2 << endl;
		swap(v[pos], v[pos2]);
		sort(v.begin() + pos + 1, v.end());
		
		for(int i = 0; i < n; i++)
			cout << v[i] << " ";
	}
}
