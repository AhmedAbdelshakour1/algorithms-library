vector<ll> generate_divisors(ll n){ // O(sqrt(n)
    vector<ll> v;
    ll i;
    for(i = 2; i * i < n; i++){
        if(n % i == 0) v.push_back(i), v.push_back(n / i);
    }
    if(i * i == n)
        v.push_back(i);
    return v; // Not sorted
}

//Prime factorization
vector<ll> factorization(ll n){ // O(sqrt(n) >> max n is 1e12
    //if n = 0 or n = 1?
    vector<ll> primes;
    ll i;
    for(i = 2; i * i <= n; i += 1 + (i & 1)){
        while(n % i == 0)
            primes.push_back(i), n /= i; // Get every prime inside n
    }
    if(n > 1)
        primes.push_back(n);
    return primes;
}

//return sum of divisors of i in range n
int sum_of_divisors1(int n){ // forward thinking
    int s = 0;
    for (int i = 1; i <= n; ++i)
        s += generate_divisors(i).size();
    return s;
}
int sum_of_divisors2(int n){ // backward thinking >> suitable for range 2e6
    vector<int> fac(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            fac[j]++;
    int s = 0;
    for (int i = 1; i <= n; ++i)
        s += fac[i];
    return s;
}
