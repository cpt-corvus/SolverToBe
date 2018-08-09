
// ~/BAU/ACM-ICPC/Teams/Rampage/Corvus
// ~/sudo apt-get verdict Accpeted
//Suffix Array O(N * log^2 )
//LCP O(N)
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

int n, suff[N], ord[N], tmpOrd[N], lcp[N];
char s[N];

void build_suffix_array() {
	++n;
	for(int i=0; i<n; i++) {
		suff[i] = i;
		ord[i] = s[i];
	}
	for(int len=1; ; len *= 2) {
		sort(suff,suff+n,[&len](int a,int b) {
			return ord[a] < ord[b] || (ord[a]==ord[b] && ord[a+len] < ord[b+len]);
		});
		for(int i=1; i<n; i++) 
			tmpOrd[i] = tmpOrd[i-1] + (ord[suff[i]]!=ord[suff[i-1]] || ord[suff[i]+len]!=ord[suff[i-1]+len]);
		for(int i=0; i<n; i++)
			ord[suff[i]] = tmpOrd[i];
		if(tmpOrd[n-1]==n-1) break;
	}
	--n;
	for(int i=0; i<n; i++)
		suff[i] = suff[i+1];
}

void build_LCP() {
	vector<int> iv(n);
	for(int i=0; i<n; i++)
		iv[suff[i]] = i;
	for(int i=0, j, k = 0; i<n; i++) {
		j = iv[i];
		if(j==0) {
			lcp[j] = -1;
			continue;
		}
		j = suff[j-1];
		while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
		lcp[iv[i]] = k;
		if(k) k--;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%s",s);
	n = strlen(s);

	build_suffix_array();

	string t = string(s);
	for(int i=0; i<n; i++)
		cout<<suff[i]<<" : "<<t.substr(suff[i])<<endl;

	build_LCP();
	
	for(int i=0; i<n; i++)
		cout<<i<<" : "<<lcp[i]<<endl;
 	return 0;
} 