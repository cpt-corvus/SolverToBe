
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
const int N = 100001;
const ll MOD = 1e9 + 7;
const double eps = 1e-9;

int n,a[N],seg[4*N];

void build(int p,int s,int e) {
	if(s==e) {
		seg[p] = a[s];
		return;
	}
	build(2*p,s,(s+e)/2);
	build(2*p+1,(s+e)/2+1,e);
	seg[p] = seg[2*p] + seg[2*p+1];
}

void update(int p,int s,int e,int i,int v) {
	if(s==e) {
		seg[p] = v;
		return;
	}
	if(i <= (s+e)/2)
		update(2*p,s,(s+e)/2,i,v); 
	else update(2*p+1,(s+e)/2+1,e,i,v);
	seg[p] = seg[2*p] + seg[2*p+1];
}

int get(int p,int s,int e,int a, int b) {
	if(s>=a && e<=b)
		return seg[p];
	if(s>b || e<a)
		return 0;
	return get(2*p,s,(s+e)/2,a,b) + get(2*p+1,(s+e)/2+1,e,a,b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

 	return 0;
}