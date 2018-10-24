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

template<typename T>
class CumulativeSum {
	vector<T> a;
	public:
	CumulativeSum(vector<T>& x) : a(x.size() + 1,0) {
		rep(i,x.size()){
			a[i + 1] = a[i] + x[i];
		}
	}
	T get(int l, int r){ // [l, r]の区間の合計を求める
		if(l < 0 or r < 0) return 0;
		if(l >= r) return 0;
		return a[r + 1] - a[l];
	}
	T operator [] (const int i) const {
		return a[i];
	}
};

int main(){
	int n;
	cin >> n;

	vector<char> a(n);
	cin >> a;

	vector<int> e(n, 0), w(n, 0);
	rep(i,a.size()){
		if(a[i] == 'W'){
			w[i]++;
		}else{
			e[i]++;
		}
	}

	CumulativeSum<int> E(e), W(w);

	int ans = 1e9;
	rep(i,n){
		ans = min(ans, W.get(0, i - 1) + E.get(i + 1, n - 1));
		//cout << i << ' ' << ans << endl;
	}
	cout << ans << endl;
}
