
// ~/BAU/ACM-ICPC/Teams/OverflowLimitExceeded/Corvus
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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 4001;
const ll MOD = 1e9 + 7;

int n, cnt, cmp, idx[N], low[N], comp[N], val[N], compH[N];
vector<rect> v;
bool in_stack[N];
stack<int> S;
vector<vector<int> > g;

inline int Not(int u) {
	return u >= n ? u - n : u + n;
}

inline void add(int a, int b) {
	g[Not(a)].push_back(b);
	g[Not(b)].push_back(a);
}

void dfs(int u) {
	idx[u] = low[u] = ++cnt;
	in_stack[u] = 1;
	S.push(u);

	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!idx[v])
			dfs(v);
		if (in_stack[v])
			low[u] = min(low[u], low[v]);
	}

	if (idx[u] == low[u]) {
		while (1) {
			int v = S.top();
			S.pop();
			in_stack[v] = 0;
			comp[v] = cmp;
			if (v == u) break;
		}
		compH[cmp] = u;
		cmp++;
	}
}

int main() {
	//2-SAT is satisfiability problem
	// (a1 v b1) ^ (a2 v b2) ^ .. = 1
	//chose values for a1, b1 ... to make sure the equation is evaluated to 1

	//n is number of variables
	//to add one term eg. (a1 v b1)
	//add(a1, b1);

	//we have 2*n node (one for each variable and the another for the compliment)
	for (int i = 0; i < 2 * n; i++)
		if (!idx[i])
			dfs(i);

	bool ok = 1;
	for(int i=0; i<n; i++)
		if (comp[i] == comp[Not(i)]) {
			ok = 0;
			break;
		}

	puts(ok ? "YES" : "NO"); //if ok==true the equation is satisfiable
	return 0;
}