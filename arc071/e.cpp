#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

struct Data{
    int a[100005], b[100005];
    int n;
    Data(){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
    void cul(){
        range(i,1,n + 1){
            a[i + 1] += a[i];
            b[i + 1] += b[i];
        }
    }
    void set(int _n){
        n = _n;
    }
    pair<int, int> get(int i, int j){
        return make_pair(a[j] - a[i], b[j] - b[i]);
    }
    void output(){
        rep(i,n + 1){ cout << a[i] << ' '; }
        cout << endl;
        rep(i,n + 1){ cout << b[i] << ' '; }
        cout << endl;
    }
};

int main(){
    Data s,t;
    {
        string x, y;
        cin >> x >> y;
        rep(i,x.size()){
            if(x[i] == 'A') s.a[i + 1]++;
            else s.b[i + 1]++;
        }
        rep(i,y.size()){
            if(y[i] == 'A') t.a[i + 1]++;
            else t.b[i + 1]++;
        }
        s.set(x.size());
        t.set(y.size());
    }
    s.cul();
    t.cul();
    //s.output();
    //t.output();


    int q;
    cin >> q;
    rep(i,q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pair<int, int> x = s.get(a - 1, b);
        pair<int, int> y = t.get(c - 1, d);
        bool f = true;
        rep(_,300){
            //show(_)
            //cout << x.first << ' ' << x.second << endl;
            //cout << y.first << ' ' << y.second << endl;
            if(y.second > x.second){
                int dif = max(1, min((y.second - x.second) / 2, x.first));
                x.first -= dif;
                x.second += dif * 2;
            }
            if(y.first > x.first){
                int dif = max(1, min((y.first - x.first) / 2, x.second));
                x.second -= dif;
                x.first += dif * 2;
            }
            if(y.first < x.first && (x.first - y.first) % 3 == 0 && x.first >= 3){
                int dif = x.first - y.first;
                x.first -= dif / 3 * 3;
            }
            if(y.second < x.second && (x.second - y.second) % 3 == 0 && x.second >= 3){
                int dif = x.second - y.second;
                x.second -= dif / 3 * 3;
            }
            if(x == y) break;
            if(x.first >= 1 && x.second >= 1){
                if(f){
                    x.first--;
                    x.second += 2;
                    f = false;
                }else{
                    x.first += 2;
                    x.second--;
                    f = true;
                }
            }else if(x.first >= 1){
                x.first--;
                x.second += 2;
            }else if(x.second >= 1){
                x.first += 2;
                x.second--;
            }
        }
        cout << (x == y ? "YES" : "NO") << endl;
    }
}
