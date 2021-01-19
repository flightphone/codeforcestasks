#include <stdio.h>
#include <algorithm>
using namespace std;


const int MAXN = 100000;
long long t[4 * MAXN];

pair<int,int> t_mm[4*MAXN];
const int MAX_MIN = 1000000007;
 
pair<int,int> combine (pair<int,int> a, pair<int,int> b) {
	if (a.first < b.first)
		return a;
	if (b.first < a.first)
		return b;
	return make_pair (a.first, a.second + b.second);
    //Возвращает позицию максимума/минимума
    //return make_pair (a.first, a.second);
}
 
void build_mm (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t_mm[v] = make_pair (a[tl], 1);
        //Позиция максимума/минимума 
        //t_mm[v] = make_pair (a[tl], tl);
	else {
		int tm = (tl + tr) / 2;
		build_mm (a, v*2, tl, tm);
		build_mm (a, v*2+1, tm+1, tr);
		t_mm[v] = combine (t_mm[v*2], t_mm[v*2+1]);
	}
}
 
pair<int,int> get_max (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return make_pair (MAX_MIN, 0);
	if (l == tl && r == tr)
		return t_mm[v];
	int tm = (tl + tr) / 2;
	return combine (
		get_max (v*2, tl, tm, l, min(r,tm)),
		get_max (v*2+1, tm+1, tr, max(l,tm+1), r)
	);
}
 
void update_mm (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t_mm[v] = make_pair (new_val, 1);
        //Возвращает позицию максимума/минимума
        //t_mm[v] = make_pair (new_val, tl);
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update_mm (v*2, tl, tm, pos, new_val);
		else
			update_mm (v*2+1, tm+1, tr, pos, new_val);
		t_mm[v] = combine (t_mm[v*2], t_mm[v*2+1]);
	}
}


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
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    //build_sum(a, 1, 0, n - 1);
    build_mm(a, 1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        int o, l, r;
        scanf("%d", &o);
        scanf("%d", &l);
        scanf("%d", &r);
        if (o == 1)
        {
            //update_sum(1, 0, n-1, l, r);
            update_mm(1, 0, n-1, l, r);
        }
        else
        {
            //long long s = get_sum(1, 0, n-1, l, r-1);
            pair<int,int> s = get_max(1, 0, n-1, l, r-1);
            printf("%d %d\n", s.first, s.second);
        }
       
    }
   
        
}