#include <string>
#include <iostream>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    long q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        long n = s.size();
        long res = 0;
        for (long i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                s[i] = '#';
                res++;
                continue;
            }
            if (i > 1)
                if (s[i] == s[i - 2])
                {
                    s[i] = '#';
                    res++;
                }
        }
        cout << res << endl;
    }
}