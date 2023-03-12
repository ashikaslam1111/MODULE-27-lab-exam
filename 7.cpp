#include<bits/stdc++.h>
using namespace std;
void print_list(list<int> l)
{
    auto x=l.begin();
    while(x!=l.end())
    {
        cout<<*x<<" ";
        x++;
    }
}
void delete_value(list<int>&l,int value)
{
    auto it = find(l.begin(),l.end(),value);
    l.erase(it);
}
int main()
{
    list<int> a;
    int n;
    cout<<"enter 7 element\n";
    for(int i=1; i<=7; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<"which one u wanna remove ";
    cin>>n;
    cout<<"before >>";
    print_list(a);
    cout<<"\n";
    delete_value(a,n);
    cout<<"after >>";
    print_list(a);
    return 0;
}
