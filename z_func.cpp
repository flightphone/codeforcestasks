#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    string s;
    string p;
    cin >> s;
    cin >> p;
    int n = p.length();
    
    string r = p + "@" + s;
    vector<int> z = z_function(r);
    int n1 = z.size();
    for (int i = 1; i < n1; i++)
    {
        if (z[i] == n)
            printf("%d ", i-n-1);
    }
    
}