// ax == 1%m IFF a,m coprimes
// return -1 means NO answer
// handle case x may be -ve
ll modInverse(ll a,ll m) {
    ll x, y;
    ll d = extended_euclid(a, m, x, y);
    if (d != 1)
        return -1;
    return (x + m) % m;
}

//pow function that is calc a^p % m
// ax == 1%p IFF p primes
ll modInversep(ll a, ll p) {
    return pow(a, p - 2, p);
}

// ax == 1%m IFF a,m coprimes
ll modInverse(ll a, ll m) {
    return pow(a, phi(m) - 1, m);
}
//--------------------------------------------------------------------------
//mod Inverse range for prime
vector<int> modInverseInRage(int p) {
    vector<int> inv(p - 1, 1);
    for (int i = 2; i < p; ++i)
        inv[i] = (p - (p / i) * inv[p % i] % p) % p;

    return inv;
}
