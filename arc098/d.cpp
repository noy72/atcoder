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

template<typename T>
class CumulativeSumXor {
	vector<T> a;
	public:
	CumulativeSumXor(vector<T>& x) : a(x.size() + 1,0) {
		rep(i,x.size()){
			a[i + 1] = a[i] ^ x[i];
		}
	}
	T get(int l, int r){ // [l, r]の区間の合計を求める
		return a[r + 1] ^ a[l];
	}
	T operator [] (const int i) const {
		return a[i];
	}
};

bool C(int l, int r, CumulativeSum<int>& s, CumulativeSumXor<int>& x){
	//cout << l << ' ' << r << ' ' << s.get(l,r) << ' ' << x.get(l,r) << endl;
	return s.get(l,r) == x.get(l,r);
}

int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	cin >> a;

	CumulativeSum<int> s(a);
	CumulativeSumXor<int> x(a);

	long long ans = 0;
	rep(i,n){
		//show(i)
		long long right = n, left = i;
		rep(j,30){
			long long mid = (right + left) / 2;
			//cout << left << ' ' << right << endl;
			if(C(i, mid, s, x)) left = mid;
			else right = mid;
		}

		//cout << left << ' ' << i << endl;
		ans += left - i + 1;
	}
	cout << ans << endl;
}
