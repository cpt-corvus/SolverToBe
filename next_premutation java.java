public static boolean next_permutation(int[] p, int len) {
	int a = len - 2;
	while (a >= 0 && p[a] >= p[a + 1]) {
		a--;
	}

	if (a == -1) {
		return false;
	}

	int b = len - 1;
	while (p[b] <= p[a]) {
		b--;
	}

	p[a] += p[b];
	p[b] = p[a] - p[b];
	p[a] -= p[b];

	for (int i = a + 1, j = len - 1; i < j; i++, j--) {
		p[i] += p[j];
		p[j] = p[i] - p[j];
		p[i] -= p[j];
	}

	return true;
}