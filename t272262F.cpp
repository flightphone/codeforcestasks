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

        string r = t + "@" + s;
        vector<long long> z = z_function(r);

        long long n1 = z.size();

        string resstr, r1;
        resstr = s + t;

        bool res = false;
        for (long long i = n + 1; i < n1; i++)
        {
            if ((z[i] == n) || ((z[i] + i) == n1))
            {
                if (z[i] == n)
                {
                    cout << s << endl;
                    res = true;
                    break;
                }
                else
                {
                    r1 = s + t.substr(z[i], n - z[i]);
                    if (r1.length() < resstr.length())
                        resstr = r1;

                    break;
                }
            }
        }
        if (res)
            continue;

        r = s + "@" + t;
        n = s.size();
        z = z_function(r);
        for (long long i = n + 1; i < n1; i++)
        {
            if ((z[i] == n) || ((z[i] + i) == n1))
            {
                if (z[i] == n)
                {
                    cout << t << endl;
                    res = true;
                    break;
                }
                else
                {
                    r1 = s + t.substr(z[i], n - z[i]);
                    if (r1.length() < resstr.length())
                        resstr = r1;

                    break;
                }
            }
        }
        if (res)
        {
            continue;
        }
        else
        {
            cout << resstr << endl;
        }
        

    }
}