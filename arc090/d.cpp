#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define int long long
const int INF = (1LL << 60);
using namespace std;


class Edge{
	public:
		int to, cost;
		Edge(int to, int cost) : to(to) ,cost(cost) {}
};

class Node{
	public:
		int dis;
		bool isUsed;
		Node(){
			this->dis = INF;
			this->isUsed = 0;
		}
};

typedef vector<vector<Edge>> AdjList;

void dijkstra_max(AdjList& g, int start, int n, vector<Node>& node){
	priority_queue<pair<int, int>> q;

	q.push(make_pair(0, start));
	node[start].dis = 0;

	pair<int, int> u;
	while(not q.empty()){
		u = q.top(); q.pop();
		int current = u.second;
		node[current].isUsed = 1;

		rep(i,g[current].size()){
			int next = g[current][i].to;
			if(node[next].isUsed == 0){
				if(node[next].dis > node[current].dis + g[current][i].cost){
					node[next].dis = node[current].dis + g[current][i].cost;
					q.push(make_pair(node[next].dis, next));
				}
			}
		}
	}
}
bool f;

void dijkstra_min(AdjList& g, int start, int n, vector<Node>& node){
	priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push(make_pair(0, start));
	node[start].dis = 0;
		node[start].isUsed = 1;

	pair<int, int> u;
	while(not q.empty()){
		u = q.top(); q.pop();
		int current = u.second;

		rep(i,g[current].size()){
			int next = g[current][i].to;
			if(node[next].isUsed == 0){
				if(node[next].dis > node[current].dis + g[current][i].cost){
					node[next].isUsed = 1;
					node[next].dis = node[current].dis + g[current][i].cost;
					q.push(make_pair(node[next].dis, next));
				}
			}else{
				if(node[next].dis != node[current].dis + g[current][i].cost){
					f = false;
				}
			}
		}
	}
}


const int MAX_V = 100005;

vector<int> g[MAX_V]; //グラフ
vector<int> tp; //トポロジカルソートの結果

void bfs(int s, int indeg[MAX_V], bool used[MAX_V]){
	queue<int> q;

	q.push(s);
	used[s] = true;

	while(not q.empty()){
		int u = q.front(); q.pop();
		tp.emplace_back(u);
		rep(i,g[u].size()){
			int v = g[u][i];
			indeg[v]--;
			if(indeg[v] == 0 && not used[v]){
				used[v] = true;
				q.push(v);
			}
		}
	}
}

//グラフに閉路がある場合、0を返す
bool topologicalSort(int v){
	int indeg[MAX_V]; //入次数
	bool used[MAX_V];
	memset(indeg, 0, sizeof(indeg));
	memset(used, 0, sizeof(used));

	rep(i,v) rep(j,g[i].size()) indeg[ g[i][j] ]++;
	rep(i,v) if(indeg[i] == 0 && not used[i]) bfs(i, indeg, used);

	if(tp.size() == v) return true;
	else return false;
}

signed main(){
	int n, m;
	cin >> n >> m;

	AdjList ag(n);
	rep(i,m){
		int l, r, c;
		cin >> l >> r >> c;
		l--; r--;
		ag[l].emplace_back(r,c);
		g[l].emplace_back(r);
	}
	if(not topologicalSort(n)){
		cout << "No" << endl;
		return 0;
	}

	f = true;
	vector<Node> maxi(n), mini(n);
	rep(i,n){
		if(maxi[tp[i]].isUsed) continue;
		dijkstra_max(ag, tp[i], n, maxi);
		dijkstra_min(ag, tp[i], n, mini);
	}
	rep(i,n){
		if(maxi[i].dis != mini[i].dis or maxi[i].dis > 1e9 or not f){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
