
//Split-Merge Treap
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

struct node {
	int v, p, sz;
	int lazy;
	node * L, *R;

	node() {
		p = rand() % int(1e9);
		L = NULL;
		R = NULL;
		sz = 1;
		lazy = 0;
	}

	node(int v) {
		p = rand() % int(1e9);
		L = NULL;
		R = NULL;
		sz = 1;
		lazy = 0;
		this->v = v;
	}
};

struct treap {
	node * root;

	treap() {
		root = NULL;
		srand(time(NULL));
	}

	treap(node * root) {
		this->root = root;
		srand(time(NULL));
	}

	node * rotate_left(node * R) {
		node * y = R->R;
		node * T2 = y->L;
		R->R = T2;
		y->L = R;
		fix(R), fix(y);
		return y;
	}

	node * rotate_right(node * R) {
		node * x = R->L;
		node * T2 = x->R;
		R->L = T2;
		x->R = R;
		fix(R), fix(x);
		return x;
	}

	inline int get_size(node * R) {
		return R == NULL ? 0 : R->sz;
	}

	inline void fix(node * R) {
		if (R == NULL) return;
		R->sz = get_size(R->L) + get_size(R->R) + 1;
	}

	void push(node * R) {
		if (R == NULL)
			return;
		if (R->lazy) {
			swap(R->L, R->R);
			if (R->L != NULL)
				R->L->lazy ^= 1;
			if (R->R != NULL)
				R->R->lazy ^= 1;
			R->lazy = 0;
		}
	}

	int get_size() {
		return get_size(root);
	}

	node * insert(node * cur, int k, node * newNode) {
		if (cur == NULL)
			return newNode;

		push(cur);

		int tmp = get_size(cur->L) + 1;
		if (tmp >= k) {
			cur->L = insert(cur->L, k, newNode);
			if ((cur->L == NULL ? 0 : cur->L->p) > cur->p)
				cur = rotate_right(cur);
		}
		else {
			cur->R = insert(cur->R, k - tmp, newNode);
			if ((cur->R == NULL ? 0 : cur->R->p) > cur->p)
				cur = rotate_left(cur);
		}

		fix(cur);
		return cur;
	}

	void insert(int v, int k) { // insert value v at index k (1-based indexed) 
		root = insert(root, k, new node(v));
	}

	void erase(int k) {
		push(root);
		pair<treap, treap> u1 = split(k);
		pair<treap, treap> u2 = u1.second.split(2);
		root = u1.first.merge(u2.second).root;
		fix(root);
	}

	pair<treap, treap> split(node * cur, int k) {
		node * newNode = new node(-1);
		newNode->p = 2e9;
		node * temp = insert(root, k, newNode);
		node * a = temp->L, *b = temp->R;
		push(a), push(b);
		fix(a), fix(b);
		delete temp;
		return make_pair(treap(a), treap(b));
	}

	//split treap [1...N] => [1...k-1], [k...N] 
	pair<treap, treap> split(int k) {
		if (k < 1) return make_pair(treap(), *this);
		else if (k > get_size(root)) return make_pair(*this, treap());
		return split(root, k);
	}

	node * merge(node * a, node * b) {
		if (a == NULL) return b;
		if (b == NULL) return a;
		push(a), push(b);
		if (a->v > b->v) {
			a->R = merge(a->R, b);
			fix(a);
			return a;
		}
		else {
			b->L = merge(a, b->L);
			fix(b);
			return b;
		}
	}

	treap merge(treap o) {
		return treap(merge(root, o.root));
	}

	void reverse() {
		if (root == NULL)
			return;
		root->lazy ^= 1;
		push(root);
	}

	int get_kth(node * cur, int k) {
		if (cur == NULL)
			return -1;

		push(cur);

		int tmp = get_size(cur->L) + 1;

		if (k == tmp)
			return cur->v;

		if (k < tmp)
			return get_kth(cur->L, k);
		return get_kth(cur->R, k - tmp);
	}

	int get_kth(int k) {
		return get_kth(root, k);
	}
	
	void print() {
		int n = get_size(root);
		for(int i=1; i<=n; i++)
			printf("%d ", get_kth(i));
		puts("");
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	const int n = 10;
	treap T;

	puts("Inital Treap...");
	for(int i=1; i<=n; i++) 
		T.insert(i,i);
	T.print();	

	puts("Erase element 4...");
	T.erase(4);
	T.print();
	T.insert(4,4);

	puts("Split the treap at index 4...");
	pair<treap,treap> u = T.split(4);
	puts("First Part");
	u.first.print();
	puts("Second Part");
	u.second.print();

	puts("Merge the two parts...");
	T = u.first.merge(u.second);
	T.print();

	puts("Reverse the treap...");
	T.reverse();
	T.print();
	T.reverse();

	puts("Split at index 5 and reverse the second part...");
	u = T.split(5);
	u.second.reverse();
	puts("First Part");
	u.first.print();
	puts("Second Part (reversed)");
	u.second.print();
	puts("Merge the two parts...");
	T = u.first.merge(u.second);
	T.print();
 	return 0;
}