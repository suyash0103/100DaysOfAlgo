#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> place(n, 0);
	vector<int> rev(n, 0);
	
	for(int i = 0; i < n; i++)
		cin >> place[i];

	for(int i = 0; i < n; i++)
		cin >> rev[i];
	
	int t;
	cin >> t;
	
	vector<int> ans1d(n, 0);
	ans1d[0] = rev[0];
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(place[i] - place[j] > t)
			{	
				ans1d[i] = max(ans1d[i], ans1d[j] + rev[i]);
				
			}
			else
			{	
				ans1d[i] = max(ans1d[i], max(ans1d[j], rev[i]));	
			}
		}
	}
	
	int finalAns = ans1d[0];
	for(int i = 0; i < n; i++)
	{
//		cout << ans1d[i] << endl;
		finalAns = max(finalAns, ans1d[i]);
	}
	
	cout << finalAns;
}

//5
//6 7 12 13 14
//5 6 5 3 1
//5
