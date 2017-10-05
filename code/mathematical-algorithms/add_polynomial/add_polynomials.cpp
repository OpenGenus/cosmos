/* Part of Cosmos by OpenGenus Foundation */
/* Contributed by Vaibhav Jain (vaibhav29498) */
#include <iostream>
using namespace std;

struct term
{
    int coeff;
    int pow;
    term* next;
    term(int,int);
};

term::term(int c,int p)
{
    coeff=c;
    pow=p;
    next=nullptr;
}

class polynomial
{
    term* head;
public:
    polynomial();
    void insert_term(int,int);
    void print();
    friend polynomial operator+(polynomial,polynomial);
};

polynomial::polynomial()
{
    head=nullptr;
}

void polynomial::insert_term(int c,int p)
{
    if(head==nullptr)
    {
        head=new term(c,p);
        return;
    }
    if(p>head->pow)
    {
        term* t=new term(c,p);
        t->next=head;
        head=t;
        return;
    }
    term* cur=head;
    while(cur!=nullptr)
    {
        if(cur->pow==p)
        {
            cur->coeff+=c;
            return;
        }
        if(cur->next==nullptr||cur->next->pow<p)
        {
            term* t=new term(c,p);
            t->next=cur->next;
            cur->next=t;
            return;
        }
        cur=cur->next;
    }
}

void polynomial::print()
{
    term* t=head;
    while(t!=nullptr)
    {
        cout << t->coeff;
        if(t->pow)
            cout << "x^" << t->pow;
        if(t->next!=nullptr)
            cout << "+";
        t=t->next;
    }
    cout << endl;
}

polynomial operator+(polynomial p1,polynomial p2)
{
    polynomial p;
    term *t1=p1.head,*t2=p2.head;
    while(t1!=nullptr&&t2!=nullptr)
    {
        if(t1->pow>t2->pow)
        {
            p.insert_term(t1->coeff,t1->pow);
            t1=t1->next;
        }
        else if(t1->pow<t2->pow)
        {
            p.insert_term(t2->coeff,t2->pow);
            t2=t2->next;
        }
        else
        {
            p.insert_term(t1->coeff+t2->coeff,t1->pow);
            t1=t1->next;
            t2=t2->next;
        }
    }
    while(t1!=nullptr)
    {
        p.insert_term(t1->coeff,t1->pow);
        t1=t1->next;
    }
    while(t2!=nullptr)
    {
        p.insert_term(t2->coeff,t2->pow);
        t2=t2->next;
    }
    return p;
}

int main()
{
    polynomial p1,p2;
    p1.insert_term(7,4);
    p1.insert_term(4,5);
    p1.insert_term(10,0);
    p1.insert_term(9,2);
    cout << "First polynomial:";
    p1.print();
    p2.insert_term(5,0);
    p2.insert_term(6,5);
    p2.insert_term(7,0);
    p2.insert_term(3,2);
    cout << "Second polynomial:";
    p2.print();
    polynomial p3=p1+p2;
    cout << "Sum:";
    p3.print();
    return 0;
}
