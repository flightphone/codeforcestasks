#include <stdio.h>
#include <vector>
using namespace std;
int main1()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    scanf("%ld", &t);
    while (t--)
    {
        long n;
        scanf("%ld", &n);
        vector<long> a(n);
        vector<long> level(n, 0);
        for (long i = 0; i < n; i++)
        {
            scanf("%ld", &a[i]);
        }
        long current = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i-1])
            {
                current++;
            }
            level[i] = level[current] + 1;
        }
        printf("%ld\n", level[n-1]);
    }
}
