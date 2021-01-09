#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

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
        vector<long> tpord;
        vector<long long> tdist(n + 1, 0);
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
        queue<long> opened;
        tp[1] = 1;
        opened.push(1);
        tpord.push_back(1);

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
                    tpord.push_back(u);
                    opened.push(u);
                    tdist[u] = d + 1;
                }
            }
            opened.pop();
        }

        for (long i = 0; i < n; i++)
            printf("%ld ", tpord[i]);

        printf("\n");
        for (long i = 0; i < n; i++)
        {
            long v = tpord[i];
            printf("%ld ", tdist[v]);
        }
    }
}