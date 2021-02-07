#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct  ainv {
    vector<int> a;
    long long inv;
};

const int MAXN = 100000;
ainv t[4 * MAXN];

const int MAX_MIN = -1000000007;

ainv combine(vector<int> &a, vector<int> &b, long long l, long long r)
{
    vector<int> res(41, 0);
    for (int i = 1; i < 41; i++)
        res[i] = a[i] + b[i];
    ainv ret;
    ret.a = res;
    ret.inv = l + r;
    for (int i = 2; i < 41; i++)    
    {
        if (a[i] > 0)
        {
            for (int j = 1; j < i; j++)
            if (b[j] > 0)
            {
                ret.inv = ret.inv + (long long)a[i] * (long long)b[j];
            }
        }
    }
    return ret;
}

ainv makev(int a)
{
    vector<int> res(41, 0);
    res[a] = 1;
    ainv ret;
    ret.a = res;
    ret.inv = 0;
    return ret;
}

void build_sum(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        t[v] = makev(a[tl]);
    else
    {
        int tm = (tl + tr) / 2;
        build_sum(a, v * 2, tl, tm);
        build_sum(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2].a, t[v * 2 + 1].a, t[v * 2].inv, t[v * 2 + 1].inv);
    }
}

void update_sum(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        t[v] = makev(new_val);
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_sum(v * 2, tl, tm, pos, new_val);
        else
            update_sum(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2].a, t[v * 2 + 1].a, t[v * 2].inv, t[v * 2 + 1].inv);
    }
}

ainv get_sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return makev(0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    ainv t1 = get_sum(v * 2, tl, tm, l, min(r, tm));
    ainv t2 = get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return combine(t1.a, t2.a, t1.inv, t2.inv);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    build_sum(a, 1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        int o;
        int x;
        int y;
        scanf("%d", &o);
        scanf("%d", &x);
        scanf("%d", &y);
        if (o == 2)
        {
            x--;
            update_sum(1, 0, n - 1, x, y);
            a[x] = y;
        }
        else
        {
            x--;
            y--;
            ainv s = get_sum(1, 0, n - 1, x, y);
            printf("%lld\n", s.inv);
        }
    }

}