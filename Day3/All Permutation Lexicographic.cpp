#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void permute(vector<int>& v, int i)
{
	if(i == 0)
	{
		for(int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		return;
	}
	
	for(int j = i; j >= 0; j--)
	{
		swap(v[i], v[j]);
		permute(v, i - 1);
		swap(v[i], v[j]);
	}
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	sort(v.begin(), v.end());
	permute(v, n - 1);
}
