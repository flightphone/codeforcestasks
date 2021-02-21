#include <stdio.h>
#include <vector>

using namespace std;
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d", &n);
        scanf("%d", &m);
        int a[n];
        int b[n];
        int c[m];
        int resc[m];
        for (int i = 0; i < m; i++)
            resc[i] = -1;

        vector<int> ac[n + 1];
        vector<int> bc[n + 1];
        vector<int> mc[n + 1];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            //ac[a[i]].push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
            if (b[i] != a[i])
            {
                bc[b[i]].push_back(i);
            }
            else
            {
                ac[a[i]].push_back(i);
            }
            
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%d", &c[i]);
            mc[c[i]].push_back(i);
        }
        //Перекрашиваем
        bool res = true;
        for (int i = 1; i <= n; i++)
        {
            int na = bc[i].size();
            int nm = mc[i].size();
            if (na == 0)
                continue;
            if (na > nm)
            {
                res = false;
                break;
            }
            for (int j = 0; j < na; j++)
            {
                resc[mc[i][j]] = bc[i][j];
            }
            for (int j = na; j < nm; j++)
            {
                resc[mc[i][j]] = bc[i][na - 1];
            }
        }
        
        if (!res)
        {
            printf("NO\n");
            continue;
        }

        if (resc[m-1] == -1)
        {
            int cl = c[m-1];
            if (ac[cl].size() == 0)
            {
                res = false;
            }
            else
            {
                resc[m-1] = ac[cl][0];
            }
        }
        
        if (!res)
        {
            printf("NO\n");
            continue;
        }
        
        for (int i = 0; i < m; i++)
        {
            if (resc[i] == -1)
                resc[i] = resc[m-1];
        }
        
        

        
        printf("YES\n");
        for (int i = 0; i < m; i++)
        {
            printf("%d ", (resc[i] + 1));
        }
        printf("\n");
    }
    return 0;
}