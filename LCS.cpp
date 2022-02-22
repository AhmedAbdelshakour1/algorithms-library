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
