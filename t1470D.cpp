#include <stdio.h>
#include <vector>
#include <queue>
//https://codeforces.com/problemset/problem/1470/D

using namespace std;
struct ans
{
    bool res;
    vector<long> tpord;
};

ans bfs(vector<vector<long>> &gr)
{
    long n = gr.size() - 1;
    vector<int> tp(n + 1, 0);
    vector<long> tpord;
    queue<long> opened;
    tp[1] = 1;
    opened.push(1);
    while (!opened.empty())
    {
        long v = opened.front();
        int f = tp[v];
        int newf = (f == 1) ? 2 : 1;

        long size = gr[v].size();
        for (long i = 0; i < size; i++)
        {
            long u = gr[v][i];
            if (tp[u] == 0)
            {
                tp[u] = newf;
                opened.push(u);
            }
            else
            {
                if (tp[u] == f && f == 1)
                    tp[u] = 2;
            }
        }
        opened.pop();
    }
    ans a;
    a.res = true;
    for (long i = 1; i <= n; i++)
    {
        if (tp[i] == 0)
        {
            a.res = false;
            break;
        }
        else
        {
            if (tp[i] == 1)
                a.tpord.push_back(i);
        }
    }
    return a;
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
        //vector<long long> tdist(n + 1, 0);
        for (long i = 0; i < m; i++)
        {
            long u;
            long v;
            scanf("%ld", &u);
            scanf("%ld", &v);
            gr[u].push_back(v);
            //Для неориентированного графа
            gr[v].push_back(u);
        }
        ans a = bfs(gr);
        if (a.res)
        {
            printf("YES\n");
            long np = a.tpord.size();
            printf("%ld\n", np);
            for (long i = 0; i < np; i++)
                printf("%ld ", a.tpord[i]);
            printf("\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}