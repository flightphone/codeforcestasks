#include <stdio.h>
#include <algorithm>
using namespace std;


const int MAXN = 100000;
long long t[4 * MAXN];

pair<int, int> t_mm[4 * MAXN];
const int MAX_MIN = -1000000007;

pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    //return make_pair (a.first, a.second + b.second);
    //Возвращает позицию максимума/минимума
    return make_pair(a.first, max(a.second, b.second));
}

void build_mm(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        //t_mm[v] = make_pair (a[tl], 1);
        //Позиция максимума/минимума
        t_mm[v] = make_pair(a[tl], tl);
    else
    {
        int tm = (tl + tr) / 2;
        build_mm(a, v * 2, tl, tm);
        build_mm(a, v * 2 + 1, tm + 1, tr);
        t_mm[v] = combine(t_mm[v * 2], t_mm[v * 2 + 1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return make_pair(MAX_MIN, 0);
    if (l == tl && r == tr)
        return t_mm[v];
    int tm = (tl + tr) / 2;
    return combine(
        get_max(v * 2, tl, tm, l, min(r, tm)),
        get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

pair<int, int> get_x(int v, int tl, int tr, int x, int l)
{
    if (t_mm[v].first < x)
        return make_pair(-1, -1);
    if (l > tr)
        return make_pair(-1, -1);
    if (tl == tr)
        return t_mm[v];

    int tm = (tl + tr) / 2;
    if (t_mm[v * 2].first >= x)
    {
        pair<int, int> test = get_x(v * 2, tl, tm, x, l);
        if (test.second == -1)
        {
            return get_x(v * 2 + 1, tm + 1, tr, x, l);
        }
        else
        {
            return test;
        }
    }
    else
    {
        return get_x(v * 2 + 1, tm + 1, tr, x, l);
    }
}



void update_mm(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        //t_mm[v] = make_pair (new_val, 1);
        //Возвращает позицию максимума/минимума
        t_mm[v] = make_pair(new_val, tl);
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_mm(v * 2, tl, tm, pos, new_val);
        else
            update_mm(v * 2 + 1, tm + 1, tr, pos, new_val);
        t_mm[v] = combine(t_mm[v * 2], t_mm[v * 2 + 1]);
    }
}

void build_sum(int a[], int v, int tl, int tr)
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

pair<int, int> get_sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return make_pair(0, l);
    if (l == tl && r == tr)
        return t_mm[v];
    int tm = (tl + tr) / 2;
    pair<int, int> t1 = get_sum(v * 2, tl, tm, l, min(r, tm));
    pair<int, int> t2 = get_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return make_pair(t1.first + t2.first, t2.second);
}


pair<int, int> get_sumx(int v, int tl, int tr, int x, int d)
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
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    
    /*
    build_sum(a, 1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        int o;
        int x;
        scanf("%d", &o);
        scanf("%d", &x);
        if (o == 1)
        {
            int newval = a[x];
            newval = (newval + 1) % 2;
            a[x] = newval;
            update_sum(1, 0, n - 1, x, newval);
        }
        else
        {
            pair<int, int> s = get_sumx(1, 0, n - 1, x + 1, 0);
            printf("%d\n", s.second);
        }
    }
    */

    
    build_mm(a, 1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {

        int o;
        scanf("%d", &o);
        if (o == 1)
        {
            int i, x;
            scanf("%d", &i);
            scanf("%d", &x);
            update_mm(1, 0, n - 1, i, x);
        }
        else
        {
            int x;
            scanf("%d", &x);
            int l;
            scanf("%d", &l);
            pair<int, int> s = get_x(1, 0, n - 1, x, l); 
            printf("%d\n", s.second);
        }
    }
    
}