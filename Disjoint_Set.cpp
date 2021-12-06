// Disjoint Set Data Structure
// >> https://www.mathblog.dk/disjoint-set-data-structure/
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
};

int main() {
  return 0;
}
