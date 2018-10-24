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
	int n, p;
	cin >> n >> p;

	vector<long long> a(n);
	cin >> a;

	long long cur = 1;
	int right = 0, left = 0;
	while(true){
		while(cur < p and right < n){
			cur *= a[right];
			right++;
		}
		if(cur < p) break;
		
		if(cur == p){
			cout << "Yay!" << endl;
			return 0;
		}
		while(cur > p and left < n){
			cur /= a[left];
			left++;
		}
		if(cur == p){
			cout << "Yay!" << endl;
			return 0;
		}
	}
	cout << ":(" << endl;
}
