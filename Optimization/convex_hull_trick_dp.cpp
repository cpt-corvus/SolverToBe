
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
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 100001;
const ll MOD = 1e9 + 7;
const double eps = 1e-9;

int top;
vector<pair<ll, ll> > s;

inline bool bad(int a, int b, pair<int, int> c) { //check if line is irrelevant (intesection between a and c is <= intersection of a and b)
	return (s[a].first - s[b].first)*(c.second - s[a].second) <= (s[a].first - c.first)*(s[b].second - s[a].second);
}

void addLine(ll m, ll c) { //add line m*x+c
	while (s.size() >= 2 && bad(s.size() - 2, s.size() - 1, make_pair(m, c))) 
		s.pop_back();
	s.push_back(make_pair(m, c));
}

ll query(ll x) { //return minimum value m*x+c
	if (top >= s.size()) top = s.size() - 1;
	while (top < s.size() - 1 && s[top].first*x + s[top].second >= s[top + 1].first*x + s[top + 1].second)
		++top;
	return s[top].first*x + s[top].second;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	return 0;
}
