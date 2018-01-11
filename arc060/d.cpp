#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

bool check(long long b, long long n, long long s){
    if(b < 2) return 0;

    long long sum = 0;
    while(n != 0){
        sum += n % b;
        n /= b;
    }
    return sum == s;
}

int main(){
    long long n, s;
    cin >> n >> s;

    range(i,2,sqrt(n) + 1){
        if(check(i,n,s)){
            cout << i << endl;
            return 0;
        }
    }

    long long ans = LLONG_MAX;
    if(n == s) ans = n + 1;
    range(i,1,sqrt(n) + 1){
        if(check((n - s) / i + 1, n, s)){
            ans = min(ans, (n - s) / i + 1);
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}
