#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
int main6()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t;
    scanf("%ld", &t);
    while (t--)
    {
        long n;
        scanf("%ld", &n);
        vector<long> a(n);
        for (long i = 0; i < n; i++)
        {
            scanf("%ld", &a[i]);
        }
        long l0 = -1;
        long l1 = -1;
        long h = -1;
        bool flagl = true;
        string r = "YES";
        for (long i = 1; i < n; i++)
        {
            if (flagl)
            {
                if (a[i] > a[i - 1])
                {
                    if (l0 == -1)
                    {
                        l0 = a[i - 1];
                    }
                    else
                    {
                        l1 = a[i - 1];
                        l0 = l0 + l1 - h;
                        if (l0 < 0)
                        {
                            r = "NO";
                            break;
                        }
                    }
                    flagl = false;
                }
                
            }
            else
            {
                if (a[i] < a[i - 1])
                {
                    flagl = true;
                    h = a[i - 1];
                }
            }
            
        }

        if (flagl && l0 > -1 && r == "YES")
        {
            l1 = a[n-1];
            l0 = l0 + l1 - h;
            if (l0 < 0)
            {
                r = "NO";
            }
        }
        printf("%s\n", r.c_str());
    }
}