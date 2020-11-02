// https://www.hackerrank.com/challenges/special-multiple/problem

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        queue<int> q;
        q.push(9);

        while(true)
        {
            int num = q.front();
            q.pop();

            if(num % n == 0)
            {
                cout << num << endl;
                break;
            }

            q.push(num * 10 + 9);
            q.push(num * 10 + 0);
        }
    }
}