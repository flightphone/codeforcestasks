#include <stdio.h>
#include <vector>
#include <algorithm>
//http://codeforces.com/problemset/problem/1475/D
using namespace std;
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t;
    scanf("%ld", &t);
    while (t--)
    {
        int n;
        int m;
        scanf("%d", &n);
        scanf("%d", &m);
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }
        vector<int> c1;
        vector<int> c2;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == 1)
                c1.push_back(a[i]);
            else
                c2.push_back(a[i]);
        }
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());

        int p1 = c1.size() - 1;
        int p2 = c2.size() - 1;
        int ans = 0;

        while ((p1 + p2) > -2)
        {

            int m11 = 0;
            int m12 = 0;
            int m2 = 0;
            if (p1 > -1)
            {
                m11 = c1[p1];
                if (p1 > 0)
                    m12 = c1[p1 - 1];
            }
            if (p2 > -1)
            {
                m2 = c2[p2];
            }

            if (m11 >= m)
            {
                ans = ans + 1;
                m = -1;
                break;
            }

            if ((m11 + m12) >= m)
            {
                ans = ans + 2;
                m = -1;
                break;
            }

            if (m2 >= m)
            {
                ans = ans + 2;
                m = -1;
                break;
            }

            if ((m11 + m2) >= m)
            {
                ans = ans + 3;
                m = -1;
                break;
            }

            if (m11 >= m2)
            {
                ans = ans + 1;
                m = m - m11;
                p1 = p1 - 1;
                continue;
            }

            if (m2 >= (m11 + m12))
            {
                m = m - m2;
                p2 = p2 - 1;
                ans = ans + 2;
            }
            else
            {
                if (2 * (m2 + m11) > 3 * (m11 + m12))
                {
                    m = m - m2 - m11;
                    ans = ans + 3;
                    p1 = p1 - 1;
                    p2 = p2 - 1;
                }
                else
                {
                    m = m - m11 - m12;
                    p1 = p1 - 1;
                    if (p1 > -1)
                        p1 = p1 - 1;
                    ans = ans + 2;    
                }
            }
        }
        if (m > 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
}