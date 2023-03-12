#include<bits/stdc++.h>
using namespace std;
template<class t>
class node
{
public:
    t data;
    node* next;
    node* prev;
};
template<class t>
class dequee
{
public:
    node<t>* head;
    node<t>* tail;
    int sz;
    dequee()
    {
        sz=0;
        head=NULL;
        tail=NULL;
    }
    node<t>* creatNewNode(int value)
    {
        node<t>* newnode=new node<t>;
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        return newnode;
    }

    void pushBack(int value)
    {
        node<t>* a= creatNewNode(value);
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

    void pushFront(int value)
    {
        sz++;
        node<t>* a= creatNewNode(value);
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
        node<t>* a=head;
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
        node<t>* a=tail;
        a->prev->next=NULL;
        tail= a->prev;
        delete a;
    }

    int Size()
    {
        return sz;
    }
    t Front()
    {
        if(sz==0)
        {
            t a;
            return a;
        }
        return head->data;
    }
    t Back()
    {
        {
            t a;
            return a;
        }
        return tail->data;
    }
};
int main()
{
    dequee<int> d;
    d.pushBack(12);
    d.pushFront(7);
    d.pushBack(2);
    cout<<d.Back();
    return 0;
}
