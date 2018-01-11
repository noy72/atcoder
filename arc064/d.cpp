#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

map<list<char>, int> m;

int dfs(list<char> ls){
    if(m.count(ls)) m[ls];

    set<int> ret;
    auto end = --ls.end();
    for(auto it = ++ls.begin(); it != end; it++){
        if(*prev(it, 1) != *it && *prev(it, 1) != *next(it, 1) && *it != *next(it, 1)){
            //for(auto i:ls){ cout << i << ' '; } cout << endl;
            char foo = *it;
            it = ls.erase(it);
            ret.emplace(dfs(ls));
            ls.insert(it, foo);
            //it++;
            --it;
        }
    }

    rep(i,1e8) if(not ret.count(i)) return m[ls] = i;
    return 1e8;
}

int main(){
    string s;
    cin >> s;
    bool f = (s.front() != s.back()) xor (s.size() % 2 == 0);
    cout << (f ? "First" : "Second") << endl;
}
