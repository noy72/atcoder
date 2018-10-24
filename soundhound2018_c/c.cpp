#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

const int MAX_V = 10005;

class Edge{
	public:
		int to, cap, rev;
		Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
};

class Flow{
	private:
		vector<Edge> G[MAX_V];
		bool used[MAX_V];
		int level[MAX_V]; //sからの距離
		int iter[MAX_V]; //どこまで調べ終わったか
		int dfs(int v, int t, int f){
			if(v == t) return f;
			used[v] = true;
			rep(i,G[v].size()){
				Edge &e = G[v][i];
				if(not used[e.to] && e.cap > 0){
					int d = dfs(e.to, t, min(f, e.cap));
					if(d > 0){
						e.cap -= d;
						G[e.to][e.rev].cap += d;
						return d;
					}
				}
			}
			return 0;
		}
		int dfs_(int v, int t, int f){
			if(v == t) return f;
			for(int &i = iter[v]; i < G[v].size(); i++){
				Edge &e = G[v][i];
				if(e.cap > 0 && level[v] < level[e.to]){
					int d = dfs_(e.to, t, min(f, e.cap));
					if(d > 0){
						e.cap -= d;
						G[e.to][e.rev].cap += d;
						return d;
					}
				}
			}
			return 0;
		}
		void bfs(int s){
			memset(level, -1, sizeof(level));
			queue<int> que;
			level[s] = 0;
			que.push(s);
			while(not que.empty()){
				int v = que.front(); que.pop();
				rep(i,G[v].size()){
					Edge &e = G[v][i];
					if(e.cap > 0 && level[e.to] < 0){
						level[e.to] = level[v] + 1;
						que.push(e.to);
					}
				}
			}
		}
	public:
		void addEdge(int from, int to, int cap){
			G[from].push_back(Edge(to, cap, static_cast<int>(G[to].size())));
			G[to].push_back(Edge(from, 0, static_cast<int>(G[from].size() - 1)));
		}
		int fordFulkerson(int s, int t){
			int flow = 0;
			while(true){
				memset(used, 0, sizeof(used));
				int f = dfs(s, t, INF);
				if(f == 0) return flow;
				flow += f;
			}
		}
		int dinic(int s, int t){
			int flow = 0;
			while(true){
				bfs(s);
				if(level[t] < 0) return flow;
				memset(iter, 0, sizeof(iter));
				int f;
				while( (f = dfs_(s, t, INF)) > 0){
					flow += f;
				}
			}
		}
};

const int dy[16] = { 0,-1, 0, 1, 1,-1, 1,-1, 0,-2, 0, 2};
const int dx[16] = { 1, 0,-1, 0, 1, 1,-1,-1, 2, 0,-2, 0};

int main(){
	int r, c;
	cin >> r >> c;

	vector<vector<char>> v(r, vector<char>(c));
	int n = 0;
	rep(i,r){
		rep(j,c){
			cin >> v[i][j];
			if(v[i][j] == '.') n++;
		}
	}

	int s = r * c;
	int t = s + 1;
	Flow flow;
	rep(i,r){
		rep(j,c){
			if(v[i][j] == '.' and (i + j) % 2 == 0){
				flow.addEdge(s, i * c + j, 1);

				rep(k,4){
					int ny = i + dy[k];
					int nx = j + dx[k];
					if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
					if(v[ny][nx] != '.') continue;
					flow.addEdge(i * c + j, ny * c + nx, 1);
				}
			}
			if((i + j) % 2 == 1){
				flow.addEdge(i * c + j, t, 1);
			}
		}
	}

	cout << n - flow.dinic(s,t) << endl;
}
