#include <stdio.h>
#include <vector>

using namespace std;
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    long n;
    scanf("%ld", &n);

    long a[4];
    long b[4];
    for (int i = 0; i < 3; i++)
    {
        scanf("%ld", &a[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        scanf("%ld", &b[i]);
    }

    a[3]=a[0];
    b[3]=b[0]; 
    long long mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[3]);
    long long mi = 0;
    for (int i = 1; i < 4; i++)
    {
        if (a[i] > (b[i]+b[i-1]))
        {
            long long d = a[i] - (b[i]+b[i-1]);
            if (mi==0)
            {
                mi = d;
            }    
            else
            {
                if (d < mi)   
                    mi = d;
            }
        }
    }
    printf("%lld %lld", mi, mx);

}