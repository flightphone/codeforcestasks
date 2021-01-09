#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
//https://codeforces.com/problemset/problem/1472/G

void backtrack(vector<vector<long>> &a, long v, vector<int> &tp, vector<long long> &tmin, vector<long long> &res)
{
    long n = a[v].size();
    tp[v] = 1;
    for (long i = 0; i < n; i++)
    {
        long u = a[v][i];
        if (tp[u] == 0)
            backtrack(a, u, tp, tmin, res);
    }
    res[v] = tmin[v];
    tp[v] = 2;
    for (long i = 0; i < n; i++)
    {
        long u = a[v][i];
        if (/*tp[u] == 2 &&*/ res[u] < res[v])
            res[v] = res[u];
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    long t;
    scanf("%ld", &t);
    while (t--)
    {
        long n;
        long m;
        scanf("%ld", &n);
        scanf("%ld", &m);
        vector<vector<long>> gr(n + 1);
        vector<int> tp(n + 1, 0);
        vector<int> tp1(n + 1, 0);
        vector<long long> tdist(n + 1, 0);
        vector<long long> tmin(n + 1, 0);
        vector<long long> res(n + 1, 0);
        vector<vector<long>> gr1(n + 1);
        for (long i = 0; i < m; i++)
        {
            long u;
            long v;
            scanf("%ld", &u);
            scanf("%ld", &v);
            gr[u].push_back(v);
            //Для неориентированного графа
            //gr[v].push_back(u);
        }
        queue<long> opened;
        tp[1] = 1;
        opened.push(1);
        

        while (!opened.empty())
        {
            long v = opened.front();
            long long d = tdist[v];
            long size = gr[v].size();
            for (long i = 0; i < size; i++)
            {
                long u = gr[v][i];
                if (tp[u] == 0)
                {
                    tp[u] = 1;
                    //tpord.push_back(u);
                    gr1[v].push_back(u);
                    opened.push(u);
                    tdist[u] = d + 1;
                    tmin[u] = tdist[u];
                }
                else
                {
                    if ((tdist[u] < tmin[v]))
                        tmin[v] = tdist[u];
                }
            }
            tp[v] = 2;
            opened.pop();
        }

        backtrack(gr1, 1, tp1, tmin, res);
        for (long i = 1; i <= n; i++)
        {
            printf("%ld ", res[i]);
        }
        printf("\n");
    }
}