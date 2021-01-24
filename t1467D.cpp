#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


bool comp(pair<int, long long> a, pair<int, long long> b)
{
    return (a.first < b.first);
}

using namespace std;
const int mod = 1000000007;
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t = 1;
    //scanf("%ld", &t);
    while (t--)
    {
        int n[3];
        long long s[3];
        int m[3];
        scanf("%d", &n[0]);
        scanf("%d", &n[1]);
        scanf("%d", &n[2]);
        for (int j = 0; j < 3; j++)
        {
            s[j] = 0;
            m[j] = mod;
            for (int i = 0; i < n[j]; i++)
            {
                int x;
                scanf("%d", &x);
                if (x < m[j])
                    m[j] = x;
                s[j] = s[j] + x;
            }
        }
        vector<pair<int, long long>> r(3);
        for (int i=0; i < 3; i++)
        {
          r[i].first = m[i];
          r[i].second = s[i];
        }
        long long mi = 0;
        sort(r.begin(), r.end(), comp);
        mi = r[0].first + r[1].first;
        if (r[0].second < mi)
        {
            mi = r[0].second;
        }
        for (int i = 0; i < 3; i++)
        {
            if (r[i].first == r[i].second && r[i].first < mi)
            {
                mi = r[i].first;
            }
        }

        long long ans = s[0]+s[1]+s[2] - 2 * mi;
        printf("%lld", ans);
    }
}