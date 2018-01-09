#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

#define int long long

vector<pair<int,int>> g[100005];

int bfs(int k){
	vector<int> dis(k,INF);
	dis[1] = 0;

	deque<int> q;
	q.push_front(1);

	while(not q.empty()){
		int u = q.front(); q.pop_front();
		for(auto e : g[u]){
			if(dis[e.first] > dis[u] + e.second){
				dis[e.first] = dis[u] + e.second;
				if(e.second == 1){
					q.emplace_back(e.first);
				}else{
					q.emplace_front(e.first);
				}
			}
		}
	}
	return dis[0] + 1;
}

signed main(){
	int k;
	cin >> k;


	rep(i,k){
		g[i].emplace_back((i + 1) % k, 1);

		int t = 10;
		while(t <= 100000){
			g[i].emplace_back((t * i) % k, 0);
			t *= 10;
		}
	}

	cout << bfs(k) << endl;
}
