

//-------------------------------------------------------------------------------------------
//----------------------------------- unweighted graph --------------------------------------
//-------------------------------------------------------------------------------------------

int n, m;
vector<vector<int> > g;

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

	return 0; 
}



//-------------------------------------------------------------------------------------------
//------------------------------------- weighted graph --------------------------------------
//-------------------------------------------------------------------------------------------

int n, m;
vector<vector<pair<int,int> > > g;

int main() {

	scanf("%d%d", &n, &m);

	g.clear();
	g.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		g[a].push_back(make_pair(b,c)); // a -> b with cost c
		g[b].push_back(make_pair(a,c)); // b -> a with cost c (for un-directed graph)
	}

	return 0; 
}