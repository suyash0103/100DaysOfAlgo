#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void powerset(vector<ll>& v, vector<ll>& st, int index, int n)
{
	if(index == n)
	{
		for(int j = 0; j < st.size(); j++)
			cout << st[j] << " ";
		cout << endl;
		return;
	}
	
	for(int x = index; x < n; x++)
	{
		st.push_back(v[index]);
		powerset(v, st, x + 1, n);
		st.pop_back();
	}
	
}

int main()
{
	ll n;
	cin >> n;
	
	vector<ll> v(n);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<ll> st;
	powerset(v, st, 0, n);
}
