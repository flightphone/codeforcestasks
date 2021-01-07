#include <stdio.h>
#include <vector>
using namespace std;



int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    long T;
    scanf("%ld", &T);
    while (T--)
    {
        long n;
        scanf("%ld", &n);
        vector<int> ab(2 * n, 0);
        for (long i = 0; i < n; i++)
        {
            long x;
            scanf("%ld", &x);
            ab[x - 1] = 1;
        }
        long res = 1;
        long sl = 0;
        n = 2*n;
        for (long i = 0; i < n; i++)
        {
            if (ab[i] == 1)
            {
                if (sl > 0)
                {
                    sl--;
                    ab[i] = 2;
                }
            }
            else
            {
                sl++;
            }
        }
        long rl = 0;
        for (long i = 0; i < n; i++)
        {
            long j = n-1-i;
            if (ab[j] == 0)
            {
                rl++;
            }
            else
            {
                if (ab[j] == 2)
                {
                    if (rl > 0)
                    {
                        rl--;
                        res++; 
                    }
                }
                else
                {
                    if (rl > 0)
                    {
                        rl--;
                    }
                    else
                    {
                        break;
                    }
                    
                }
                
            }
            
        }
        printf("%ld\n", res);
    }
}