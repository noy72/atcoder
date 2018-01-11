#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<int> g[100005];

void bfs(int n){
	int dp[N][]; //距離
	queue<int> q; //訪問した点を入れる
	rep(i,N) dis[i] = INF;

	dis[1] = 0;
	q.push(1);

	int u;
	while(!q.empty()){
		u = q.front(); q.pop();
		for(auto to : g[cur]){
		}
	}
}

int main(){
	int n;
	cin >> n;

	rep(i,n){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
}
