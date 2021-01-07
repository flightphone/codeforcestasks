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
/*
    long q;
    cin >> q;
    while (q--)
    {
*/        

        string s;
        string t;
        cin >> s;
        cin >> t;

        long long n = t.size();
        long long n1 = s.size();

        if (n != n1)
        {
             cout << "No" << endl;
             return 0;
        }

        if (t == s)
        {
             cout << "Yes" << endl;
             cout << 0 << endl;
             return 0;   
        }

        string s1 = s;
        reverse(s1.begin(), s1.end());

        /*
        if (t == s1)
        {
             cout << "Yes" << endl;
             cout << (n - 1) << endl;
             return 0;   
        }
        */
        string t1 = t;
        reverse(t1.begin(), t1.end());
        

        string r = s + (char)9 + t1;
        string r1 = s1 + (char)9 + t1;
        vector<long long> z = z_function(r);
        vector<long long> z1 = z_function(r1);

        long long km = z[n+1];
        if (km == 0)
        {
             cout << "No" << endl;
             return 0;
        }
        for (long long i = 0; i < km; i++)
        {
            if (z1[n + i + 2] == (n - i - 1))
            {
                
                 cout << "Yes" << endl;
                 cout << i+1 << endl;
                 return 0;   
            }
        }


        cout << "No" << endl;
    //}
}