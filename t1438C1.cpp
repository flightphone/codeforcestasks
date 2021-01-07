#include <stdio.h>
#include <vector>

using namespace std;


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


int main8()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {

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
                int o1 = e%2;
                int o2 = (i+j)%2;
                if (o1!=o2)
                    b[i].push_back(1);
                else
                {
                    b[i].push_back(0);
                }
                    
            }    
        }
        pr(a, b, n, m);
        
    }
}