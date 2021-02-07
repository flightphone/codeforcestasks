#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
//http://codeforces.com/problemset/problem/1478/C

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<long long> d(2 * n);
        for (int i = 0; i < 2 * n; i++)
            scanf("%lld", &d[i]);

        bool res = true;
        
        sort(d.begin(), d.end());
        unsigned long long delta = 0;
        long long ai_1 = 0;
        for (int i = n; i > 0; i--)
        {
            if (d[2 * i - 1] <= delta)
            {
                res = false;
                break;
            }
            long long test = d[2 * i - 1] - delta;
            if ((test % (2 * i) != 0) || (d[2 * i - 1] != d[2 * i - 2]))
            {
                res = false;
                break;
            }
            long long ai = test / i / 2;
            if (ai == ai_1)
            {
                res = false;
                break;
            }
            ai_1 = ai;
            //printf("%lld ", ai);
            delta = delta + test / i;
            
        }
        if (res)
            printf("YES\n");
        else
            printf("NO\n");
    }
}