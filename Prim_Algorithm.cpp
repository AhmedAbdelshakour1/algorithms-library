#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define nline '\n';
#define len(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(),(x).rend()
#define e 2.718281828459045

const int MOD = 1e9 + 7;
const ll OO = 1e8;
const double PI = 2 * asin(1);
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {-0, 0, -1, 1};
ll pow(ll b, ll p) {   // O(log(p) base 2)
    if (p == 0 && b == 0) return 0;
    if (p == 0) return 1;
    ll sq = pow(b, p / 2);
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
struct edge{
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w){}
    bool operator < (const edge & e) const {
		return w > e.w;	// STL priority_queue need it > , or modify data -ve, or use paprmeter less
	}
};

//Adjacency matrix
//return cost and list of edges in MST
pair<int, vector<edge>> primMST1(vector<vector<int>> adjMax){  // O(n ^ 2)
    int curNode = 0, n = len(adjMax), minJoinNode;
    int minDis, mstCost = 0;

    vector<int> vis(n, 0), prev(n);
    vector<int> dist(n, OO); // 1) dist[i]: Minimum value to connect i to current built tree
    vector<edge> edges;			 // Save MST edges

    for (int k = 0; k < n - 1; ++k) {
        vis[curNode] = 1, minDis = OO, minJoinNode = -1;
        for (int i = 0; i < n; ++i) {
            if(!vis[i])
            {
                if(adjMax[curNode][i] < dist[i])	//2) Update if i can reach tree with a new Minimum value
                    dist[i] = adjMax[curNode][i], prev[i] = curNode;

                if (dist[i] < minDis) minDis = dist[i], minJoinNode = i;	//3) Select minimum EDGE value
            }
        }
        if(minJoinNode == -1)	break;	// 4) check if graph is disconnected
        // 5) update edges and cost of mst
        edges.push_back( edge(prev[minJoinNode], minJoinNode, adjMax[prev[minJoinNode]][minJoinNode] ) );
        curNode = minJoinNode, mstCost += dist[curNode];
    }

    if( len(edges) != n-1)	return make_pair(OO, vector<edge>() );
    return make_pair(mstCost, edges);
}


//---------------------------------------------------------------------------------------------------------------------------------------


// Adjacency List
pair<int, vector<edge> > primMST2(vector< vector< edge > > adjList) { // O(E logV)

    int n = len(adjList), mstCost = 0;
    vector<int> vis(n, 0);
    vector<edge> edges;			 // Save MST edges

    priority_queue<edge> q;		// 1) priority_queue to sort edges
    q.push( edge(-1, 0, 0) );

    while( !q.empty() ) {
        edge ed = q.top();
        q.pop();
        if( vis[ed.to] ) continue;
        vis[ed.to] = 1;
        mstCost += ed.w;
        if(ed.to)	edges.push_back( ed );	// 2) remove min element from priority queue & update cost/list

        for (auto curr : adjList[ed.to]) { // 3) Iterate on adjacent edges & add new edges, using e.to as src
            if( !vis[ curr.to] )				// 4) If added will cause cycle
                q.push( curr );
        }
    }

    if( len(edges) != n-1)	return make_pair(-OO, vector<edge>() );
    return make_pair(mstCost, edges);
}








int main(){
  return 0;
}

