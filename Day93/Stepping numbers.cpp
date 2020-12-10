#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    queue<int> q;
    for(int i = 1; i < 10; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x <= m && x >= n)
        {
            cout << x << " ";
        }

        int lastD = x % 10;
        int upper = lastD + 1;
        int lower = lastD - 1;

        if (upper <= 9 && x * 10 + upper <= m)
        {
            q.push(x * 10 + upper);
        }

        if(lower >= 0 && x * 10 + lower <= m)
        {
            q.push(x * 10 + lower);
        }
    }
}