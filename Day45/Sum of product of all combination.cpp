#include<bits/stdc++.h>

using namespace std;

int sum = 0;

int find(int n, int i, int num, int prod)
{
//	cout << n << " " << i << endl;
	if(i == 0)
	{
		sum += prod;
//		cout << prod << endl;
		return sum;
	}
	
	if(num > n)
	{
		return 0;
	}
	
	find(n, i - 1, num + 1, prod * num);
	find(n, i, num + 1, prod);
}

int main()
{
	int n;
	cin >> n;
	
	cout << "1: " << (n * (n + 1))/2 << endl;
	
	for(int i = 2; i <= n; i++)
	{
		sum = 0;
		find(n, i, 1, 1);
		cout << i << ": " << sum << endl;
	}
}
