#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;
 
const double INF = 1e8;
 
map<string,vector<pair<string, double>>> m; //今の単位、pair(変換先、コスト)
 
void bfsMaxDiff(int n, string start){
    map<string, double> dis; //距離
    queue<string> q; //訪問した点を入れる
 
    dis[start] = 1;
    q.push(start);
 
    string u;
    while(!q.empty()){
        u = q.front(); q.pop();
        for(auto v:m[u]){
            if(not dis.count(v.first)){
                dis[v.first] = dis[u] * v.second;
                q.push(v.first);
            }
        }
    }
 
    double maxi = 0, mini = INF;
    pair<string, string> p;
    for(auto it:dis){
        //cout << it.first << ' ' << it.second << endl;
        if(maxi < it.second){
            maxi = it.second;
            p.second = it.first;
        }
        if(mini > it.second){
            mini = it.second;
            p.first = it.first;
        }
    }
 
    cout << '1' << p.first << '=' << static_cast<int>(maxi / mini + 0.5) << p.second << endl;
}
 
int main(){
    int n;
    cin >> n;
 
    rep(i,n){
        string cur, to;
        double cost;
        cin >> cur >> cost >> to;
        m[cur].emplace_back(make_pair(to, cost));
        m[to].emplace_back(make_pair(cur, 1.0 / cost));
    }
 
    bfsMaxDiff(m.size(), m.begin()->first);
}
