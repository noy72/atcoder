#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int MAX_N = 100005;

bool check(int s, int t, vector<bool> u, vector<int> v[MAX_N]){
	for(auto i : v[s]){
		if(u[i] == false){
			return true;
		}
	}
	for(auto i : v[t]){
		if(u[i] == false){
			return true;
		}
	}
	return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v[MAX_N];
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

	list<int> ans;
	vector<bool> used(n,0);
	int s = 0, t = 0;
	used[0] = true;
	ans.emplace_back(0);
	while(check(s,t, used, v)){
		bool f = false;
		for(auto i : v[t]){
			if(not used[i]){
				t = i;
				used[i] = true;
				f = true;
				ans.emplace_back(i);
				break;
			}
		}
		if(f) continue;
		for(auto i : v[s]){
			if(not used[i]){
				s = i;
				used[i] = true;
				ans.emplace_front(i);
				break;
			}
		}
	}

	cout << ans.size() << endl;
	for(auto i = ans.begin(); i != ans.end(); i++){
		if(i != ans.begin()) cout << ' ';
		cout << *i + 1;
	}
	cout << endl;
}
