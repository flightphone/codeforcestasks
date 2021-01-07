#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<long long> z_function(string s)
{
    int n = (long long)s.length();
    vector<long long> z(n);
    for (long long i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

long long culc(string s)
{
    vector<long long> z = z_function(s);
    long long n = s.size();
    map<long long, int> zl;
    map<long long, int> zculc;
    long long smax = 0;
    for (long long i = 0; i < n; i++)
    {
        if (z[i] > 0)
        {
            if (i + z[i] == n)
            {
                zl[z[i]] = 1;
            }
            else
            {
                zl[z[i]] = 0;
            }
            
        }
    }

    for (auto it = zl.begin(); it != zl.end(); ++it)
    {
        smax = smax + it->second;
        zculc[it->first] = smax;
    }
    long long res = n - smax - 1;
    for (long long i = 0; i < n; i++)
    {
        if (z[i] > 0)
            res = res + z[i] - zculc[z[i]];
    }
    return res;
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
        cin >> s;
        long long r = culc(s);
        reverse(s.begin(), s.end());
        r = r + culc(s);
        cout << r << endl;
    }
}