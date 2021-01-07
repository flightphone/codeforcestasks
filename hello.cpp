#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    long a;
    long b;
};
bool comp(point a, point b)
{
    return (a.a > b.a);
}
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int nt;
    scanf("%ld", &nt);
    for (int in = 0; in < nt; in++)
    {
        long n;
        scanf("%ld", &n);
        vector<point> t(n);
        for (long i = 0; i < n; i++)
        {
            scanf("%ld", &t[i].a);
        }
        for (long i = 0; i < n; i++)
        {
            scanf("%ld", &t[i].b);
        }
        sort(t.begin(), t.end(), comp);
        long r = 0;
        long r1  = 0;
        for (long i = 0; i < n; i++)
        {
            r1 = r + t[i].b;
            if (r1 >= t[i].a)
            {
                r = max(t[i].a, r);
                break;
            }
            else
            {
                r = r1;
            }
            
        }
        printf ("%ld\n", r);
    }
}