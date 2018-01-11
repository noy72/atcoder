#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
using namespace std;

const int INF = 100000000;

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
            this->dis = -1;
            this->isUsed = 0;
        }
};

typedef vector<vector<Edge>> AdjList;

void dijkstra(AdjList g, int start, int n){
    vector<Node> node(n);
    priority_queue<pair<int, int>> q;

    q.push(make_pair(start, start));
    node[start].dis = start;

    pair<int, int> u;
    while(not q.empty()){
        u = q.top(); q.pop();
        int cost = u.first;
        int current = u.second;

        rep(i,g[current].size()){
            int next = g[current][i].to;
            if(node[next].dis < cost){
                node[next].dis = cost;
                q.push(make_pair( min(next, cost), next));
            }
        }
    }
    rep(i,n){
        if(node[i].dis >= i){
            cout << i + 1 << endl;
        }
    }
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<Node> node(n);
    AdjList g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].emplace_back(Edge{b,0});
        g[b].emplace_back(Edge{a,0});
    }
    dijkstra(g,s - 1, n);
}
