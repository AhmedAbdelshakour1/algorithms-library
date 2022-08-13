#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
const int N = 1e5 + 1;
int n, m;
vector<int> adj[N];
int vis[N], c[N], color[N];


//.........................................(^_^)............................................//
// Bipartite
// Problem link Bipartite graph: https://cses.fi/problemset/task/1668
// Bipartite graph using bfs and using dfs https://github.com/AhmedAbdelshakour1/competitive-programming/blob/main/CSES/Building%20Teams.cpp

void bfs(int s) {
    queue<int> q;
    color[s] = 1; q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!color[v]) {
                color[v] = color[u] % 2 + 1;
                q.push(v);
            }
            else if (color[v] == color[u]) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    }
}
//another way

bool isBipartite(int u){
    for(auto v : adj[u]){
        if(color[v] == color[u])
            return false;
        else if(color[v] == 0){
            color[v] = -color[u];
            if(!isBipartite(v)){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(){
    for(int i = 1; i <= n; i++){
        if(color[i] == 0) {
            color[i] = -1;
            if(!isBipartite(i))
                return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!color[i])
            bfs(i);
    for (int i = 1; i <= n; i++) 
        cout << color[i] << " ";
    cout << "\n";
}
//.........................................(^_^)............................................//

int connectedComponenetsCnt(){ // O(E+V)
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
//.........................................(^_^)............................................//
bool isCycle(int node, int parent){
    vis[node] = 1;
    for(int child : adj[node]){
        if(!vis[child]){
            if(isCycle(child, node))
                return true;
        }
        else if(child != parent)
            return true;
    }
    return false;
}


int main() {
   
}
