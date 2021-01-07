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

vector<pair<long long, long>> sparseTable(vector<long long> &a, vector<pair<long, long>> &qu)
{
    long size = a.size();
    vector<long long> p2;
    int np = 0;
    for (np = 0; (1 << np) <= size; np++)
    {
        p2.push_back(1 << np);
    }
    long lg[size + 1];
    for (long i = 0; i <= size; i++)
    {
        lg[i] = (i > 1 ? lg[i / 2] + 1 : 0);
    }
    long long st[np][size];
    long stinx[np][size];
    for (long i = 0; i < size; i++)
    {
        st[0][i] = a[i];
        stinx[0][i] = i;
    }
    for (int p = 1; p < np; p++)
    {
        for (long i = 0; i + p2[p] <= size; i++)
        {
            st[p][i] = min(st[p - 1][i], st[p - 1][i + p2[p - 1]]);
            stinx[p][i] = (st[p - 1][i] < st[p - 1][i + p2[p - 1]]) ? stinx[p - 1][i] : stinx[p - 1][i + p2[p - 1]];
        }
    }

    long nqu = qu.size();
    vector<pair<long long, long>> res(nqu);
    for (long i = 0; i < nqu; i++)
    {
        long l = qu[i].first;
        long r = qu[i].second;
        int p = lg[r - l + 1];
        res[i].first = min(st[p][l], st[p][r - p2[p] + 1]);
        res[i].second = (st[p][l] < st[p][r - p2[p] + 1]) ? stinx[p][l] : stinx[p][r - p2[p] + 1];
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
        vector<pair<long, long>> qu(n);
        for (long i = 0; i < n; i++)
        {
            ws[i] = f[i].w;
            qu[i].first = 0;
            qu[i].second = i;
        }
        vector<pair<long long, long>> minw = sparseTable(ws, qu);

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
