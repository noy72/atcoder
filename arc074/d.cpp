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

    long long a[300005];
    rep(i,n * 3){
        cin >> a[i];
    }
    priority_queue<long long, vector<long long>, greater<long long>> s;
    priority_queue<long long> t;
    long long s_sum = 0, t_sum = 0;
    rep(i,n){
        s.push(a[i]);
        s_sum += a[i];
    }

    for(int i = n * 3 - 1; i >= n + n; i--){
        t.push(a[i]);
        t_sum += a[i];
    }


    long long s_max[100005], t_min[100005];
    s_max[0] = s_sum;
    range(i,n,n + n){
        s_sum += a[i];
        s.push(a[i]);
        s_sum -= s.top();
        s.pop();
        s_max[i - n + 1] = s_sum;
    }

    t_min[0] = t_sum;
    for(int i = n + n - 1; i >= n; i--){
        t_sum += a[i];
        t.push(a[i]);
        t_sum -= t.top();
        t.pop();
        t_min[n + n - i] = t_sum;
    }
    //rep(i,n + 1){ show(s_max[i]) }
    //rep(i,n + 1){ show(t_min[i]) }

    long long ans = -(1LL << 60);
    rep(i,n + 1){
        ans = max(ans, s_max[i] - t_min[n - i]);
    }

    cout << ans << endl;
}
