#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
 
long long bfs(vector<vector<long>> &g, long start)
{
    long n = g->size();
    vector<vector<long>> gp = (*g);
    bool proc[n];
    bool disco[n];
    long parent[n];
    for (long i = 0; i < n; i++)
    {
        proc[i] = false;
        disco[i] = false;
        parent[i] = -1;
    }
    queue<long> q;
    long v;
    long y;
    disco[start] = true;
    q.push(start);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        //process(v) //Посетили вершину v
        proc[v] = true;
        vector<long> p = gp[v];
        for (long i = 0; i < p.size(); i++)
        {
            y = p[i];
            //process(v,y) // Посетили ребро v,y
 
            if (!disco[y])
            {
                q.push(y);
                disco[y] = true;
                parent[y] = v;
            }
        }
    }
 
    long long res = (long long)n;
    for (long i = 0; i < n; i++)
    {
        long x = i;
        long p = parent[x];
        while (p != -1)
        {
            res++;
            x = p;
            p = parent[x];
        }
    }
    return res;
}
 
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    long n;
    scanf("%ld", &n);
    //И как встану я поутру, обойду я граф в ширину
    vector<long> e;
    vector<vector<long>> graph(n, e);
 
    for (long i = 0; i < n - 1; i++)
    {
        long u, v;
        scanf("%ld%ld", &u, &v);
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<long> g1;
    for (long i = 0; i < n; i++)
    {
        if (graph[i].size() == 1)
            g1.push_back(i);
    }
    long n1 = g1.size();
    long long maxs[n1];
    for (long i = 0; i < g1.size(); i++)
        maxs[i] = bfs(graph, g1[i]);
 
    long long res = maxs[0];
    for (long i = 1; i < n1; i++)
        if (res < maxs[i])
            res = maxs[i];
    printf("%lld", res);
    return 0;