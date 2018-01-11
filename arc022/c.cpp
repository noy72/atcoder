#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

const int MAX_V = 100000;
const int INF = 1e8;

class Edge{
    public:
        int to, dis;
        Edge(int to, int dis): to(to), dis(dis)  {}
};

vector<Edge> g[MAX_V];
int dis[MAX_V];

void bfs(int s, int n){
    queue<int> q;

    rep(i,n) dis[i] = INF;
    dis[s] = 0;
    q.push(s);

    int u;
    while(not q.empty()){
        u = q.front(); q.pop();
        rep(i,g[u].size()){
            Edge e = g[u][i];
            if(dis[e.to] == INF){
                dis[e.to] = dis[u] + e.dis;
                q.push(e.to);
            }
        }
    }
    //rep(i,n) show(dis[i]) cout << endl;
}

void solve(int n){
    int maxi = 0, tmt = 0;
    int tgt = 0; //ある点sから最も遠い点

    bfs(0, n);
    rep(i,n){
        if(dis[i] == INF) continue;
        if(maxi < dis[i]){
            maxi  = dis[i];
            tgt = i;
        }
    }

    bfs(tgt, n);
    maxi = 0; //tgtから最も遠い接点の距離maxi
    rep(i,n){
        if(dis[i] == INF) continue;
        if(maxi < dis[i]){
            maxi = dis[i];
            tmt = i;
        }
    }

    cout << tgt + 1 << ' ' << tmt + 1 << endl;
}

int main(){
    int n;
    cin >> n;
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].emplace_back(Edge{b,1});
        g[b].emplace_back(Edge{a,1});
    }
    solve(n);
}
