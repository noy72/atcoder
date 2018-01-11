#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;

    queue<int> q;
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            q.push(i + 1);
        }

    }

    int c[105][105];
    rep(i,w){
        if(i % 2){
            for(int j = h - 1; j >= 0; j--){
                c[j][i] = q.front(); q.pop();
            }
        }else{
            rep(j,h){
                c[j][i] = q.front(); q.pop();
            }
        }
    }

    rep(i,h){
        rep(j,w){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
}
