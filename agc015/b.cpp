#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
    string s;
    cin >> s;

    long long ans = 0;
    rep(i,s.size()){
        if(s[i] == 'U'){
            ans += s.size() - 1 - i;
            ans += i * 2;
        }else{
            ans += (s.size() - 1 - i) * 2;
            ans += i;
        }
    }
    cout << ans << endl;
}
