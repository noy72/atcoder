#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
using namespace std;
const long long INF = (1LL << 62);

long long r, b, x, y;
long long ans = 0;

long long C(long long mid, long long r, long long b){
    long long res = 0;
    res += mid;
    r -= mid * x;
    b -= mid;
    if(mid < 0) return -INF;
    if(r < 0) return -INF;
    if(b < 0) return -INF;
    res += min(b / y, r);
    ans = max(ans, res);
    return res;
}

void ternarySearch(long long r, long long b){
    long long right = INF, left = 0;
    rep(i,300){
        long long llr = (left * 2 + right) / 3;
        long long rll = (left + right * 2) / 3;
        if(C(llr,r,b) < C(rll,r,b)){
            left = llr;
        }else{
            right = rll;
        }
    }
}

inline bool C(long long k){
    if(r - k < 0) return 0;
    if(b - k < 0) return 0;
    return ((r - k) / (x - 1) + (b - k) / (y - 1) >= k);
}

int main(){
    cin >> r >> b >> x >> y;
    //ternarySearch(r,b);

    long long  right = INF, left = 0;
    rep(i,300){
        long long mid = (right + left ) / 2;
        if(C(mid)) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
