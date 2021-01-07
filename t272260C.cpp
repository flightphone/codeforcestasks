#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> z_function(string s)
{
    int n = (long long)s.length();
    vector<long long> z(n);
    for (long long i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && (s[z[i]] == s[i + z[i]] || s[z[i]] == '?'))
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    long t;
    cin >> t;
    while (t--)
    {

        string s;
        string p;
        cin >> s;
        cin >> p;
        int n = p.length();
        string ps = p + "@" + s;
        vector<long long> z = z_function(ps);
        long long n1 = z.size();
        vector<long long> r;
        for (long long i = n + 1; i < n1; i++)
        {
            if (z[i] == n)
                r.push_back(i - n - 1);
        }
        long long rs = (long long)r.size();
        printf("%lld\n", rs);
        for (long long i = 0; i < rs; i++)
            printf("%lld ", r[i]);
        printf("\n");
    }
}