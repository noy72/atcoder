#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

typedef unsigned long long ull;
const ull M = 1000000007;

//べき乗 x^n mod M
ull power(ull x, ull n){
    ull res = 1;
    if(n > 0){
        res = power(x, n / 2);
        if(n % 2 == 0) res = (res * res) % M;
        else res = (((res * res) % M) * x ) % M;
    }
    return res;
}

//階乗
ull factorial(ull n, ull r){
    ull res = 1;
    range(i,r,n + 1){
        res*= i;
        res%= M;
    }
    return res;
}

//nCr コンビネーション (1,1)から(w,h)だと、引数は(w - 1, h - 1, M)
ull combination(ull n, ull r){
    //nCr = n! / ( (n - r)! * r! )
    ull a = factorial(n, n - r + 1);
    ull b = factorial(r,1) % M;
    return a * power(b, M - 2) % M;
}

ull solve(ull dif, ull num){
    //show(dif) show(num)
    return combination(dif + num, num);
}

int main(){
    ull n;
    cin >> n;

    vector<int> v;
    rep(i,n){
        int a;
        cin >> a;
        v.emplace_back(a);
    }

    ull ans = 1;
    ull dif = v[0], num = 0; //数字の差、項の数
    range(i,1,n){
        if(v[i] == -1){
            num++;
        }else{
            (ans *= solve(v[i] - dif, num)) %= M;
            num = 0;
            dif = v[i];
        }
    }
    cout << ans << endl;
}
