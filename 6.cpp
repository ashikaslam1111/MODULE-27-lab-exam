#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    char data;
    node* next;
    node* prev;
};
class dequee
{
public:
    node* head;
    node* tail;
    int sz;
    dequee()
    {
        sz=0;
        head=NULL;
        tail=NULL;
    }
    node* creatNewNode(char value)
    {
        node* newnode=new node;
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
    }

    void pushBack(int value)
    {
        node* a= creatNewNode(value);
        if(sz==0)
        {
            head=a;
            tail=a;
        }
        tail->next=a;
        a->prev=tail;
        tail=a;
        sz++;
    }

    void pushFront(char value)
    {
        sz++;
        node* a= creatNewNode(value);
        if(sz==0)
        {
            head=a;
            tail=a;
            sz++;
            return;
        }
        a->next=head;
        head->prev=a;
        head=a;
        sz++;
    }

    void popFront()
    {
        if(sz==0)return;

        if(sz==1)
        {
            delete head;
            head=NULL;
            tail=NULL;
            sz--;
            return;
        }
        node* a=head;
        a->next->prev=NULL;
        head= a->next;
        delete a;
        sz--;
    }

    void popBack()
    {
        if(sz==0)return;
        sz--;
        if(sz==1)
        {
            delete head;
            head=NULL;
            tail=NULL;
            return;
        }
        node* a=tail;
        a->prev->next=NULL;
        tail= a->prev;
        delete a;
    }

    int Size()
    {
        return sz;
    }
    char Front()
    {
        if(sz==0)return '0';
        return head->data;
    }
    char Back()
    {
        if(sz==0)return '0';
        return tail->data;
    }
};
int main()
{
    dequee d;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        d.pushBack(s[i]);
    }
    int siz=d.Size();
    int lop=siz/2;
    for(int i=1; i<=lop; i++)
    {
        if(d.Back()==d.Front())
        {
            d.popBack();
            d.popFront();
        }
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
