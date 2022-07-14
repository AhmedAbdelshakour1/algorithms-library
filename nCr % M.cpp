ll ncr(ll n, ll r) { // O(R logN) 
    if (n - r < r) r = n - r;
    ll p = 1, k = 1;
    if (r == 0) return 1;
    while (r) {
        p *= n;
        k *= r;
        ll div = __gcd(p, k);
        p /= div;
        k /= div;
        n--;
        r--;
    }
    return p;
}
//-----------------------------------------------------------------------------
//O(N) for precomputing and O(1) for every query.

const int N = 2e5 + 10;
ll fact[N];
int MOD = 1e9 + 7;

ll binPow2(ll a, ll p) {
    ll result = 1;
    while (p > 0) {
        if (p & 1) result = ((result % MOD) *( a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        p >>= 1;
    }
    return result;
}
void precalc() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

ll inv(ll x){
    return binPow2(x, MOD - 2);
}

ll ncr(ll n, ll r){
    ll dem = (fact[n - r] * fact[r]) % MOD;
    return (fact[n] * inv(dem)) % MOD;
}
