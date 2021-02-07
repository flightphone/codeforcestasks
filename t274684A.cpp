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
    scanf("%d", &n);
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (i % 2 == 0)
            a[i] = x;
        else
            a[i] = -x;
    }
    build_sum(a, 1, 0, n - 1);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int o;
        scanf("%d", &o);
        if (o == 0)
        {
            int i;
            int j;
            scanf("%d", &i);
            scanf("%d", &j);
            i--;
            if (i % 2 == 1)
                j = -j;
            update_sum(1, 0, n - 1, i, j);
        }
        else
        {
            int l;
            int r;
            scanf("%d", &l);
            scanf("%d", &r);
            l--;
            r--;
            long long ans = get_sum(1, 0, n - 1, l, r);
            if (l % 2 == 1)
                ans = -ans;
            printf("%lld\n", ans);
        }
    }

    return 0;
}