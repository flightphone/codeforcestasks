#include <stdio.h>
#include <vector>
using namespace std;
int main()
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
        vector<long> k(n, -1);
        for (long i = 0; i < n; i++)
        {
            scanf("%ld", &a[i]);
        }
        long ns = n / 2;
        long nmin = -1;
        if (ns * 2 < n)
        {
            ns = ns;
            nmin = a[ns];
            k[ns] = nmin;
        }
        else
        {
            ns = ns - 1;
        }
        
        for (long i = ns + 1; i < n; i++)
        {
            if (nmin > a[i] || nmin == -1)
                nmin = a[i];
            if (nmin > a[n - i - 1] || nmin == -1)
                nmin = a[n - i - 1];
            k[i] = nmin;
        }
        for (long i = 0; i < n; i++)
        {
            printf("%ld ", k[i]);
        }
        printf("\n");
    }
}