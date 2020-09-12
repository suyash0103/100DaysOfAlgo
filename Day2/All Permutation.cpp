#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

set<vector<ll> > st;

void permute(vector<ll>& v, int n)
{
	for(int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
				continue;
				
			swap(v[i], v[j]);
			if(st.find(v) == st.end())
			{
				st.insert(v);
				permute(v, n);
			}
			else
			{
				continue;
			}
			
			swap(v[i], v[j]);
		}
	}
}

void permuteOptimise(vector<ll>& v, int i, int n)
{
	if(i == n - 1)
	{
		for(int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << endl;
		return;
	}
	
	for(int j = i; j < n; j++)
	{
		swap(v[i], v[j]);
		permuteOptimise(v, i + 1, n);
		swap(v[i], v[j]);
	}
}

int main()
{
	ll n;
	cin >> n;
	
	vector<ll> v(n);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	st.insert(v);
	
	permute(v, n);
	cout << endl;
	permuteOptimise(v, 0, n);
}
