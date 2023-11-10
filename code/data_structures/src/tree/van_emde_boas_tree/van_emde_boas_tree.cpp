#include <bits/stdc++.h>
using namespace std;

class veb
{
    int u;
    int *min;
    int *max;
    veb *summary;
    veb **cluster;

public:

    veb(int u);
    void insert(int x);
    void remove(int x);
    int* pred(int x);
    int minimum();
    int maximum();
};


veb :: veb(int u)
{
    this->u = u;
    this->min = NULL;
    this->max = NULL;

    if (u == 2)
    {
        this->summary = NULL;
        this->cluster = NULL;
    }
    else
    {
        int sub_size = sqrt(u);
        this->summary = new veb(sub_size);
        this->cluster = new veb*[sub_size];
    }

}


void veb::insert(int x)
{
    if (u == 2)
    {
        if (x == 0)
        {
            if (max == NULL)
            {
                max = new int;
                min = new int;
                *max = x;
                *min = x;
            }
            else
                *min = x;
        }
        else if (x == 1)
        {
            if (min == NULL)
            {
                max = new int;
                min = new int;
                *max = x;
                *min = x;
            }
            else
                *max = x;
        }
    }
    else
    {
        if (min == NULL)
        {
            min = new int;
            max = new int;
            *max = x;
            *min = x;
            this->insert(x);
        }
        else
        {
            if ((*min) > x)
            {
                *min = x;
                this->insert(x);
            }
            else
            {
                int subsize = sqrt(u);
                int high = x / subsize, low = x % subsize;
                if (cluster[high] == NULL)
                {
                    cluster[high] = new veb(subsize);
                    cluster[high]->insert(low);
                    summary->insert(high);
                }
                else
                    cluster[high]->insert(low);
                if ((*max) < x)
                    *max = x;
            }
        }
    }
}


void veb::remove(int x)
{
    if (u == 2)
    {


        if (x == 0)
        {
            if (min != NULL)
            {
                if (*max == 0)
                {
                    min = NULL;
                    max = NULL;
                }
                else
                    *min = 1;
            }
        }
        else if (max != NULL)
        {

            if (*min == 1)
            {
                min = NULL;
                max = NULL;
            }
            else
                *max = 0;
        }

    }
    else
    {

        int subsize = sqrt(u);
        int high = x / subsize, low = x % subsize;
        if (min == NULL || cluster[high] == NULL)
            return;
        if (x == *min)
        {

            if (x == *max)
            {
                min = NULL;
                max = NULL;
                cluster[high]->remove(low);
                return;
            }

            cluster[high]->remove(low);

            if (cluster[high]->min == NULL)
            {
                delete cluster[high];
                cluster[high] = NULL;
                summary->remove(high);
            }
            int newminhigh = summary->minimum();
            int newminlow = cluster[newminhigh]->minimum();
            *min = newminhigh * subsize + newminlow;
        }
        else
        {
            cluster[high]->remove(low);

            if (cluster[high]->min == NULL)
            {
                delete cluster[high];
                cluster[high] = NULL;
                summary->remove(high);
            }
            if (x == *max)
            {
                int newmaxhigh = summary->maximum();
                int newmaxlow = cluster[newmaxhigh]->maximum();
                *max = newmaxhigh * subsize + newmaxlow;
            }
        }

    }
}

int* veb::pred(int x)
{
    if (u == 2)
    {
        if (x == 0)
            return NULL;
        else if (x == 1)
        {
            if (min == NULL)
                return NULL;
            else if ((*min) == 1)
                return NULL;
            else
                return min;
        }
        else
            return NULL;
    }
    else
    {
        if (min == NULL)
            return NULL;
        if ((*min) >= x)
            return NULL;
        if (x > (*max))
            return max;
        int subsize = sqrt(u);
        int high = x / subsize;
        int low = x % subsize;
        if (cluster[high] == NULL)
        {
            int *pred = summary->pred(high);
            int *ans = new int;
            *ans = (*pred) * subsize + *(cluster[*pred]->max);
            return ans;
        }
        else
        {
            int *ans_high = new int;
            int *ans_low = new int;

            if (low > *(cluster[high]->min))
            {
                *ans_high = high;
                ans_low = cluster[high]->pred(low);
            }
            else
            {
                ans_high = summary->pred(high);
                ans_low = cluster[(*ans_high)]->max;
            }

            int *ans = new int;
            *ans = (*ans_high) * subsize + (*ans_low);
            return ans;
        }
    }

}

int veb::minimum()
{
    return *min;
}

int veb::maximum()
{
    return *max;
}

void findpred(veb *x, int y)
{
    int *temp = x->pred(y);
    if (temp == NULL)
        cout << "no predecesor" << endl;
    else
        cout << "predecesor of " << y << " is " << *temp << endl;

}

int main()
{
    veb      *x = new veb(16);
    x->insert(2);
    x->insert(3);
    x->insert(4);
    x->insert(5);
    x->insert(7);
    x->insert(14);
    x->insert(15);


    cout << x->minimum() << endl << x->maximum() << endl;



    findpred(x, 0);
    findpred(x, 1);
    findpred(x, 2);
    findpred(x, 3);
    findpred(x, 4);
    findpred(x, 5);
    findpred(x, 6);
    findpred(x, 7);
    findpred(x, 8);
    findpred(x, 9);
    findpred(x, 10);
    findpred(x, 11);
    findpred(x, 12);
    findpred(x, 13);
    findpred(x, 14);
    findpred(x, 15);
    findpred(x, 16);
    findpred(x, 7);

    x->remove(15);
    x->remove(5);

    findpred(x, 0);
    findpred(x, 1);
    findpred(x, 2);
    findpred(x, 3);
    findpred(x, 4);
    findpred(x, 5);
    findpred(x, 6);
    findpred(x, 7);
    findpred(x, 8);
    findpred(x, 9);
    findpred(x, 10);
    findpred(x, 11);
    findpred(x, 12);
    findpred(x, 13);
    findpred(x, 14);
    findpred(x, 15);
    findpred(x, 16);
    findpred(x, 7);

}
