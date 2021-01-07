#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    long t;
    scanf("%d", &t);
    while (t--)
    {
        long n;
        scanf("%ld", &n);
        vector<long long> a(n);
        for (long i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        vector<bool> b(n, false);
        long long res = 0;
        long istart = 0;
        while (true)
        {
            while (b[istart])
            {
                if (istart < n - 1)
                    istart++;
                else
                    break;
            }
            if (b[istart] && (istart == n - 1))
                break;

            b[istart] = true;
            long long ti = istart;
            long long tres = 0;
            b[ti] = true;
            while (ti < n)
            {
                tres = tres + a[ti];
                ti = ti + a[ti];
                if (ti < n)
                {
                    if (b[ti])
                        break;
                    else
                        b[ti] = true;
                }
            }
            if (tres > res)
                res = tres;
        }
        printf("%lld\n", res);
    }
}