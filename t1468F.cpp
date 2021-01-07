#include <stdio.h>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

const double mod = 1000000007.0;

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
        map<double, long> pmap;
        map<double, long> mmap;

        vector<long long> pv;
        vector<long long> mv;

        for (long i = 0; i < n; i++)
        {
            long long x, y, u, v;
            scanf("%lld", &x); 
            scanf("%lld", &y); 
            scanf("%lld", &u); 
            scanf("%lld", &v); 
            
            double tg = 0.0;
            int sign = 0;
            if (x != u)
            {
                sign = (u > x) ? 1 : -1;
                tg = ((double)(v - y)) / ((double)(u - x));
            }
            else
            {
                sign = (v > y) ? 1 : -1;
                tg = mod;
            }
            if (sign > 0)
            {
                pmap[tg] = pmap[tg] + 1;
                mmap[tg] = mmap[tg] + 0;
            }
            else
            {
                pmap[tg] = pmap[tg] + 0;
                mmap[tg] = mmap[tg] + 1;
            }
        }
        for (auto it = pmap.begin(); it != pmap.end(); ++it)
        {
            pv.push_back(it->second);
        }
        for (auto it = mmap.begin(); it != mmap.end(); ++it)
        {
            mv.push_back(it->second);
        }

        long long res = 0;
        n = pmap.size();
        for (int i = 0; i < n; i++)
        {
            res = res + pv[i] * mv[i];
        }
        printf("%lld\n", res);
    }
}