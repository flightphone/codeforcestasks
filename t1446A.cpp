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
    return (a.w < b.w);
}
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int nt;
    scanf("%d", &nt);
    while (nt--)
    {

        long n;
        long long W;
        scanf("%ld", &n);
        scanf("%lld", &W);
        vector<point> t(n);
        for (long i = 0; i < n; i++)
        {
            scanf("%lld", &t[i].w);
            t[i].i = i + 1;
        }
        sort(t.begin(), t.end(), comp);
        long long W2 = W / 2;
        W2 = W2 + (W % 2);
        long long s2 = t[0].w;
        if (s2 > W)
        {
            printf("-1\n");
        }
        else
        {
            if (s2 >= W2)
            {
                printf("1\n%ld\n", t[0].i);
            }
            else
            {
                for (long i = 1; i < n; i++)
                {
                    s2 = s2 + t[i].w;
                    if (s2 >= W2 && s2 <= W)
                    {
                        printf("%ld \n", (i + 1));
                        for (long j = 0; j <= i; j++)
                        {
                            printf("%ld ", t[j].i);
                        }
                        printf("\n");
                        break;
                    }

                    if (s2 > W)
                    {
                        if (t[i].w <= W && t[i].w >= W2)
                        {
                            printf("1\n%ld\n", t[i].i);
                        }
                        else
                        {
                            printf("-1\n");
                        }
                        break;
                    }

                    if (i == n - 1 && s2 < W2)
                    {
                        printf("-1\n");
                    }
                }
            }
        }
    }
}