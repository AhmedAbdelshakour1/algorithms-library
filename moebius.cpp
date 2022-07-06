int moebius(int n){
    int moeb = 1;
    for (int i = 2; i * i <= n; ++i) {
        if(n % i == 0){
            if(n % (i * i) == 0) return 0;
            n /= i, moeb *= -1;
        }
    }
    if(n) moeb *= -1;
    return moeb;
}

void moebius_in_range() {
    int MAX = 1e6;
    vector<int> moebius(MAX, 1), prime(MAX, 1);
    for (ll i = 2; i <= MAX; ++i)
        if (prime[i]) {
            moebius[i] = -1;
            for (ll j = i * 2; j <= MAX; j += i)
                prime[j] = 0, moebius[j] = j % (i * i) == 0 ? 0 : -moebius[j];
        }
    for (int i = 1; i <= MAX; ++i) {
        cout << moebius[i] << " ";
    }
}
