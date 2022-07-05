// brute force
int phi(int n) {
    int ret = 0;
    for (int i = 1; i < n; i++)
        if (__gcd(i, n) == 1)
            ret++;
    return ret;
}

// Factorize and use fact p^(k-1)*(p-1)
int phi(int n) {
    int p_power_k, relative_primes = 1;
    for (int i = 2; i * i <= n; i += 1 + (i & 1)) {
        if (!(n % i)) {
            p_power_k = 1;
            while (!(n % i))
                p_power_k *= i, n /= i;
            relative_primes *= (p_power_k / i) * (i - 1);
        }
    }
    if (n != 1)
        relative_primes *= (n - 1);
    return relative_primes;
}


void phi_in_range() {
    int MAX = 10000001;
    vector<int> primes(MAX, 1), phi(MAX, 1);
    for (int i = 2; i <= MAX; ++i) {
        if (primes[i]) {
            phi[i] = i - 1;// ph(prime)=p-1
            for (int j = i * 2; j <= MAX; j += i) {
                primes[j] = 0;
                int n = j, pow = 1;
                while (!(n % i))
                    pow *= i, n /= i;
                phi[j] = (pow / i) * (i - 1);
            }
        }
    }
    for (int i = 0; i <= MAX; ++i) {
        cout << phi[i] << nl;
    }
}

// phi(N!) = (N is prime ? N - 1 : N) * phi((N - 1)!)
ll phi_factn(int n) {
    ll ret = 1;
    for (int i = 2; i <= n; ++i)
        ret = ret * (isprime(i) ? i - 1 : i);
    return ret;
}
