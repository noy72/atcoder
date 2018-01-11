#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
    long long a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    n *= 4;

    b = min(2 * a, b);
    c = min(min(4 * a, 2 * b), c);
    d = min(min(8 * a, 4 * b), min(2 * c, d));

    long long ans = 0;
    ans += n / 8 * d;
    n %= 8;
    ans += n / 4 * c;
    n %= 4;
    ans += n / 2 * b;
    n %= 2;
    ans += n * a;

    cout << ans << endl;
}
