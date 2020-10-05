#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	int maxProd = 1;
	int minProd = 1;
	
	int maxFinal = INT_MIN;
	
	for(int i = 1; i < n; i++)
	{
		maxProd = max(maxProd * v[i], minProd * v[i]);
		minProd = min(maxProd * v[i], minProd * v[i]);
		
		maxFinal = max(maxFinal, max(maxProd, minProd));
		
		if(maxProd == 0)
		{
			maxProd = 1;
		}
		
		if(minProd == 0)
		{
			minProd = 1;
		}
	}
	
	cout << maxFinal;
}
