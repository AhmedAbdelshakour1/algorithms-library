#include <bits/stdc++.h>
using namespace std;

struct unionFind{
    vector<int> rank, parent;
    int forests;

    unionFind(int n) {
        rank.resize(n,0);
        parent.resize(n);
        forests = n;        //Number of current forests
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    //find parent and make path compression in the same time
    int findSet(int x){
        if(parent[x] == x) return x;
        return parent[x] = findSet(parent[x]);
    }
    void link(int x, int y) {
        if(rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
    }
    bool unionSets(int x, int y) {
       int parentX = findSet(x), parentY = findSet(y);
        if(parentX != parentY){
            link(parentX,parentY);
            forests--;  //after merging two forests
        }
        return parentX != parentY;
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

struct edge{
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w){}
    bool operator < (const edge & ed) const {
        return w > ed.w;	// STL priority_queue need it > , or modify data -ve, or use paprmeter less
    }
};

pair<int, vector<edge>> kruskalMST(vector<edge> edgeList, int n){  // O(E logV);
    unionFind uf(n);
    vector<edge> edges;
    int mstCost = 0;
    priority_queue<edge> q;
    for (int i = 0; i < len(edgeList); ++i)
        q.push(edgeList[i]);

    while(!q.empty()){
        edge ed = q.top();
        q.pop();
        if(uf.unionSets(ed.from, ed.to)){  // if added, then part of tree
            mstCost += ed.w;
            edges.push_back(ed);
        }
    }
    if(len(edges) != n - 1) return make_pair(OO, vector<edge>());
    return make_pair(mstCost, edges);

}
int main() {
    return 0;
}
