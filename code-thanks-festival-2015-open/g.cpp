#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

#define int long long
const int INF = (1LL << 60);

//https://beta.atcoder.jp/contests/code-thanks-festival-2015-open/tasks/code_thanks_festival_2015_g

class Edge{ //頂点、コスト、辺に与えられた識別番
	public:
		int to, cost, color;
		Edge(int to, int cost, int color) : to(to) ,cost(cost) ,color(color) {}
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

class Dijkstra{
	private:
		vector<vector<Edge>> g;
		vector<map<int, Node>> node; // node[i][j] := 頂点iに色jで来たとき
		int n;
	public:
		Dijkstra(int n){
			this->n = n;
			g = vector<vector<Edge>>(n);
			node = vector<map<int, Node>>(n);
		}
		int solve(int start, int goal, int spre){	//spre スタート時の状態。何もなければ-1
			typedef pair<int,pair<int, int>> ppi;
			priority_queue<ppi, vector<ppi>, greater<ppi>> q;

			q.push(make_pair(0, make_pair(start, spre)));
			node[start][spre].dis = 0;

			ppi u;
			while(not q.empty()){
				u = q.top(); q.pop();
				int cur = u.second.first;
				int pre = u.second.second;
				node[cur][pre].isUsed = 1;
				if(cur == goal) break;//これがないとTLE
				//breakしないとgoalに到着したコストを各色について求めてしまう
				//最後の色の指定がないので、どんな色でもいいから最短経路が決まったらbreakする。

				for(const auto& e : g[cur]){
					int to = e.to;
					int color = e.color;
					int cost = e.cost + abs(pre - color) + u.first;

					auto& next = node[to][color];
					if(next.isUsed == 0){
						if(not node[to].count(color) || next.dis > cost){
							next.dis = cost;
							q.push(make_pair(next.dis, make_pair(to, color)));
						}
					}
				}
			}

			int mini = INF;
			for(auto it : node[goal]){
				mini = min(mini, it.second.dis);
			}
			return mini;
		}
		void addEdge(int from, int to, int cost, int color){
			g[from].emplace_back(Edge{to, cost, color});
			g[to].emplace_back(Edge{from, cost, color});
		}
};

signed main(){
	int n, m;
	scanf("%lld%lld", &n, &m);

	Dijkstra d(n);
	rep(i,m){
		int a, b, c, t;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &t);
		a--; b--;
		d.addEdge(a,b,t,c);
	}
	cout << d.solve(0, n - 1, 1) << endl;
}
