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
ll linearDiophantine(ll a, ll b, ll c, ll &x, ll &y, bool &found){
    ll g = extended_euclid(a, b, x, y);
    if(found = c % g == 0)
        x *= c / g, y *= c / g;
    return g;
}
int main(){
    ll x, y;
    bool is;
    cout << linearDiophantine(258, 147, 369, x, y, is) << nl;
    cout << x << " " << y << " " << is << nl;
}
