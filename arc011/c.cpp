#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

const int N = 1005;

int M[N][N];

vector<string> bfs(int n, vector<string> v){
    pair<int, int> dis[N]; //距離, 前回の点
    queue<int> q; //訪問した点
    rep(i,N) dis[i] = make_pair(INF,-1);

    dis[0] = make_pair(0,-1);
    q.push(0);

    while(!q.empty()){
        int u;
        u = q.front(); q.pop();
        rep(i,v.size()){
            if(M[u][i] && dis[i].first == INF){
                dis[i] = make_pair(dis[i].first + 1, u); //グラフの深さ 
                q.push(i);
            }
        }
    }


    vector<string> ret;
    if(dis[1].first == INF) return ret;

    ret.emplace_back(v[1]);
    int u = dis[1].second;
    while(u != -1){
        ret.emplace_back(v[u]);
        u = dis[u].second;
    }
    return ret;
}

bool nearString(string a, string b){
    int dif = 0;
    rep(i,a.size()){
        if(a[i] != b[i]) dif++;
    }
    return dif <= 1;
}

int main(){
    string s, g;
    int n;
    cin >> s >> g >> n;

    vector<string> v;
    v.emplace_back(s);
    v.emplace_back(g);
    rep(i,n){
        string inp;
        cin >> inp;
        v.emplace_back(inp);
    }

    rep(i,v.size()){
        rep(j,v.size()){
            if(nearString(v[i], v[j])){
                //cout << v[i] << ' ' << v[j] << endl;
                M[i][j] = true;
            }
        }
    }
    
    vector<string> ans = bfs(n,v);
    if(ans.size() == 0){
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() - 2 << endl;
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << endl;
    }
    //cout << g << endl;
}
