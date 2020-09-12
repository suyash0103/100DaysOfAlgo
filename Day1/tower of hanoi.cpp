#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void move(int n, string init, string mid, string to)
{
	if(n == 1)
	{
		cout << "Shifting from " << init << " to " << to << endl;
		return;
	}
	move(n - 1, init, to, mid);
	cout << "Shifting from " << init << " to " << to << endl;
	move(n - 1, mid, init, to);
}

int main()
{
	ll n;
	cin >> n;
	
	move(n, "initial rod", "middle rod", "target rod");
}
