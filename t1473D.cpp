#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//http://codeforces.com/problemset/problem/1473/D

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        cin >> m;
        string p;
        cin >> p;
        n = n + 1;
        int a[n];
        int lmin[n];
        int lmax[n];
        int rmin[n];
        int rmax[n];
        int x = 0;
        a[0] = x;
        for (int i = 1; i < n; i++)
        {
            if (p[i - 1] == '+')
                x++;
            else
                x--;
            a[i] = x;
        }
        lmin[0] = a[0];
        lmax[0] = a[0];
        rmin[0] = a[n - 1];
        rmax[0] = a[n - 1];
        for (int i = 1; i < n; i++)
        {
            lmin[i] = (a[i] < lmin[i - 1]) ? a[i] : lmin[i - 1];
            lmax[i] = (a[i] > lmax[i - 1]) ? a[i] : lmax[i - 1];
            int j = n - 1 - i;
            rmin[i] = (a[j] < rmin[i - 1]) ? a[j] : rmin[i - 1];
            rmax[i] = (a[j] > rmax[i - 1]) ? a[j] : rmax[i - 1];
        }

        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l;
            cin >> r;
            int d = a[r] - a[l - 1];
            l--;
            r++;
            int lmi = lmin[l];
            int lma = lmax[l];
            int ans = lma - lmi + 1;
            if (r < n)
            {
                r = n - 1 - r;
                int ans1 = rmax[r] - rmin[r] + 1;
                lmi = lmi + d;
                lma = lma + d;
                int l1 = max(rmin[r], lmi);
                int r1 = min(rmax[r], lma);
                if (r1 >= l1)
                {
                    ans1 = ans1 - (r1 - l1 + 1);
                }
                ans = ans + ans1;
            }
            cout << ans << endl;
        }
    }
}