#include <stdio.h>
using namespace std;

long long alog(long long a)
{
    long long a2 = a / 2;
    long long b = 1;
    while (b <= a2)
    {
        b = b * 2;
    }
    return b;
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
        scanf("%ld", &n);
        for (long i = 0; i < n; i++)
        {
            long long a;
            scanf("%lld", &a);
            long long b = alog(a);
            printf("%lld ", b);
        }
        printf("\n");
    }
}