#include <stdio.h>
#include <vector>
using namespace std;

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
        res[i].second = (st[p][l] < st[p][r - p2[p] + 1])? stinx[p][l] : stinx[p][r - p2[p] + 1];

    }

    return res;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    long n;
    scanf("%ld", &n);
    vector<long long> a(n);
    for (long i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    long q;
    scanf("%ld", &q);
    vector<pair<long, long>> qu(q);
    for (long i = 0; i < q; i++)
    {
        long long l;
        long long r;
        scanf("%lld", &l);
        scanf("%lld", &r);
        pair<long, long> pr;
        pr.first = l;
        pr.second = r;
        qu[i] = pr;
    }

    vector<pair<long long, long>> res = sparseTable(a, qu);
    for (long i = 0; i < q; i++)
        printf("%lld ", res[i].first);

    printf("\n");

    for (long i = 0; i < q; i++)
        printf("%lld ", res[i].second);
}