#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int n, k;
bool dp[5005][5005];
int a[5005];

bool C(int mid){
    if(mid >= n) return true;
    else if(mid < 0) return false;

    dp[0][0] = 1;
    rep(i,n){
        for(int j = k; j >= 0; j--){
            dp[i + 1][j] |= dp[i][j];
            if(i != mid) dp[i + 1][min(k, j + a[i])] |= dp[i][j];
        }
    }

    range(i,max(0,k - a[mid]),k){
        if(dp[n][i]) return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    rep(i,n) cin >> a[i];
    sort(a, a + n);

    int right = n, left = -1;
    rep(i,20){
        int mid = (right + left ) / 2;
        if(C(mid)) right = mid;
        else left = mid;
    }
    if(left == n) cout << n << endl;
    else if(left == -1) cout << 0 << endl;
    else cout << left + 1 << endl;
}
