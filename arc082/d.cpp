#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

bool check(int n, int p[100005]){
    rep(i,n){
        if(p[i] == i + 1) return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;

    int p[100005];
    rep(i,n){
        cin >> p[i];
        p[i]--;
    }

    int cnt = 0;
    rep(i,n){
        if(p[i] == i){
            if(i + 1 < n && p[i + 1] == i + 1){
                cnt++;
                i++;
                continue;
            }
            cnt++;
        }
    }
    cout << cnt << endl;
}
