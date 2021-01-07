#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long d;
        int k;
        scanf("%lld", &d);
        scanf("%d", &k);
        double q2 = sqrt(2.0);
        double h = d / q2;
        int n = h / k;
        double l = n*k*1.0;
        double ld = sqrt(d * d * 1.0 - l * l) - l;
        if (ld < k)
        {
            printf("Utkarsh\n");
        }
        else
        {
            printf("Ashish\n");
        }
        

    }
}    