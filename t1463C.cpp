#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int msign(long long a)
{
    return ((a < 0) ? -1 : 1);
}

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
        vector<long long> t(n);
        vector<long long> x(n);
        for (long i = 0; i < n; i++)
        {
            scanf("%lld", &t[i]);
            scanf("%lld", &x[i]);
        }
        long r = 0;
        long long xstart = 0;
        long long xstop = x[0];
        long long tstart = t[0];
        long long tstop = t[0] + abs(x[0]);
        bool flagRun = true;
        for (long i = 1; i < n; i++)
        {
            if (t[i] >= tstop)
            {
                if (flagRun)
                {
                    r++;
                }
                //Начинаем новое движение
                xstart = xstop;
                xstop = x[i];
                tstart = t[i];
                tstop = t[i] + abs(xstop - xstart);
                flagRun = true;
            }
            else
            {
                //активное движение неуспешно
                flagRun = false;
                long long tu = -1;
                if (msign(x[i] - xstart) == msign(xstop - xstart))
                {
                    tu = tstart + abs(x[i] - xstart);
                }
                if (tu >= t[i] && tu <= tstop)
                {
                    if (i == n - 1)
                    {
                        r++;
                    }
                    else
                    {
                        if (tu <= t[i+1])
                            r++;
                    }
                }
            }
        }
        if (flagRun)
            r++;
        printf("%ld\n", r);    
    }
}