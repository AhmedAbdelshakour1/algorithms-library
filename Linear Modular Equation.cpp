ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    if (a < 0) {
        ll r = extended_euclid(-a, b, x, y);
        x *= -1;
        return r;
    }
    if (b < 0) {
        ll r = extended_euclid(a, -b, x, y);
        y *= -1;
        return r;
    }
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll g = extended_euclid(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}


// solves the equation ax = b (mod n)
vector<ll> modularEquation(ll a, ll b, ll n) {
    vector<ll> sols;
    ll x, y, g;
    g = extended_euclid(a, n, x, y);
    if (b % g != 0)
        return sols; // no solutions
    x = ((x * b / g) % n + n) % n; // from LDE,+ve mod
    for (int i = 0; i < g; ++i)    // Bézout's identity
        sols.push_back((x + i * n / g) % n);
    sort(sols.begin(), sols.end());
    return sols;
}
