// https://github.com/AhmedAbdelshakour1/competitive-programming/blob/main/SPOJ/Prime%20Generator.cpp

vector<char> segmentedSieve(int L, int R){
    int sq = sqrt(R);
    vector<char> vis(sq + 1, true);
    vector<ll> isPrime;
    for (ll i = 2; i <= sq; ++i) {
        if(vis[i]){
            isPrime.push_back(i);
            for (ll j = i * i; j <= sq; j += i) vis[j] = 0;
        }
    }
    vector<char> primes(R - L + 1, true);
    for(auto p : isPrime){
        for (ll i = max(p * p, (L + p - 1) / p * p); i <= R; i += p) primes[i - L] = 0;
    }
    if(L == 1) primes[0] = 0;
    return primes;
}
