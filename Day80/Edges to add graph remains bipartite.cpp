#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int s1 = n/2;
    int s2;
    if(n % 2 == 1)
    {
        s2 = n/2 + 1;
    }
    else
    {
        s2 = n/2;
    }

    int total = s1 * s2;
    int ans = total - e;

    cout << ans << endl;
    
}