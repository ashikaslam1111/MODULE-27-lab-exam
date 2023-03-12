#include<bits/stdc++.h>
using namespace std;
template<class t>
class node
{
public:
    t data;
    node* next;
};
template<class t>
class stackk
{
public:
    node<t>* head;
    int sz;
    stackk()
    {
        head=NULL;
        sz=0;
    }
    node<t>* creat_new_node(t vlue)
    {
        node<t>* newnode=new node<t>;
        newnode->data=vlue;
        newnode->next=NULL;
        return newnode;
    }
    void inshead(t valu)
    {
        node<t>* a =creat_new_node(valu);
        if(head==NULL)
        {
            head=a;
            sz++;
            return ;
        }
        a->next=head;
        head=a;
        sz++;
    }
    void pop()
    {
        if(head==NULL)return;
        node<t>* a=head;
        head=a->next;
        delete a;
        sz--;
    }
t top()
{
    if(sz==0)
    {
        cout<<"empty";
        t a;
        return a;
    }
    return head->data;
}
int getsize()
{
    return sz;
}
};
int main()
{
    stackk<char> s;
    s.inshead('d');
    s.inshead('e');
    s.inshead('r');
    s.inshead('e');
    s.pop(); s.pop(); s.pop(); s.pop();
    cout<<"size= "<<s.getsize()<<"\n";
    cout<<s.top();
    return 0;
}
