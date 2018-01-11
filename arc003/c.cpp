#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

struct Point{ int x, y; };
int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
const int N = 505;

char c[N][N];

//x^n mod M
double power(double x, int n){
    double res = 1;
    if(n > 0){
        res = power(x, n / 2);
        if(n % 2 == 0) res = (res * res);
        else res = res * res * x;
    }
    return res;
}

bool bfs(int h, int w, Point p, double limit){
    int dis[N][N];
    queue<Point> q;
    rep(i,N) rep(j,N) dis[i][j] = INF;

    dis[p.y][p.x] = 0;
    q.push(p);

    Point u;
    while(not q.empty()){
        u = q.front(); q.pop();
        rep(i,4){
            Point next;
            next.x = u.x + dx[i];
            next.y = u.y + dy[i];
            if(next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
            if(c[next.y][next.x] == '#') continue;
            else if(c[next.y][next.x] == 'g'){
                return true;
            }

            double next_brightness = (c[next.y][next.x] - '0') * power(0.99, dis[u.y][u.x] + 1);
            if(next_brightness > limit && dis[next.y][next.x] > dis[u.y][u.x] + 1){
                dis[next.y][next.x] = dis[u.y][u.x] + 1;
                //show(dis[next.y][next.x].first)
                q.push(next);
            }
        }
    }
    //rep(i,h){ rep(j,w){ cout << dis[i][j].first << ' '; } cout << endl; } cout << endl;
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    Point s,g;
    rep(i,n){
        rep(j,m){
            cin >> c[i][j];
            if(c[i][j] == 's') s = Point{j,i};
            else if(c[i][j] == 'g') g = Point{j,i};
        }
    }
    if(not bfs(n,m,s,-1)){
        cout << -1 << endl;
        return 0;
    }

    double right = 10, left = 0;
    rep(i,100){
        double mid = (right + left ) / 2;
        if(bfs(n,m,s,mid)) left = mid;
        else right = mid;
    }
    cout << fixed << setprecision(10) << left << endl;
}
