#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

#define int long long

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

const int INF = (1LL << 60);

struct Edge{
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

struct Node{
	int dis;
	bool used;
	Node() : dis(INF), used(false) { }
	Node(int d, bool f) : dis(d), used(f) { }
};

typedef vector<vector<Edge>> graph;

vector<Node> dijkstra(graph g, int s, int n){
	vector<Node> node(n);
	priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push(make_pair(0, s));
	node[s] = Node{0, true};

	while(not q.empty()){
		int dis, pos;
		tie(dis, pos) = q.top(); q.pop();
		node[pos].used = true;

		for(auto e : g[pos]){
			if(node[e.to].used == true) continue;
			if(node[e.to].dis > dis + e.cost){
				node[e.to].dis = dis + e.cost;
				q.emplace(node[e.to].dis, e.to);
			}
		}
	}
	return node;
}

void addEdge(graph& g, int from, int to, int cost){
	g[from].emplace_back(Edge{to, cost});
	g[to].emplace_back(Edge{from, cost});
}

signed main(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--; t--;

	graph ga(n), gb(n);
	rep(i,m){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--;
		addEdge(ga, a, b, c);
		addEdge(gb, a, b, d);
	}

	vector<Node> anode = dijkstra(ga, s, n);
	vector<Node> bnode = dijkstra(gb, t, n);

	priority_queue<pair<int, int>> q;
	rep(i,n){
		int sum = anode[i].dis + bnode[i].dis;
		//cout << anode[i].dis << ' ' << bnode[i].dis << endl;
		assert(sum <= static_cast<long long>(1e15));
		q.emplace(1e15 - sum, i);
	}

	rep(i,n){
		while(i > q.top().second) q.pop();
		cout << q.top().first << endl;
	}
}
