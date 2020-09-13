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
	
	vector<ll> st;
	
	for(int i = 1; i < pow(2, n); i++)
	{
		for(int j = n - 1; j >= 0; j--)
		{
			int cc = pow(2, j);
			int c = (i & cc);
			if(c != 0)
			{
				st.push_back(v[j]);
			}
		}
		for(int k = 0; k < st.size(); k++)
			cout << st[k] << " ";
		cout << endl;
		st.clear();
	}
}
