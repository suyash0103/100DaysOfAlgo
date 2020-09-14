#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void find(vector<ll>& v, vector<ll> st, int start, ll n, ll k)
{
//	cout << "size: " << st.size() << endl;
	
	if(st.size() == k)
	{
		for(int i = 0; i < st.size(); i++)
			cout << st[i] << " ";
		cout << endl;
		return;
	}
	
	if(start == n)
	{
		return;
	}
	
	for(int i = start; i < n; i++)
	{
//		cout << start << " " << i << endl;
		if(st.size() < k)
		{
			st.push_back(v[i]);
			find(v, st, i + 1, n, k);
			st.pop_back();
		}
	}
}

int main()
{
	ll n;
	cin >> n;
	
	ll k;
	cin >> k;
	
	vector<ll> v(n);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	vector<ll> st;
	find(v, st, 0, n, k);
	
}
