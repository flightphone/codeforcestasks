#include <stdio.h>
#include <vector>
using namespace std;

long long l, r, t, x, y;
bool mres = false;

void backtrack(long long k, long long i)
{
    if (mres)
        return;

    if (i == t - 1)
    {
        mres = true;
        return;
    }
    else
    {
        i++;
        long long l1 = k + y - x;
        if (l1 >= l && l1 <= r && (k + y) >= l && (k + y) <= r)
            backtrack(l1, i);
        if (mres)
            return;
        l1 = k - x;
        if (l1 >= l && l1 <= r && k >= l && k <= r)
            backtrack(l1, i);
    }
}



int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    long long k;
    scanf("%lld", &k);
    scanf("%lld", &l);
    scanf("%lld", &r);
    scanf("%lld", &t);
    scanf("%lld", &x);
    scanf("%lld", &y);
    long long i = -1;
    backtrack(k, i);
    if (mres)
        printf("Yes");
    else
    {
        printf("No");
    }
        
}