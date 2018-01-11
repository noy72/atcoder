#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    rep(i,n){
        long long from = a + c * i - d * (n - i - 1); //小さく上がって大きく下がる
        long long to = a + d * i - c * (n - i - 1);
        if(from <= b  && b <= to){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}
