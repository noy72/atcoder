#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;
 
class Edge{ //頂点、前回の移動に使った辺番号、コスト
    public:
        int to, com, cost;
        Edge(int to, int com, int cost) : to(to) ,com(com) ,cost(cost) {}
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
 
map<int, vector<Edge>> g[200001];
typedef pair<int,pair<int, int>> ppi;
map<int, Node> node[200001];
 
int dijkstra(int start, int n){
    priority_queue<ppi, vector<ppi>, greater<ppi>> q;
 
    q.push(make_pair(0, make_pair(start, -1))); //前回利用した辺はないので−1
    node[start][-1].dis = 0;
 
    ppi u;
    while(not q.empty()){
        u = q.top(); q.pop();
        int cur = u.second.first;
        int pre = u.second.second;
        if(node[cur][pre].isUsed) continue;
        node[cur][pre].isUsed = 1;
 
		//cout << cur << ' ' << pre << endl;
		for(auto e : g[cur][pre]){
			int to = e.to;
			int to_com = e.com;
			if(node[to][to_com].isUsed == 0){
				if(not node[to].count(to_com) || node[to][to_com].dis > node[cur][pre].dis + e.cost){
					node[to][to_com].dis = node[cur][pre].dis + e.cost;
					q.push(make_pair(node[to][to_com].dis, make_pair(to, to_com)));
				}
			}
        }
    }
 
    int mini = INF;
    for(auto it : node[n - 1]){
        mini = min(mini, it.second.dis);
    }
    return mini;
}
 
int main(){
    int n, m;
	cin >> n >> m;

	rep(i,m){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a][c].emplace_back(Edge{b, c, 0}); //同じ会社間の移動コストは0
		g[b][c].emplace_back(Edge{a, c, 0}); //同じ会社間の移動コストは0
		g[a][c].emplace_back(Edge{a, -1, 0}); //乗り換える
		g[b][c].emplace_back(Edge{b, -1, 0});
		g[a][-1].emplace_back(Edge{a, c, 1}); //乗り換える
		g[b][-1].emplace_back(Edge{b, c, 1});
	}

    int ans = dijkstra(0,n);
    cout << (ans == INF ? -1 : ans) << endl;
}
