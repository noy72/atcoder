#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const long long M = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;

    vector<long long> x(n), y(m);
    rep(i,n){ cin >> x[i]; }
    rep(i,m){ cin >> y[i]; }

    long long xlen = 0, ylen = 0;
    rep(i,n) (xlen += i * x[i] - (n - i - 1) * x[i]) %= M;
    rep(i,m) (ylen += i * y[i] - (m - i - 1) * y[i]) %= M;

    cout << xlen * ylen % M << endl;
}
