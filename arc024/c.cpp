#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

string toStr(int n){
    if(n == 0) return "0";
    string str;
    int len = static_cast<int>(log10(n));
    int K = 1;
    rep(i,len) K*=10;
    rep(i,len + 1){
        if(n / K == 0) str+= '0';
        else str+= ('0' + n / K);
        n%=K; K/=10;
    }
    return str;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    string str;
    cin >> n >> k >> str;

    unordered_map<string, int> m;

    bool f = false;
    int a[30] = {0};
    rep(i,k - 1) a[str[i] - 'a']++;
    range(i,k - 1,str.size()){
        a[str[i] - 'a']++;
        //for(auto it:s) cout << it; cout << endl;

        string s;
        rep(j,'z' - 'a' + 1) s += toStr(a[j]);
        if(m.count(s)){
            if(i - m[s] >= k){
                f = true;
                break;
            }
        }else m[s] = i;
        a[str[i - k + 1] - 'a']--;
    }

    auto YesOrNo = [](bool f) { cout << (f ? "YES" : "NO") << endl; };
    YesOrNo(f);
}
