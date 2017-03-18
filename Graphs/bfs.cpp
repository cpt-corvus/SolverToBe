
// ~/BAU/ACM-ICPC/Teams/A++/BlackBurn95
// ~/sudo apt-get Accpeted

#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > g;
bool vis[10001];

void bfs(int u) {
	queue<int> s;
	vis[u] = 1;
	s.push(u);

	while (!s.empty()) {
		int v = s.front();
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

	bfs(0);

	return 0; 
}