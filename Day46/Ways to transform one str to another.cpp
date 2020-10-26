#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int find(string a, string b, int i, int j)
{
	if(j == b.length())
	{
		ans++;
		return 1;
	}
	
	if(i == a.length())
	{
		return 0;
	}
	
	int t = 0;
	
	if(a[i] == b[j])
	{
		t += find(a, b, i + 1, j + 1);
	}
	
	t += find(a, b, i + 1, j);
	return t;
}

int main()
{
	string a, b;
	cin >> a >> b;
	
	cout << find(a, b, 0, 0) << endl;
	cout << ans;
}
