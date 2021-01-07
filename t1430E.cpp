#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    long n;
    scanf("%ld", &n);
    long long d = 0;
    vector<char> a(n);
    vector<char> b(n);
    char c;
    scanf("%c", &c);
    for (long i = 0; i < n; i++)
    {
        scanf("%c", &c);
        a[i] = c;
        b[n-1-i] = c;
    }
    for (long i=0; i < n; i++)
    {
        if (a[i]==b[i])
            continue;

        long j = i;
        while (a[j]!= b[i])
        {
            j++;
        }
        d = d + j - i;
        for (long k = j; k > i; k--)
            a[k] = a[k-1];

    }
    printf("%lld", d);

}