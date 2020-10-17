#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int find(string s1, string s2, int i, int j, int sum)
{
	ans = max(ans, sum);
	cout << i << " " << j <<  " " << sum << endl;
	
	if(i == s1.length() || j == s2.length())
	{
		return -1;
	}
	
	int a = -1;
	
	if(s1[i] == s2[j])
	{
		a = max(a, find(s1, s2, i + 1, j + 1, sum + 1));
	}
	
	int b = find(s1, s2, i + 1, j, sum);
	int c = find(s1, s2, i, j + 1, 0);
	
	a = max(a, max(b, c));
	return a;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int l = 0;
	
	vector<vector<int> > v(s1.length() + 1, vector<int>(s2.length() + 1, 0));
	for(int i = 0; i <= s1.length(); i++)
	{
		for(int j = 0; j <= s2.length(); j++)
		{
			if(i == 0 || j == 0)
			{
				v[i][j] = 0;
			}
			else if(s1[i - 1] == s2[j - 1])
			{
				v[i][j] = v[i - 1][j - 1] + 1;
			}
			else
			{
				v[i][j] = max(v[i - 1][j], 0);
			}
			
			l = max(l, v[i][j]);
		}
	}
	
	cout << l << endl;
	
//	find(s1, s2, 0, 0, 0);
//	cout << ans;
}






