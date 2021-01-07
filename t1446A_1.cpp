#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    long long w;
    long i;
};
bool comp(point a, point b)
{
    return (a.w > b.w);
}
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int nt;
    scanf("%d", &nt);
    while (nt--)
    {

        long n;
        long long W;
        scanf("%ld", &n);
        scanf("%lld", &W);
        vector<point> t(n);
        vector<long> res;
        for (long i = 0; i < n; i++)
        {
            scanf("%lld", &t[i].w);
            t[i].i = i + 1;
        }
        sort(t.begin(), t.end(), comp);
        long long W2 = (W + 1) / 2;
        long long s2 = 0;
        for (long i = 0; i < n; i++)
        {
            if ((s2 + t[i].w) <= W)
            {
                s2 = s2 + t[i].w;
                res.push_back(t[i].i);
            }
        }
        if (s2 < W2)
        {
            printf("-1\n");
        }
        else
        {
            long nr = res.size();
            printf("%ld \n", nr);
            for (long j = 0; j < nr; j++)
            {
                printf("%ld ", res[j]);
            }
            printf("\n");
        }
    }
}
