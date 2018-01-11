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

    map<char,vector<int>> m;
    rep(i,s.size()){ m[s[i]].emplace_back(i); }

    vector<int> v;
    set<char> st;
    for(auto it = s.rbegin(); it != s.rend(); it++){
        st.insert(*it);
        if(st.size() == 26){
            v.emplace_back(s.rend() - it - 1);
            st.clear();
            //show(v.back())
        }
    }
    reverse(all(v));

    string ans;
    int cur = -1;
    rep(i,v.size() + 1){
        for(char j = 'a'; j != 'z' + 1; j++){
            auto p = lower_bound(all(m[j]), cur);
            if(p == m[j].end()){
                ans += j;
                break;
            }
            //show(*p)
            //    show(v.size() - distance(v.begin(), lower_bound(all(v), cur)))
            //    show(v.size() - distance(v.begin(), lower_bound(all(v), *p + 1)))
            if(v.size() - distance(v.begin(), lower_bound(all(v), cur)) == 
                    v.size() - distance(v.begin(), lower_bound(all(v), *p + 1)) + 1){
                ans += j;
                cur = *p + 1;
                break;
            }
        }
    }
    //if(ans.size() == 0) rep(i,v.size() + 1) ans += 'a';
    cout << ans << endl;
}
