#include<bits/stdc++.h>

using namespace std;

set<int> st;

set<pair<int, int> > rep;

int find(vector<int>& v, int i, int sum)
{
	st.insert(sum);
	
	if(i == v.size())
	{
		return 0;
	}
	
	if(rep.find({i, sum}) != rep.end())
	{
		return 0;
	}
	
	find(v, i + 1, sum + v[i]);
	find(v, i + 1, sum);
	rep.insert({i, sum});
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	find(v, 0, 0);
	
	set<int> :: iterator it;
	it = st.begin();
	while(it != st.end())
	{
		cout << *it << " ";
		it++;
	}
}
