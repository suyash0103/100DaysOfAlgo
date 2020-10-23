#include<bits/stdc++.h>

using namespace std;

int find(vector<int>& v, vector<int>& a, int i, int sum)
{
	if(sum < 0)
	{
		return 0;
	}
	
	if(sum == 0)
	{
		for(int j = 0; j < a.size(); j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
		return 1;
	}
	
	if(i == v.size())
	{
		return 0;
	}
	
	find(v, a, i + 1, sum);
	a.push_back(v[i]);
	find(v, a, i + 1, sum - v[i]);
	a.pop_back();
	
	return 1;
}

int main()
{
	int n, sum;
	cin >> n >> sum;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<int> a;
	find(v, a, 0, sum);
}
