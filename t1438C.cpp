#include <stdio.h>
#include <vector>

using namespace std;

bool finished = false;

bool is_stop(vector<vector<long>> &a, vector<vector<int>> &b, int n, int m, int i, int j)
{
    bool r = false;
    if (i > 0)
    {
        if ((a[i][j] + b[i][j]) == (a[i-1][j] + b[i-1][j]))
            return true;
    }
    if (j > 0) 
    {
        if ((a[i][j] + b[i][j]) == (a[i][j-1] + b[i][j-1]))
            return true;
    }
    return r;       
}

void pr(vector<vector<long>> &a, vector<vector<int>> &b, int n, int m)
{
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%ld ", (a[i][j]+b[i][j]));
            }
            printf("\n");
        }
}

void back(vector<vector<long>> &a, vector<vector<int>> &b, int n, int m, int i, int j)
{
    if (finished)
    return;
    if (!is_stop(a, b, n, m, i, j))
    {
        if (i== n-1 && j == m-1)
        {
            finished = true;
            pr(a, b, n, m);
        }
        else
        {
            if (j==m-1)
            {
                i++;
                j=0;
            }
            else
            {
                j++;
            }
            b[i][j] = 0;
            back(a, b, n, m, i, j);
            if (finished)
                return;
            b[i][j] = 1;
            back(a, b, n, m, i, j);    

        }
        
    }
    
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        finished = false;
        int n;
        int m;
        scanf("%d", &n);
        scanf("%d", &m);
        vector<vector<long>> a(n);
        vector<vector<int>> b(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                long e;
                scanf("%ld", &e);
                a[i].push_back(e);
                b[i].push_back(0);
            }    
        }
        back(a, b, n, m, 0, -1);
        //pr(a, b, n, m);
        
    }
}