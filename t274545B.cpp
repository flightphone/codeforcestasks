#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

pair<long long, int> t_mm[4 * MAXN];
const int MAX_MIN = -1000000007;

void build_sum(long long a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t_mm[v] = make_pair(a[tl], tl);
    }
    else
    {
        int tm = (tl + tr) / 2;
        build_sum(a, v * 2, tl, tm);
        build_sum(a, v * 2 + 1, tm + 1, tr);
        t_mm[v] = make_pair(t_mm[v * 2].first + t_mm[v * 2 + 1].first, t_mm[v * 2 + 1].second);
    }
}

pair<int, int> get_sumx(int v, int tl, int tr, long long x, long long d)
{
    if (t_mm[v].first < x - d)
        return make_pair(-1, -1);

    if (tl == tr)
        return make_pair(t_mm[v].first + d, t_mm[v].second);

    int tm = (tl + tr) / 2;
    if (t_mm[v * 2].first >= x - d)
    {
        return get_sumx(v * 2, tl, tm, x, d);
    }
    else
    {
        return get_sumx(v * 2 + 1, tm + 1, tr, x, d + t_mm[v * 2].first);
    }
}

void update_sum(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        t_mm[v] = make_pair(new_val, tl);
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_sum(v * 2, tl, tm, pos, new_val);
        else
            update_sum(v * 2 + 1, tm + 1, tr, pos, new_val);
        t_mm[v] = make_pair(t_mm[v * 2].first + t_mm[v * 2 + 1].first, t_mm[v * 2 + 1].second);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n;
    scanf("%d", &n);
    long long s[n];
    long long g[n];
    int r[n];
    for (long i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        s[i] = i-x;
        g[i] = 1;
    }
    build_sum(g, 1, 0, n - 1);

    for (long j = 0; j < n; j++)
    {
        long i = n - 1 - j;
        long long a = s[i]+1;
        int k = 0;
        pair<long long, int> s = get_sumx(1, 0, n - 1, a, 0);
        k = s.second;

        r[i] = k+1;
        g[k] = 0;
        update_sum(1, 0, n - 1, k, 0);
    }
    for (long i = 0; i < n; i++)
        printf("%lld ", r[i]);
    return 0;
}