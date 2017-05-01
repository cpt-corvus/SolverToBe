
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

struct node {
	int num, dist;

	node() {
		num = 0, dist = 1e9;
	}

	node(int u, int d) {
		this->num = u;
		this->dist = d;
	}

	bool operator<(const node & o) const {
		if (dist != o.dist)
			return dist > o.dist;
		return num > o.num;
	}
};

const int N = 1000; //max num of nodes
int n, m;
vector<vector<pair<int, int> > > g;
int dist[N];

void dijkstra(int s) {
	for (int i = 0; i < n; i++)
		dist[i] = 1e9;
	dist[s] = 0;

	priority_queue<node> pq;
	pq.push(node(s, 0));

	while (!pq.empty()) {
		node u = pq.top();
		pq.pop();

		for (int i = 0; i < g[u.num].size(); i++) {
			int v = g[u.num][i].first;
			int c = g[u.num][i].second;

			if (dist[v] > dist[u.num] + c) {
				dist[v] = dist[u.num] + c;
				pq.push(node(v, dist[v]));
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);

	g.clear();
	g.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c)); 
	}

	dijkstra(0);
	
	return 0;
}