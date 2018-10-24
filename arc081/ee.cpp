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

int main(){
	string s;
	cin >> s;

	vector<vector<int>> a(26);
	rep(i,s.size()) a[ s[i] - 'a' ].emplace_back(i);

	set<char> st;
	vector<int> c;
	for(int i = s.size() - 1; i >= 0; i--){
		st.emplace(s[i]);
		if(st.size() == 26){
			st.clear();
			c.emplace_back(i);
		}
	}
	reverse(all(c));

	if(c.size() == 0){
		rep(i,26){
			if(not st.count(i + 'a')){
				printf("%c\n", i + 'a');
				return 0;
			}
		}
	}

	int pos = -1;
	string ans;
	rep(_,c.size() + 1){
		rep(i,26){
			auto p = lower_bound(all(a[i]), pos);
			if(p == a[i].end() or lower_bound(all(c), pos) - c.begin() == lower_bound(all(c), *p + 1) - c.begin() - 1){
				ans += 'a' + i;
				pos = *p + 1;
				break;
			}
		}
	}
	cout << ans << endl;
}
