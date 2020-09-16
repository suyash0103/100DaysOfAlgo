#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	int v[10] = {1, 3, -2, 4, 10, -14, 2, -5, -1, 0};
	
	int maxHere = 0;
	int maxFinal = 0;
	
	for(int i = 0; i < 10; i++)
	{
		maxHere += v[i];
		if(maxFinal < maxHere)
		{
			maxFinal = maxHere;
		}
		
		if(maxHere < 0)
		{
			maxHere = 0;
		}
	}
	
	cout << maxFinal;
}
