#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<int> t;

vector<int> f;

int find(vector<int>& v, int n, int k, int i, int sum)
{
//	cout << i << " " << k << " " << sum << endl;
	if(i == n)
	{
		if(k == 0)
		{
			sort(t.begin(), t.end());
//			cout << "vec: ";
//			for(int l = 0; l < t.size(); l++)
//				cout << t[l] << " ";
//			cout << endl;
			f.push_back(t[t.size() - 1]);
			ans = max(ans, sum);
			return ans;
		}
	}
	
	if(k < 0)
	{
		return INT_MAX;
	}
	
	int time = 0;
	int a = 0;
	for(int j = i; j < n; j++)
	{
		time += v[j];
		t.push_back(time);
		a = max(a, find(v, n, k - 1, j + 1, time));
		t.pop_back();
	}
	
	return a;
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	find(v, n, k, 0, 0);
	sort(f.begin(), f.end());
	cout << f[0];
//	cout << ans;
}
