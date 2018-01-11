#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
    int n, p;
    cin >> n >> p;

    pair<int, int> a[5005];
    rep(i,n) cin >> a[i].first >> a[i].second;
    sort(a, a + n, greater<pair<int, int>>());

    vector<int> dp(5200,0);
    rep(i,n){
        for(int j = p; j >= 0; j--){
            dp[j + a[i].first] = max(dp[j + a[i].first], dp[j] + a[i].second);
        }
        //for(int j = 0; j <= p + 100; j+=10){ cout << dp[j] << (j == p + 100 ? '\n' : ' '); }
    }

    cout << *max_element(all(dp)) << endl;
}
