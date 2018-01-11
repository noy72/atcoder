#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int l, q;
    cin >> l >> q;

    vector<int> dp[20];
    rep(i,20) dp[i] = vector<int>(100005);
    rep(i,n){
        dp[0][i] = distance(a.begin(), upper_bound(all(a), a[i] + l)) - 1;
        //cout << dp[0][i] << endl;
    }

    rep(k,20 - 1){
        rep(i,n){
            dp[k + 1][i] = dp[k][ dp[k][i] ];
        }
    }

    rep(i,q){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a > b) swap(a,b);
        //show("JI")
        //cout << a << ' ' << b << endl;

        int ans = 0;
        for(int j = 19; j >= 0; j--){
            //cout << j << ' ' << (1 << j) << endl;
                //cout << a << ' ' <<b << ' ' <<  dp[j][a] << endl;


            if(dp[j][a] < b){ //移動可能
                a = dp[j][a];
                ans += 1 << j;
            }
        }
        cout << ans + 1 << endl;
    }
}
