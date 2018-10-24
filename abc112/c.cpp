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
	int n;
	cin >> n;

	vector<int> x(n), y(n), h(n);
	int p = -1;
	rep(i,n){
		cin >> x[i] >> y[i] >> h[i];
		if(h[i] != 0) p = i;
	}
	assert(p != -1);

	range(cx,0,101){
		range(cy,0,101){
			int high = h[p] + abs(x[p] - cx) + abs(y[p] - cy);

			auto f = [&](){
				rep(i,n){
					if(max(high - abs(x[i] - cx) - abs(y[i] - cy), 0) != h[i]){
						return false;
					}
				}
				return true;
			};
			if(f()){
				cout << cx << ' ' << cy << ' ' << high << endl;
				return 0;
			}
		}
	}
	assert(false);
}
