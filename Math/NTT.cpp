
// FFT (NTT)
// [Fast Fourier Transform] (Number Theoretic Transform)
//................................
// ~/SolverToBe/Developers/Corvus
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
#include <assert.h>
#include <complex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 20005, M = 505;
const ll MOD = 1e9 + 7;
const double eps = 1e-9;
const double PI = acos(-1);

int tc, n;
vector<int> p1, p2;

//if the following prime is not enough, we need to find another prime and its primitive root
const int mod = 998244353; //mod = 1 + c * 2^k
const int root = 3; //primitive root of mod

int fast_pow(int b, int n) {
	if (n == 1)
		return b % mod;
	if (n == 0)
		return 1;
	if (n & 1) return (1ll * b * fast_pow(b, n - 1)) % mod;
	int r = fast_pow(b, n / 2);
	return (1ll * r * r) % mod;
}

 /**
 * Fast Fourier Transform (FFT)
 * Number Theoretic Transform (NTT)
 * Transform the polynomials passed by refrence p to point-value form by using FFT algorithm to perfom Discreate Fourier Transform (DFT)
 * Implementation of FFT to calculate multiplication of two polynomials module prime number
 * It slower than the complex numbers based implementation of FFT but it has some advantages (1) lower memory usage, (2) no rounding errors
 */
 // 
void fft(vector<int> & p, bool inverse) {
	int n = p.size();

	//mod = 1 + c * 2^k
	//h = c (for given n where n = 2^k)
	int h = fast_pow(root, (mod - 1) / n);
	if (inverse) h = fast_pow(h, mod - 2);

	for (int i = 1, j = 0; i < n - 1; i++) {
		for (int bit = n >> 1; bit > (j ^= bit); bit >>= 1);
		if (i < j) swap(p[i], p[j]);
	}

	for (int len = 1; len < n; len <<= 1) {
		int wlen = fast_pow(h, n / (len << 1));  
		int w = 1;
		for (int i = 0; i < len; i++) {
			for (int j = i; j < n; j += (len << 1)) {
				int u = p[j], v = (1ll * p[j + len] * w) % mod;
				p[j] = u + v;
				if (p[j] >= mod) p[j] -= mod;
				p[j + len] = u - v;
				if (p[j + len] < 0) p[j + len] += mod;
			}
			w = (1ll * w * wlen) % mod;
		}
	}
	if (inverse) {
		int n_inverse = fast_pow(n, mod - 2);
		for (int i = 0; i < p.size(); i++)
			p[i] = (1ll * p[i] * n_inverse) % mod;
	}
}

vector<int> multiply(vector<int> &a, vector<int> &b) {
	int n = 1;
	while (n < a.size() + b.size())
		n <<= 1;
	a.resize(n), b.resize(n);
	fft(a, 0), fft(b, 0);
	for (int i = 0; i < n; i++)
		a[i] = (1ll * a[i] * b[i]) % mod;
	fft(a, 1);
	return a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		p1.clear(), p1.resize(n + 1);
		p2.clear(), p2.resize(n + 1);
		for (int i = 0; i <= n; i++)
			scanf("%d", &p1[i]);
		for (int i = 0; i <= n; i++)
			scanf("%d", &p2[i]);
		vector<int> res = multiply(p1, p2);
		for (int i = 0; i < 2 * n + 1; i++)
			printf("%s%d", (i ? " " : ""), res[i]);
		puts("");
	}
	return 0;
}