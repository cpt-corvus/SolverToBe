
vector<int> p, q;
//extended euclide algorithm
int xgcd(int a, int b, int &x, int &y, int step, int &m) {
	if (step == 0) p.push_back(0);
	else if (step == 1) p.push_back(1);
	else p.push_back((p[step - 2] - (1ll * p[step - 1] * q[step - 2]) % m + m)%m);
	if (b == 0) {
		x = 0, y = 0;
		return a;
	}
	int x2 = 0, y2 = 0;
	q.push_back(a / b);
	int g = xgcd(b, a%b, x2, y2, step+1, m);
	x = x2;
	y = x2 - (a / b)*y2;
	return g;
}

//find modular inverse of a mod m (-1 if a doesn't have modular inverse)
int mod_inverse(int a, int m) { 
	int x = 0, y = 0;
	int g = xgcd(m, a, x, y, 0, m);
	if (g != 1)
		return -1;
	return p.back();
}