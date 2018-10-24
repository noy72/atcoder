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

vector<int> divisor(int n){
	vector<int> res;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			res.emplace_back(i);
			if(i != n / i) res.emplace_back(n / i);
		}
	}
	return res;
}

int main(){
	int n;
	cin >> n;

	int ans = 0;
	for(int i = 1; i <= n; i += 2){
		ans += divisor(i).size()  == 8;
	}
	cout << ans << endl;
}
