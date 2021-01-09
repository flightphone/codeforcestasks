#include <stdio.h>
#include <vector>
#include <algorithm>
//https://codeforces.com/problemset/problem/1472/D
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
        vector<long long> a(n, 0);
        long long asum = 0;
        long long bsum = 0;
        for (long i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }

        if (n % 2 == 1)
        {
            a.push_back(0);
            n++;
        }

        sort(a.begin(), a.end());
        long n2 = n / 2;
        for (long i = 0; i < n2; i++)
        {
            if (a[n - 1 - 2 * i] % 2 == 0)
                asum = asum + a[n - 1 - 2 * i];

            if (a[n - 1 - (2 * i + 1)] % 2 == 1)
                bsum = bsum + a[n - 1 - (2 * i + 1)];
        }

        
        if (asum == bsum)
        {
            printf("%s\n", "Tie");
        }
        else
        {
            if (asum > bsum)
            {
                printf("%s\n", "Alice");
            }
            else
            {
                printf("%s\n", "Bob");
            }
        }
    }
}