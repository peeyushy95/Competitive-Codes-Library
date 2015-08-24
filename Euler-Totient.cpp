
method :1

	int phi (int n) {
		int result = n;
		for (int i=2; i*i<=n; ++i)
			if (n % i == 0) {
				while (n % i == 0)
					n /= i;
				result -= result / i;
			}
		if (n > 1)
			result -= result / n;
		return result;
	}

...............................................................................
method :2

    void phi1() {
	phi[0]  = 0;
	for (int i=1; i<maxn; ++i) phi[i] = i - 1;
	for (int i=1; i<maxn; ++i)
		for (int j=i+i; j<maxn; j+=i)
		         phi[j] -= phi[i];
    }
