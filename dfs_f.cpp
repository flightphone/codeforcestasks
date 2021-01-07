#include <stdio.h>
#include <vector>
#include <ctime> 
#include <iostream>
using namespace std;
bool is_solution (vector<int> &a, int k, int n)
{
    return (k==n-1);
}


void process_solution(vector<int> &a, int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

vector<int> construct_candidates(vector<int> &a, int k, int n)
{
    vector<int> b(n, 0);
    for (int i = 0; i < k; i++)
    {
        b[a[i]] = 1;
    }
    vector<int> res(n-k);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i]==0)
        {
            res[j]=i;
            j++;
        }
    }
    return res;
}

void backtrack(vector<int> &a, int k, int n)
{
    if (is_solution (a, k, n))
    {
        process_solution(a, k, n);
    }
    else
    {
        k++;
        vector<int> c = construct_candidates(a, k, n);
        int nc = c.size();
        for (int i=0; i<nc; i++)
        {
            a[k] = c[i];
            backtrack(a, k, n);
        }

    }
    
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n = 5;
    int k = -1;
    vector<int> a(n, 0);
    backtrack(a, k, n);
}