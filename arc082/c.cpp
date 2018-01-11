#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
    int n;
    cin >> n;

    map<int,int> m;
    rep(i,n){
        int a;
        cin >> a;
        range(j,-1,2) m[a + j]++;
    }

    int ans = 0;
    for(auto it : m){
        ans = max(ans, it.second);
    }
    cout << ans << endl;
}

