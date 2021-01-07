#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
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
    /*
    long t;
    cin >> t;
    while(t--)
    {
    */
    string s;
    cin >> s;
    string p = s + "#" + s;
    long long n = s.size();
    for (long long i = 0; i < n; i++)
    {
        p[n + 1 + i] =  s[n - 1 - i];
    }

    vector<long long> z = z_function(p);
    for (long long i = 0; i < n; i++)
    {
        if (z[n + 1 + i] == (n - i))
        {
            cout << (n - i) << endl;
            break;
        }
    }

    //}
}