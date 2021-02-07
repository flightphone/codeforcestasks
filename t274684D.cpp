#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100000;
vector<int> t[4 * MAXN];

const int MAX_MIN = -1000000007;

vector<int> combine(vector<int> &a, vector<int> &b)
{
    vector<int> res(41, 0);
    for (int i = 1; i < 41; i++)
        res[i] = a[i] + b[i];
    return res;
}

vector<int> makev(int a)
{
    vector<int> res(41, 0);
    res[a] = 1;
    return res;
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
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
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
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

vector<int> get_sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return makev(0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    vector<int> t1 = get_sum(v * 2, tl, tm, l, min(r, tm));
    vector<int> t2 = get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return combine(t1, t2);
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
        }
        else
        {
            x--;
            y--;
            vector<int> s = get_sum(1, 0, n - 1, x, y);
            int ans = 0;
            for (int i = 1; i < 41; i++)
                if (s[i] > 0)
                    ans++;
            printf("%d\n", ans);
        }
    }

}