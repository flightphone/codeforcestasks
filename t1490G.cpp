#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
//http://codeforces.com/problemset/problem/1490/G
bool comp(pair<long long, int> a, pair<long long, int> b)
{

    return (a.first < b.first);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int msize = 200000;
    int lg[msize + 1];
    for (long i = 0; i <= msize; i++)
    {
        lg[i] = (i > 1 ? lg[i / 2] + 1 : 0);
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d", &n);
        scanf("%d", &m);
        int a[n];
        long long suma = 0;
        long long msuma = 0;
        vector<pair<long long, int>> sums(n);

        vector<long long> sms(n);
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            suma = suma + a[i];
            if (msuma < suma)
                msuma = suma;
            sums[i] = make_pair(suma, i);
        }
        int x[m];
        long long res[m];
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &x[i]);
        }
        sort(sums.begin(), sums.end(), comp);
        for (int i = 0; i < n; i++)
        {
            sms[i] = sums[i].first;
            pos[i] = sums[i].second;
        }
        //Строим разреженную таблицу для pos

        long size = pos.size();
        vector<long long> p2;
        int np = 0;
        for (np = 0; (1 << np) <= size; np++)
        {
            p2.push_back(1 << np);
        }

        long long st[np][size];
        long stinx[np][size];
        for (long i = 0; i < size; i++)
        {
            st[0][i] = pos[i];
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
        //Строим разреженную таблицу для pos

        for (int i = 0; i < m; i++)
        {
            if (suma <= 0 && msuma < x[i])
            {
                res[i] = -1;
                continue;
            }
            if (msuma >= x[i])
            {
                //Запрос к таблице
                vector<long long>::iterator it;
                it = lower_bound(sms.begin(), sms.end(), x[i]);
                int l = it - sms.begin();
                int r = n - 1;
                int p = lg[r - l + 1];
                res[i] = min(st[p][l], st[p][r - p2[p] + 1]);
            }
            else
            {
                long long k = (x[i] - msuma) / suma;
                if (((x[i] - msuma) % suma) != 0)
                    k++;
                res[i] = (long long)n * k;
                x[i] = x[i] - k * suma;
                //Запрос к таблице
                vector<long long>::iterator it;
                it = lower_bound(sms.begin(), sms.end(), x[i]);
                int l = it - sms.begin();
                int r = n - 1;
                int p = lg[r - l + 1];
                res[i] = res[i] + min(st[p][l], st[p][r - p2[p] + 1]);
            }
        }
        for (int i = 0; i < m; i++)
            printf("%lld ", res[i]);

        printf("\n");
    }
    return 0;
}