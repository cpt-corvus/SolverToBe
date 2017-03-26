
#include <iostream>
using namespace std;

const int N = 1000;
int p[N];

int find(int u) {
	if (p[u] == u)
		return u;

	return p[u] = find(p[u]);
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		p[i] = i;

	while (m--) {
		int a, b;
		cin >> a >> b;

		a = find(a);
		b = find(b);

		if (a != b) {
			p[a] = b;
		}
	}
	return 0;
}