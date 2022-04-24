int n; 
vector<int> v;
vector<int> dp;
int LIS(){ //O(nlogn)
    for (int i = 0; i < n; i++)
        *lower_bound(dp.begin(), dp.end(), v[i]) = v[i];

    for (int i = 0; i <= n; i++) {
        if (dp[i] == MOD) {
            return i;
        }
    }
    return 0;
}
int LIS2() { // dp in O(n^2)
    vector<int> dp(n);
    dp.assign(n, 1);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(v[i] > v[j]){
                dp[i] = max(dp[j] + 1, dp[i]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}
// memoization
int memo[2555][2555];
int LIS3(int indx, int prev) { //O(n^2)
    if(indx == n)
        return 0;
    int &ret = memo[indx][prev];
    if(~ret) return ret;
    ret = LIS(indx + 1, prev);
    if(v[indx] > v[prev])
        return ret = max(ret, LIS(indx + 1, indx) + 1);
    return ret;
}
int main() {
    //cin >> n;
    //v.resize(n);
    // MOD = 1e9 + 7 u can use another big number instead.
    //dp.resize(n + 10, MOD);
    //memset(memo, -1, sizeof memo);
    //for(int &i : v) cin >> i;
    //cout << LIS();

}
