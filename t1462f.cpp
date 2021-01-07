#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    long long l;
    long long r;
};

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    long t;
    scanf("%ld", &t);
    while (t--)
    {
        long n;
        scanf("%ld", &n);
        vector<long long> l(n);
        vector<long long> r(n);
        vector<point> lr(n);
        for (long i = 0; i < n; i++)
        {
            scanf("%lld", &l[i]);
            scanf("%lld", &r[i]);
            point p;
            p.l = l[i];
            p.r = r[i];
            lr[i] = p;
        }
        sort(l.begin(), l.end());
        long long rmax = 0;
        for (long i = 0; i < n; i++)
        {
            if (rmax < r[i])
                rmax = r[i];
        }
        for (long i = 0; i < n; i++)
        {
            r[i] = rmax - r[i];
        }
        sort(r.begin(), r.end());
        long minn = n;
        for (long i = 0; i < n; i++)
        {
            vector<long long>::iterator ri = upper_bound(l.begin(), l.end(), lr[i].r);
            long rn = 0;
            if (ri != l.end())
            {
                rn = l.end() - ri;
            }

            vector<long long>::iterator li = upper_bound(r.begin(), r.end(), rmax - lr[i].l);
            long ln = 0;
            if (li != r.end())
            {
                ln = r.end() - li;
            }
            if ((ln + rn) < minn)
                minn = ln + rn;
            if (minn == 0)
                break;
        }
        printf("%ld\n", minn);
    }
}