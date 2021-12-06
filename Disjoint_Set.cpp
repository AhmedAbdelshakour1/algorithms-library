// Disjoint Set Data Structure
// >> https://www.mathblog.dk/disjoint-set-data-structure/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nline '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {-0, 0, -1, 1};
const double PI = 2 * asin(1);
const int MOD = 1e9 + 7;
const ll OO = 1e8;


ll pw(ll b, ll p) {   // O(log(p) base 2)
    if (p == 0 && b == 0) return 0;
    if (p == 0) return 1;
    ll sq = pw(b, p / 2);
    sq = sq * sq;
    if (p & 1) sq = sq * b;
    return sq;
}

void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//.....................................................................................//
struct unionFind{
    vector<int> rank, parent;
    int forests;

    unionFind(int n) {
        rank = vector<int>(n), parent = vector<int>(n);
        forests = n;        //Number of current forests
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    //find parent and make path compression in the same time
    int findSet(int x){
        if(x == parent[x]) return x;
        return parent[x] = findSet(parent[x]);
    }
    void link(int x, int y) {
        if(rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
    }
    bool unionSets(int x, int y) {
        x = findSet(x), y = findSet(y);
        if(x != y){
            link(x, y);
            forests--;  //after merging two forests
        }
        return x != y;
    }
    //Other utilities
    int same_set(int x, int y){
        return findSet(x) == findSet(y);
    }
    vector<vector<int>> connected_components(){
        vector<vector<int>> list(len(parent));
        for (int i = 0; i < len(parent); ++i) {
            list[findSet(i)].push_back(i);
        }
        return list;
    }
};


int main() {
    return 0;
}

