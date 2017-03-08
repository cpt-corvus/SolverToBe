
// ~/BAU/ACM-ICPC/Teams/A++/BlackBurn95
// ~/sudo apt-get Accpeted

#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;

int n, m;
vector<vector<int> > g;
bool vis[10001];

void dfs(int u) {
	vis[u] = 1;

	for (int i = 0; i < g[u].size(); i++)
		if (!vis[g[u][i]])
			dfs(g[u][i]);
}

void dfs_stack(int u) {
	stack<int> s;
	vis[u] = 1;
	s.push(u);

	while (!s.empty()) {
		int v = s.top();
		s.pop();

		for (int i = 0; i < g[v].size(); i++)
			if (!vis[g[v][i]]) {
				vis[g[v][i]] = 1;
				s.push(g[v][i]);
			}
	}
}

int main() {
	scanf("%d%d", &n, &m);

	g.clear();
	g.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		g[a].push_back(b); // a -> b
		g[b].push_back(a); // b -> a (for un-directed graph)
	}

	memset(vis, 0, sizeof(vis));

	dfs(0); // or    dfs_stack(0);

	return 0; 
}