#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

void backtrack(vector<vector<long>> &a, int v, vector<long> &tp, vector<long> &tpord)
{
    long n = a[v].size();
    tp[v] = 1;
    for (long i = 0; i < n; i++)
    {
        long u = a[v][i];
        if (tp[u] == 0)
            backtrack(a, u, tp, tpord);
    }
    tp[v] = 2;
    tpord.push_back(v);
}

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
        vector<long> tp(n + 1, 0);
        vector<long> tpord;
        
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
        
        backtrack(gr, 1, tp, tpord);

        for (long i = 0; i < n; i++)
            printf("%ld ", tpord[i]);

        printf("\n");
        
    }
}