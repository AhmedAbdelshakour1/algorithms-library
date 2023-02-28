// Memoization
string s, t;
int memo[105][105];
int LCS(int i, int j){
    if(i == len(s) || j == len(t))
        return 0;
    int &ret = memo[i][j];
    if(~ret) return ret;
    if(s[i] == t[j])
        return ret = LCS(i + 1, j + 1) + 1;
    return ret = max(LCS(i, j + 1), LCS(i + 1, j));
}

// Tabulation
int dp[1001][1001];
int LCS(string s, string t) {
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= t.size(); ++j) {
            if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ans = dp[s.size()][t.size()];
    memset(dp, 0, sizeof dp);
    return ans;
}
