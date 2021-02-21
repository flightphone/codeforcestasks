#include <iostream>
#include <vector>
#include <string>
using namespace std;
//http://codeforces.com/problemset/problem/1481/D
void sisolve(int lsolve[], int nsolve, int m)
{
    cout << "YES" << endl;
    if (nsolve == 2)
    {
        int n2 = (m + 1) / 2;
        for (int i = 0; i < n2; i++)
        {
            cout << lsolve[0] << " " << lsolve[1] << " ";
        }
        if ((m + 1) % 2 == 1)
            cout << lsolve[0];
        cout << endl;
        return;
    }

    if (nsolve == 3)
    {
        int n3 = (m + 1) / 3;
        for (int i = 0; i < n3; i++)
        {
            cout << lsolve[0] << " " << lsolve[1] << " " << lsolve[2] << " ";
        }
        int md = (m + 1) % 3;
        for (int i = 0; i < md; i++)
        {
            cout << lsolve[i] << " ";
        }
        cout << endl;
        return;
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int m;
        cin >> n;
        cin >> m;
        string s;
        char a[3];
        char b[3];
        for (int i = 0; i < 3; i++)
        {
            a[i] = 'z';
            b[i] = 'x';
        }
        cin >> s;
        a[0] = s[1];
        if (n > 2)
            b[0] = s[2];
        cin >> s;
        b[1] = s[0];
        if (n > 2)
        {
            a[1] = s[2];
            cin >> s;
            a[2] = s[0];
            b[2] = s[1];
        }

        for (int i = 3; i < n; i++)
        {
            cin >> s;
        }

        if (m == 1)
        {
            cout << "YES" << endl
                 << "1 2" << endl;
            continue;
        }

        int lsolve[3];
        int nsolve;
        if (a[0] == a[1] && a[1] == a[2])
        {
            nsolve = 3;
            lsolve[0] = 1;
            lsolve[1] = 2;
            lsolve[2] = 3;
            sisolve(lsolve, nsolve, m);
        }
        else if (a[0] == b[1] || a[1] == b[2] || a[2] == b[0])
        {
            nsolve = 2;
            if (a[0] == b[1])
            {
                lsolve[0] = 1;
                lsolve[1] = 2;
                sisolve(lsolve, nsolve, m);
                continue;
            }
            if (a[1] == b[2])
            {
                lsolve[0] = 2;
                lsolve[1] = 3;
                sisolve(lsolve, nsolve, m);
                continue;
            }
            if (a[2] == b[0])
            {
                lsolve[0] = 1;
                lsolve[1] = 3;
                sisolve(lsolve, nsolve, m);
                continue;
            }
        }
        else
        {
            if (n == 2)
            {
                if (m % 2 == 0)
                {
                    cout << "NO" << endl;
                    continue;
                }
                else
                {
                    cout << "YES" << endl;
                    int k = (m + 1) / 2;
                    for (int i = 0; i < k; i++)
                        cout << "1 2 ";

                    cout << endl;    
                    continue;    
                }
            }
            cout << "YES" << endl;
            if (a[0] == a[1])
            {
                lsolve[0] = 1;
                lsolve[1] = 2;
                lsolve[2] = 3;
            }
            else if (a[0] == a[2])
            {
                lsolve[0] = 3;
                lsolve[1] = 1;
                lsolve[2] = 2;
            }
            else
            {
                lsolve[0] = 2;
                lsolve[1] = 3;
                lsolve[2] = 1;
            }

            vector<int> res;
            int md = m % 3;
            int k = m / 3;
            if (md == 0)
            {
                for (int i = 0; i < k; i++)
                {
                    res.push_back(lsolve[1]);
                    res.push_back(lsolve[2]);
                    res.push_back(lsolve[0]);
                }
                res.push_back(lsolve[1]);
            }

            if (md == 2)
            {
                res.push_back(lsolve[0]);

                for (int i = 0; i < k; i++)
                {
                    res.push_back(lsolve[1]);
                    res.push_back(lsolve[2]);
                    res.push_back(lsolve[0]);
                }
                res.push_back(lsolve[1]);
                res.push_back(lsolve[2]);
            }

            if (md == 1)
            {
                if (k % 2 == 1)
                {
                    int k2 = k / 2;

                    for (int i = 0; i < k2; i++)
                    {
                        res.push_back(lsolve[1]);
                        res.push_back(lsolve[2]);
                        res.push_back(lsolve[0]);
                    }
                    res.push_back(lsolve[1]);
                    res.push_back(lsolve[2]);
                    res.push_back(lsolve[1]);
                    res.push_back(lsolve[0]);

                    for (int i = 0; i < k2; i++)
                    {
                        res.push_back(lsolve[1]);
                        res.push_back(lsolve[2]);
                        res.push_back(lsolve[0]);
                    }
                    res.push_back(lsolve[1]);
                }
                else
                {
                    int k2 = (k - 2) / 2;

                    for (int i = 0; i < k2; i++)
                    {
                        res.push_back(lsolve[1]);
                        res.push_back(lsolve[2]);
                        res.push_back(lsolve[0]);
                    }
                    res.push_back(lsolve[1]);

                    res.push_back(lsolve[2]);
                    res.push_back(lsolve[1]);

                    res.push_back(lsolve[2]);
                    res.push_back(lsolve[0]);
                    res.push_back(lsolve[1]);

                    res.push_back(lsolve[0]);

                    for (int i = 0; i < k2; i++)
                    {
                        res.push_back(lsolve[1]);
                        res.push_back(lsolve[2]);
                        res.push_back(lsolve[0]);
                    }
                    res.push_back(lsolve[1]);
                }
            }

            int nz = res.size();
            for (int i = 0; i < nz; i++)
            {
                cout << res[i] << " ";
            }
            cout << endl;
            /*
            for (int i = 1; i < nz; i++)
            {
                if (res[i-1] == 1 & res[i] == 2)
                    cout << "a";
                if (res[i-1] == 2 & res[i] == 3)    
                    cout << "a";
                if (res[i-1] == 3 & res[i] == 1)    
                    cout << "b";    

                if (res[i] == 1 & res[i-1] == 2)
                    cout << "b";
                if (res[i] == 2 & res[i-1] == 3)    
                    cout << "b";
                if (res[i] == 3 & res[i-1] == 1)    
                    cout << "a";        
            }
            cout << endl;    
            */
        }
    }
}