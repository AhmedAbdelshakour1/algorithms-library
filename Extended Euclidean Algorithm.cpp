#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nl '\n';

//time and space in O(logn)
// ax + by = gcd(a, b)
// ax + by + cz = gcd(a, b, c)
//gcd(a, b, c) = gcd(gcd(a, b), c)
ll extended_euclid(ll a,ll b,ll &x, ll&y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll g = extended_euclid(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}
void solve() {
    ll a, b, x, y; cin >> a >> b;
    cout << "gcd is : " << extended_euclid(a, b, x, y) << "\nvalue of x is : " << x << "\nvalue of y is : " << y << nl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
