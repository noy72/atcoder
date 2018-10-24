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
		return a[r + 1] - a[l];
	}
	T operator [] (const int i) const {
		return a[i];
	}
};

int main(){
	int n, m, q;
	cin >> n >> m >> q;

	vector<int> seg(n, 0); // seg[i] := [0, i] に含まれる区間の数
	vector<int> imos(n, 0); // imos[i] := i 駅で切れる列車
	rep(i,m){
		int l, r;
		cin >> l >> r;
		l--; r--;

		seg[r] += 1;

		if(r - l >= 2){
			cout << l + 1  << ' ' << r - 1 << endl;
			imos[l + 1]++;
			imos[r    ]--;
		}
	}

	CumulativeSum<int> cs(seg), cmos(imos);

	rep(i,n + 1){ cout << cs[i] << ' '; } cout << endl;
	rep(i,n + 1){
		cout << cmos[i] <<  ' ';
	}
	cout << endl;

	rep(i,q){
		int p, q;
		cin >> p >> q;
		p--; q--;

		show(cs.get(p,q))
		cout << cs.get(p, q) - cmos[p + 1] << endl;
	}
}
