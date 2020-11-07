// https://www.geeksforgeeks.org/length-longest-sub-string-can-make-removed/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> st;
    int maxans = 0;
    int ans = 0;
    int i = 0;
    int num = 0;
    while (i < s.length())
    {
        if(st.size() > 2)
        {
            char b = st.top();
            st.pop();
            char a = st.top();
            st.pop();
            string sub = "";
            sub.push_back(a);
            sub.push_back(b);
            sub.push_back(s[i]);
            if(sub == "100")
            {
                ans += 3;
                maxans = max(ans, maxans);
                i++;
                num = 1;
            }
            else
            {
                st.push(a);
                st.push(b);
                st.push(s[i]);
                i++;
                if(num > 0)
                {
                    num--;
                }
                else
                {
                    ans = 0;
                }
                
            }
            
        }
        else
        {
            st.push(s[i]);
            i++;
        }
    }

    cout << maxans << endl;
}