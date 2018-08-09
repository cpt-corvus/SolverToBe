
// ~/BAU/ACM-ICPC/Teams/Rampage/Corvus
// ~/sudo apt-get verdict Accpeted

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 100005;
const ll MOD = 1e9+7;
const double eps = 1e-9;

int n, z[N];
char s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%s",s);
	n = strlen(s);

	int l = 0,r = 0;
	for(int i=0; i<n; i++) {
		if(i>r) {
			l = i,r = i;
			while(r<n && s[r-i]==s[r]) r++;
			r--;
			z[i] = r-l+1;
		} else {
			if(r-i+1 > z[i-l]) z[i] = z[i-l];
			else {
				l = i;
				while(r<n && s[r-i]==s[r]) r++;
				r--;
				z[i] = r-l+1;
			}
		}
	}

	for(int i=0; i<n; i++)
		printf("%d: %d\n", i, z[i]);
 	return 0;
} 