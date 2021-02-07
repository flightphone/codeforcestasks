#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
long long t[4 * MAXN];

void build_sum(long long a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build_sum(a, v * 2, tl, tm);
        build_sum(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

long long get_sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return get_sum(v * 2, tl, tm, l, min(r, tm)) + get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update_sum(int v, int tl, int tr, int pos, long long new_val)
{
    if (tl == tr)
        t[v] = new_val;
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_sum(v * 2, tl, tm, pos, new_val);
        else
            update_sum(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    build_sum(a, 1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        int o;
        scanf("%d", &o);
        if (o == 1)
        {
            int l;
            int r;
            int v;
            scanf("%d", &l);
            scanf("%d", &r);
            scanf("%d", &v);
            a[l] = a[l] + v;
            update_sum(1, 0, n - 1, l, a[l]);
            if (r < n)
            {
                a[r] = a[r] - v;
                update_sum(1, 0, n - 1, r, a[r]);
            }
        }
        else
        {
            int ii;
            scanf("%d", &ii);
            long long ans = get_sum(1, 0, n - 1, 0, ii);
            printf("%lld\n", ans);
        }
    }

    return 0;
}