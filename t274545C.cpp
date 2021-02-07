#include <stdio.h>
#include <algorithm>
using namespace std;


const int MAXN = 200000;
long long t[4 * MAXN];


void build_sum(int a[], int v, int tl, int tr)
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


long long get_sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return get_sum (v*2, tl, tm, l, min(r,tm))
		+ get_sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update_sum (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update_sum (v*2, tl, tm, pos, new_val);
		else
			update_sum (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n;
    scanf("%d", &n);
    int a[2*n];
    int l[n];
    int r[n];
    int res[n];
    for (int i = 0; i < n; i++)
    {
        l[i] = -1;
        r[i] = -1;
    }
    for (int i = 0; i < 2*n; i++)
    {
        a[i] = 0;
    }
    build_sum(a, 1, 0, 2*n-1);
    for (int i = 0; i < 2*n; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        if (l[x] == -1)
        {
            l[x] = i;
        }
        else
        {
            r[x] = i;
            long long ans = get_sum(1, 0, 2*n-1, l[x], r[x]);
            res[x] = ans;
            update_sum(1, 0, 2*n-1, l[x], 1);
        }
    }
    
    
    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);
    return 0;
}