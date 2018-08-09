
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

int n, m, f[N];
char s[N], t[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%s%s",s,t);
	n = strlen(s);
	m = strlen(t);

	for(int i=1,j=0; i<m; i++) {
		while(j && t[i]!=t[j])
			j = f[j-1];
		if(t[i]==t[j]) j++;
		f[i] = j; 
	}

	for(int i=0,j=0; i<n; i++) {
		while(j && s[i]!=t[j])
			j = f[j-1];
		if(s[i]==t[j]) j++;
		if(j==m) {
			printf("occurence at %d\n", i-m+1);
			j = f[j-1];
		}
	}
 	return 0;
} 