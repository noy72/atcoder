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

	vector<int> a(n);
	cin >> a;

	map<int,int> odd, even;
	rep(i,n){
		if(i % 2){
			odd[a[i]]++;
		}else{
			even[a[i]]++;
		}
	}

	vector<pair<int, int>> x, y;
	for(auto i : odd) x.emplace_back(i.second, i.first);
	for(auto i : even) y.emplace_back(i.second, i.first);

	sort(all(x), greater<pair<int, int>>());
	sort(all(y), greater<pair<int, int>>());

	int cost = n;
	if(x.front().second != y.front().second){
		cost -= x.front().first + y.front().first;
	}else{
		int p = x.front().first + y[1].first;
		int q = x[1].first + y.front().first;
		cost -= max(p, q);
	}
	cout << cost << endl;
}
