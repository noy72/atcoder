#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const double INF = 1e8;
using namespace std;

struct Data{
    double x, y, t, r;
};

class Edge{
    public:
        int to;
        double cost;
        Edge(int to, double cost) : to(to) ,cost(cost) {}
};

class Node{
    public:
        double dis;
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

double dijkstra(AdjList g, int start, int n){
    vector<Node> node(n);
    priority_queue<int, vector<pair<double, int>>, greater<pair<double, int>>> q;

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
    sort(all(node));
    //rep(i,n){ show(node[i].dis) }

    double ret = 0;
    range(i,1,n){
        ret = max(ret, node[i].dis + n - i - 1);
    }
    return ret;
}

double pow(double a){
    return a * a;
}

int main(){
    int n;
    cin >> n;

    Data d[1005];
    rep(i,n){
        double x, y, t, r;
        cin >> x >> y >> t >> r;
        d[i] = Data{x,y,t,r};
    }

    AdjList g(n);
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            g[i].emplace_back(Edge{j, sqrt( pow(d[i].x - d[j].x) + pow(d[i].y - d[j].y)) / min(d[j].r, d[i].t)});
            //cout << i << ' ' << j << endl;
            //show(g[i].back().cost)
        }
    }
    cout <<fixed << setprecision(10)<< dijkstra(g,0,n) << endl;
}
