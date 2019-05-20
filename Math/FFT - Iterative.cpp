
// FFT
// [Fast Fourier Transform]
// (fast iterative implementation)
//.................................
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
 
int n;
vector<ll> p1, p2;
 
 /**
 * Fast Fourier Transform (FFT)
 * Transform the polynomials passed by refrence v to point-value form by using FFT algorithm to perfom Discreate Fourier Transform (DFT)
 */
void fft(vector<complex<double> > & p, bool inverse) {
	int n = p.size();
	for (int i = 1, j = 0; i < n - 1; i++) {
		for (int bit = n >> 1; bit > (j ^= bit); bit >>= 1);
		if (i < j) swap(p[i], p[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = (inverse ? -1 : 1) * 2 * PI / len;
		complex<double> Wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			complex<double> W(1);
			for (int j = 0; j < (len >> 1); j++) {
				complex <double> u = p[i + j], v = p[i + j + (len >> 1)] * W;
				p[i + j] = u + v;
				p[i + j + (len >> 1)] = u - v;
				W *= Wlen;
			}
		}
	}
	if (inverse)
		for (int i = 0; i < n; i++)
			p[i] /= n;
}
 
 /**
 * Multiply two polynomials a and b
 */
vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
	vector<complex<double> > fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < a.size() + b.size())
		n *= 2;
	fa.resize(n);
	fb.resize(n);
	
	fft(fa, 0), fft(fb, 0);
 
	for (int i = 0; i < n; i++)
		fa[i] *= fb[i];
 
	fft(fa, 1);
 
	vector<ll> res(n);
	for (int i = 0; i < n; i++)
		res[i] = round(fa[i].real());
 
	return res;
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	scanf("%d", &n);
	p1.clear(), p1.resize(n+1);
	p2.clear(), p2.resize(n+1);
	for (int i = 0; i <= n; i++)
		scanf("%lld", &p1[i]);
	for (int i = 0; i <= n; i++)
		scanf("%lld", &p2[i]);
	vector<ll> res = multiply(p1, p2); //multiplication of two polynomials using FFT
	for (int i = 0; i < 2*n+1; i++)
		printf("%s%lld", (i ? " " : ""), res[i]);
	puts("");
	return 0;
} 