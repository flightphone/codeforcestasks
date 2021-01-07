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
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
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

    long q;
    cin >> q;
    while (q--)
    {

        string s;
        string t;
        cin >> s;
        cin >> t;

        long long n = t.size();
        long long n1 = s.size();

        string rs = t + "#" + s;
        vector<long long> z = z_function(rs);

        long long nt = 0;
        long long start = 0;

        for (long long i = 0; i < n1; i++)
        {
            if (z[i + n + 1] == n)
            {
                long long l = i - start + 1;
                long long r = n1 - (i + z[i + n + 1] - 1);
                start = i + 1;
                nt = nt + l * r;
                
            }
        }

        long long res = (n1 * (n1 - 1)) / 2 + n1 - nt;
        cout << res << endl;
    }
}