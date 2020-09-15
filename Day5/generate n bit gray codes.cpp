#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	int n;
	cin >> n;
	
	vector<string> v;
	v.push_back("0");
	v.push_back("1");
	
	while(v[0].length() != n)
	{
		vector<string> copy;
		
		for(int i = 0; i < v.size(); i++)
		{
			string s = "0" + v[i];
			copy.push_back(s);
		}
		
		for(int i = v.size() - 1; i >= 0; i--)
		{
			string s = "1" + v[i];
			copy.push_back(s);
		}
		
		v = copy;
	}
	
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}
