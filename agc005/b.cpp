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

    int m[200005]; //num, pos
    rep(i,n){
        int a;
        cin >> a;
        m[a] = i;
    }

    set<int> pos;
    pos.insert(-1);
    pos.insert(n);
    long long ans = 0;
    range(i,1,n + 1){
        int cur = m[i];

        auto it = pos.upper_bound(cur);
        int left = cur - *prev(it,1);
        //show(left)
        long right = *it - cur;
        //show(right)

        ans += 1LL * left * right * i;
        //show(ans)
        pos.emplace(cur);
    }
    cout << ans << endl;
}
