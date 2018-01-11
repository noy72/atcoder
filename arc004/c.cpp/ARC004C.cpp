#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

long long gcd(long long x, long long y) {
    long long r;
    if(x < y) swap(x, y);

    while(y > 0){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long x, y;
    char g;
    cin >> x >> g >> y;

    long long GCD = gcd(x,y);
    x /= GCD;
    y /= GCD;

    bool f = false;
    long long t = x * 2 / y - 1;
    if(t * y >= 2 * x - y) t++;
    for(long long n = max(1LL, t); n <= x * 2 / y + 1; n++){
        long long temp = (n + 1) * y - 2 * x;
        if(temp < 0) continue;
        if( (n * temp) % (2 * y) == 0){
            if(n < temp * n / (2 * y)) continue;
            cout << n << ' ' << temp * n / (2 * y) << endl;
            f = true;
        }
    }
    if(not f) cout << "Impossible" << endl;
}
