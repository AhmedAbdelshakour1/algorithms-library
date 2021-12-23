// Note that iterative faster than recursive

// Recursive
ll pw(ll a, ll p) {   // O(log(p) base 2)
    if (p == 0 && a == 0) return 0;
    if (p == 0) return 1;
    ll sq = pw(a, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * a;
    return sq;
}


// Iterative
ll pw(ll a, ll p){
    if(a == 0 && p == 0) return 0;
    ll result = 1;
    while(p > 0){
        if(p & 1) result *= a;
        a *= a;
        p >>= 1;
    }
    return result;
}
