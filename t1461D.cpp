#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void add(vector<long> &a, vector<long long> &suma, vector<long long> &vrsum, vector<long>::iterator begin, vector<long>::iterator end)
{

    long ibegin = begin - a.begin();
    long iend = end - a.begin();
    vrsum.push_back(suma[iend] - suma[ibegin]);
    if (ibegin == iend)
        return;
    long d = (a[ibegin] + a[iend-1]) / 2;
    vector<long>::iterator mid = upper_bound(begin, end, d);
    if (mid==end || mid == begin)
        return;
    add(a, suma, vrsum, begin, mid);
    add(a, suma, vrsum, mid, end);
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long n;
        long q;
        scanf("%ld", &n);
        scanf("%ld", &q);
        vector<long> a(n);
        vector<long long> s(q);
        vector<long long> suma(n + 1);
        for (long i = 0; i < n; i++)
        {
            scanf("%ld", &a[i]);
        }

        for (long i = 0; i < q; i++)
        {
            scanf("%lld", &s[i]);
        }

        sort(a.begin(), a.end());
        suma[0] = 0;
        for (long i = 0; i < n; i++)
        {
            suma[i + 1] = suma[i] + a[i];
        }
        vector<long long> vrsum;
        add(a, suma, vrsum, a.begin(), a.end());
        sort(vrsum.begin(), vrsum.end());
        for (int i = 0; i < q; i++)
        {
            if (binary_search(vrsum.begin(), vrsum.end(), s[i]))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
                
        }

    }
}