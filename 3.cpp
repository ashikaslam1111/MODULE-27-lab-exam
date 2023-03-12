#include <bits/stdc++.h>
using namespace std;
bool operand(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}
int prc(char ch)
{
    if (ch == '+' || ch == '-') return 1;
    else if(ch=='/' ||ch=='*')return 2;
    return 0;
}
int main()
{
    string s;
    cin>>s;
    stack<char> stk;
    string res="";
    for (int i = 0; i< s.size(); i++)
    {
        char now=s[i];
        if (operand(now))
        {
            res +=now;
        }
        else if (s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while(stk.empty()==false && stk.top()!='(')
            {
                res += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while(stk.size()&&prc(stk.top())>= prc(now))
            {
                res+= stk.top();
                stk.pop();
            }
            stk.push(now);
        }
    }
    while (stk.size())
    {
        res+=stk.top();
        stk.pop();
    }
    cout <<res<<"\n";
    return 0;
}
