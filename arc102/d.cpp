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

//i番目のビットを返す
bool getBit(int num, int i){
	return ((num & (1 << i)) != 0);
}

//i番目を1にする
int setBit(int num, int i){
	return num | (1 << i);
}

//i番目を0にする
int clearBit(int num, int i){
	int mask = ~(1 << i);
	return num & mask;
}

//i番目をvで置き換える
int updateBit(int num, int i, int v){
	int mask = ~(1 << i);
	return (num & mask) | (v << i);
}

int main(){
	int L;
	cin >> L;

	int k = log2(L);

	vector<tuple<int,int,int>> e;
	int t = 1;
	rep(i,k){
		e.emplace_back(i, i + 1, t);
		e.emplace_back(i, i + 1, 0);
		t *= 2;
	}

	int p = 1;
	rep(_,k) p*=2;

	for(int i = k; i >= 0; i--){
		if(L == 0) break;
		if(L - p >= t){
			e.emplace_back(i, k, L - p);
			L -= p;
		}
		p/=2;
	}

	cout << k + 1 << ' ' << e.size() << endl;
	for(auto i : e){
		int u, v, c;
		tie(u, v, c) = i;
		cout << u + 1 << ' ' << v + 1 << ' ' << c << endl;
	}
}
