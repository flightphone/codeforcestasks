#include <stdio.h>
#include <algorithm>
using namespace std;

struct data
{
    long long sum, pref, suff, ans;
};

const int MAXN = 100000;
data t[4 * MAXN];
const int MAX_MIN = 1000000007;

data combine(data l, data r)
{
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data(int val)
{
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = (0 > val)?0:val;
    return res;
}

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = make_data(a[tl]);
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        t[v] = make_data(new_val);
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%ld", &a[i]);

    build(a, 1, 0, n - 1);
    printf("%lld\n", t[1].ans);

    for (int i = 0; i < m; i++)
    {
        int l;
        scanf("%d", &l);
        int x;
        scanf("%d", &x);
        update(1, 0, n - 1, l, x);
        printf("%lld\n", t[1].ans);
    }
}