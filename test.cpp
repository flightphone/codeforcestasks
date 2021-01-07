#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 5;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i+1;
    }
    //printf("%d", a.begin() - a.begin());

    vector<int>::iterator it =  upper_bound(a.begin(), a.end(), 10);
    printf("%d", it - a.begin());

}