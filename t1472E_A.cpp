#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const long long mod = 1000000007;

struct point
{
    long long h;
    long long w;
    long i;
};
bool comp(point a, point b)
{
    return (a.h < b.h);
}

vector<pair<long long, long>> sparseTable_0_i(vector<long long> &a)
{
    long size = a.size();
    long long cmin = a[0];
    long cinx = 0;
    vector<pair<long long, long>> res(size);
    res[0].first = cmin;
    res[0].second = cinx;
    for (long i = 0; i < size; i++)
    {
        if (a[i] < cmin)
        {
            cmin = a[i];
            cinx = i;
        }
        res[i].first = cmin;
        res[i].second = cinx;
    }

    return res;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {

        long n;
        scanf("%ld", &n);
        vector<point> f(n);
        vector<long> res(n);
        for (long i = 0; i < n; i++)
        {
            long long h;
            long long w;
            scanf("%lld", &h);
            scanf("%lld", &w);
            f[i].i = i;
            if (h > w)
            {
                f[i].h = h;
                f[i].w = w;
            }
            else
            {
                f[i].h = w;
                f[i].w = h;
            }
        }
        sort(f.begin(), f.end(), comp);
        vector<long long> ws(n);
        for (long i = 0; i < n; i++)
        {
            ws[i] = f[i].w;
        }
        vector<pair<long long, long>> minw = sparseTable_0_i(ws);

        long long ch = f[0].h;
        long long cw = mod;
        long cinx = -1;
        res[f[0].i] = cinx;
        for (long i = 1; i < n; i++)
        {
            if (f[i].h == ch)
            {
                if (f[i].w > cw)
                {
                    res[f[i].i] = f[cinx].i;
                }
                else
                {
                    res[f[i].i] = -1;
                }
            }
            else
            {
                ch = f[i].h;
                cinx = minw[i - 1].second;
                cw = minw[i - 1].first;

                if (f[i].w > cw)
                {
                    res[f[i].i] = f[cinx].i;
                }
                else
                {
                    res[f[i].i] = -1;
                }
            }
        }

        for (long i = 0; i < n; i++)
        {
            if (res[i] > -1)
                res[i] = res[i] + 1;
            printf("%ld ", res[i]);
        }
        printf("\n");
    }
}
