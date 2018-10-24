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
	bool isEven;
	cout << "? 2" << endl;

	string s;
	cin >> s;
	if(s == "even") isEven = true;
	else isEven = false;

	int right = 1e9, left = 1;
	rep(i,29){
		int mid = (right + left) / 2;
		if(mid % 2 == 0) mid++;

		cout << "? " << mid << endl;
		cin >> s;
		if(s == (isEven ? "even" : "odd")) right = mid;
		else left = mid;
	}
	if(isEven and left == 1e9 - 1) cout << "! 1000000000" << endl;
	else cout << "! " << (isEven ? right-1 : left) << endl;

}
