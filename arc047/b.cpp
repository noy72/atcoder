#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
using namespace std;

const double INF = 2000000000;

typedef struct {
    int x, y;
} P;

int main(){
    int n;
    cin >> n;

    P p[100005];
    int max_x = -INF, max_y = -INF, min_x = INF, min_y = INF;
    rep(i,n){
        cin >> p[i].x >> p[i].y;
        max_x = max(max_x, p[i].x + p[i].y);
        max_y = max(max_y, p[i].x - p[i].y);
        min_x = min(min_x, p[i].x + p[i].y);
        min_y = min(min_y, p[i].x - p[i].y);
    }
    int dis = max(max_x - min_x, max_y - min_y);
    vector<P> v;
    int x[2] = {max_x - dis / 2, dis / 2 + min_x};
    int y[2] = {max_y - dis / 2, dis / 2 + min_y};
    rep(i,2) rep(j,2) v.emplace_back(P{(x[i] + y[i]) / 2, (x[i] - y[i]) / 2});

    rep(i,v.size()){
        map<int,bool> m;
        rep(j,n){
            m[abs(v[i].x - p[j].x) + abs(v[i].y - p[j].y)] = true;
        }
        if(m.size() == 1){
            cout << v[i].x << ' ' << v[i].y << endl;
            return 0;
        }
    }
    return -1;
}
