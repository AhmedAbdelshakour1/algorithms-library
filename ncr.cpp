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
