#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const long long INF = (1LL << 60);
using namespace std;

class Edge{
    public:
        long long to, cost;
        Edge(long long to, long long cost) : to(to) ,cost(cost) {}
};

class Node{
    public:
        long long dis;
        bool isUsed;
        Node(){
            this->dis = INF;
            this->isUsed = 0;
        }
        bool operator < ( const Node &right ) const {
            return dis < right.dis;
        }
};

typedef vector<vector<Edge>> AdjList;

long long dijkstra(AdjList g, long long start, long long n, long long r, long long t){
    vector<Node> node(n);
    priority_queue<long long, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;

    q.push(make_pair(0, start));
    node[start].dis = 0;

    pair<long long, long long> u;
    while(not q.empty()){
        u = q.top(); q.pop();
        long long current = u.second;
        node[current].isUsed = 1;

        rep(i,g[current].size()){
            long long next = g[current][i].to;
            if(node[next].isUsed == 0){
                if(node[next].dis > node[current].dis + g[current][i].cost){
                    node[next].dis = node[current].dis + g[current][i].cost;
                    q.push(make_pair(node[next].dis, next));
                }
            }
        }
    }
    sort(all(node));
    rep(i,n) node[i].dis *= t;

	long long ans = 0;
	auto it = node.begin();
	advance(it,1); //ゴール地点を省く

	for(; it != node.end(); it++){
		Node tmp;
		tmp.dis = it->dis / t * r;

		int dif = distance(upper_bound(all(node), tmp), node.end());
		ans += dif;
		if(n - dif <= distance(node.begin(), it)) ans--;
	}
	return ans;

    for(auto it = ++node.begin(); it != node.end(); it++){
        Node tmp;
        tmp.dis = it->dis / t * r;
        tmp.isUsed = true;
        auto next = it;
        next++;
        ans += node.end() - upper_bound(next, node.end(), tmp);
    }
    return ans;
}

int main(){
    long long n, m, r, t;
    cin >> n >> m >> r >> t;

    AdjList g(n);
    rep(i,m){
        long long a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(Edge{b,c});
        g[b].emplace_back(Edge{a,c});
    }

    long long ans = 0;
    rep(i,n){
        ans += dijkstra(g,i,n,r,t);
    }
    cout << ans << endl;
}
