#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int t;
    scanf("%lld", & t);
    while (t--)
    {
        long long int b, w, bc, wc, z;
        scanf("%lld %lld %lld %lld %lld", & b, & w, & bc, & wc, & z);
        long long int m;
        if (bc > (wc + z))
        {
            m = (w * wc) + ((wc + z) * b);
        }
        else if (wc > (bc + z))
        {
            m = (b * bc) + (w * (bc + z));
        }
        else
        {
            m = (b * bc) + (w * wc);
        }
        printf("%lld\n", m);
    }
}
