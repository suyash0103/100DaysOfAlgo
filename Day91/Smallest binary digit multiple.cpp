#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x % n == 0)
        {
            cout << x << endl;
            break;
        }

        q.push(x * 10);
        q.push(x * 10 + 1);
    }
}