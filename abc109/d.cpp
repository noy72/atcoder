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

int main(){
	int h, w;
	cin >> h >> w;

	vector<vector<int>> v(h, vector<int>(w));
	rep(i,h){
		rep(j,w){
			cin >> v[i][j];
		}
	}

	vector<tuple<int,int,int,int>> ans;
	int y, x;
	bool p = false;

	auto f = [&](int i, int j){
		if(p){
			ans.emplace_back(y, x, i, j);
			p = false;
		}else{
			y = i;
			x = j;
			p = true;
		}
	};
	auto g = [&](int i, int j){
		ans.emplace_back(y, x, i, j);
		y = i;
		x = j;
	};

	rep(i,h){
		if(i % 2){
			for (int j = w - 1; j >= 0; j--) {
				if(v[i][j] % 2) f(i,j);
				else if(p) g(i,j);
			}
		}else{
			rep(j,w){
				if(v[i][j] % 2) f(i,j);
				else if(p) g(i,j);
			}
		}
	}

	cout << ans.size() << endl;
	for(auto pp : ans){
		int a, b, c, d;
		tie(a,b,c,d) = pp;
		a++; b++; c++; d++;
		cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	}
}
