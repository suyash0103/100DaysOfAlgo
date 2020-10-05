#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	int l = 0, r = -1;
	int maxfinal = 0, maxhere = 0;
	int flag = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(v[i] > 0)
		{
			flag = 1;
		}
		
		maxhere += v[i];
		
		if(maxfinal < maxhere)
		{
			maxfinal = maxhere;
			r = i;
		}
		
		maxfinal = max(maxfinal, maxhere);
		if(maxhere < 0)
		{
			l = i + 1;
			maxhere = 0;
		}
	}
	
	if(flag == 0)
	{
		cout << "All elements negative";
	}
	else
	{
		int neg = 0;
		int negpos = -1;
		for(int i = l; i <= r; i++)
		{
			if(v[i] < 0 && v[i] < neg)
			{
				negpos = i;
				neg = v[i];
			}
		}
		
		if(negpos == -1)
		{
			int sumL = 0;
			int LorR = 0;
			
			for(int i = l - 2; i >= 0; i--)
			{
				if(v[i] < 0)
				{
					break;
				}
				sumL += v[i];
			}
			
			int sumR = 0;
			for(int i = r + 2; i < n; i++)
			{
				if(v[i] < 0)
				{
					break;
				}
				sumR += v[i];
			}
			
			maxfinal += max(sumL, sumR);
		}
		else
		{
			maxfinal -= neg;
		}
		
		cout << maxfinal;
	}
}
