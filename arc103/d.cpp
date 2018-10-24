#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

int main() try{
	int n;
	cin >> n;

	vector<pair<int, int>> p(n);
	rep(i,n){
		cin >> p[i].first >> p[i].second;
		if(p[i].first < 0) p[i].first *= -1;
		if(p[i].second < 0) p[i].second *= -1;
	}
	sort(all(p));

	vector<int> w, s;
	rep(i,n){
		int mini = INT_MAX;
		rep(j,i){
			if(p[i].second == 0) continue;
			mini = min(mini, p[i].second);
		}
		range(j,i,n){
			if(p[i].first == 0) continue;
			mini = min(mini, p[i].first);
		}

		w.emplace_back(mini);
		s.emplace_back(w.size());
		range(j,i,n){
			p[i].first -= mini;
		}
	}

}catch(...){
	cout << -1 << endl;
}
