#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

typedef vector<char> vc;

pair<vc, vc>  getCrossChar(const vector<vc>& s, int i, int j, bool f = 0){
	vc x, y;
	rep(k,s[i].size()){
		x.emplace_back(s[i][k]);
	}

	rep(k,s.size()){
		if(i == k) continue;
		y.emplace_back(s[k][j]);
	}
	sort(all(x));
	if(not f) sort(all(y));

	//cout << x << y << endl;
	return make_pair(x,y);
}

bool check(vector<pair<vc,int>>& c){
	vector<vc> f, s;
	rep(i,c.size() / 2){
		sort(all(c[i].first));
		f.emplace_back(c[i].first);
	}
	range(i,c.size() / 2, c.size()){
		sort(all(c[i].first));
		s.emplace_back(c[i].first);
	}
	sort(all(f));
	sort(all(s));

	rep(i,f.size()){
		rep(j,f[i].size()){
			if(f[i][j] != s[i][j]) return false;
		}
	}
	return true;
}

bool dfs(vector<vc>& s){
	int h = s.size();
	int w = s[0].size();
	//cout << h << ' ' << w << endl; for(auto i : s){ for(auto j : i){ cout << j; } cout << endl; }

	map<vc, vector<pair<vc,int>>> m;
	rep(i,h){
		rep(j,w){
			pair<vc, vc> p = getCrossChar(s, i, j);
			m[p.first].emplace_back(p.second, i);
		}
	}

	if(m.size() == 1){
		map<vc,int> me;
		rep(i,s.size()){
			sort(all(s[i]));
			me[s[i]]++;
		}

		if(h % 2 == 1){
			int odd = 0;
			for(auto i : me){
				if(i.second % 2 == 1) odd++;
			}
			return odd == 1;
		}else{
			for(auto i : me){
				if(i.second % 2 == 1) return false;
			}
			return true;
		}
	}

	if(h % 2 == 1){
		vector<vc> nxt;
		for(auto i : m){
			if(i.second.size() == w){
				rep(j,w){
					nxt.emplace_back(getCrossChar(s, i.second[0].second, j, 1).second);
				}
			}else{
				if(not check(i.second)) {
					//cout << "kisuu chekcfalse " << endl;
					return false;
				}
			}
		}

		return dfs(nxt);
	}else{
		for(auto i : m){
			if(not check(i.second)) {
				//cout << "guusuu checkfalse" << endl;
				return false;
			}
		}
		return true;
	}
}

int main(){
	int h, w;
	cin >> h >> w;

	vector<vc> s(h, vc(w));
	rep(i,h){
		rep(j,w){
			cin >> s[i][j];
		}
	}

	cout << (dfs(s) ? "YES" : "NO") << endl;
}
