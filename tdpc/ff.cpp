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

const int M = 1000000007;

struct RAQ{
	using T = long long;
	T operator()(const T &a, const T &b) { return ((a + b) % M + M) % M; };
	static constexpr T identity() { return 0; }
};

template<class Monoid>
class rangeAddQuery{
	private:
		using T = typename Monoid::T;
		Monoid op;
		const int n;
		vector<T> dat, lazy;
		T query(int a, int b, int k, int l, int r){
			if(b <= l || r <= a) return op.identity();
			else if(a <= l && r <= b) return ((dat[k] * (r - l) % M + lazy[k]) + M) % M;
			else{
				T res = (min(b,r) - max(a,l)) * dat[k] % M;
				res += query(a, b, k * 2, l, (l + r) / 2);
				res %= M;
				res += query(a, b, k * 2 + 1, (l + r) / 2, r);
				res %= M;
				return res;
			}
		}
		void add(int a, int b, int k, int l, int r, T x){
			if(a <= l && r <= b){
				((dat[k] += x) +=M ) %= M;
			}else if(l < b && a < r){
				lazy[k] += ((min(b,r) - max(a,l)) * x % M + M) % M;
				add(a, b, k * 2, l, (l + r) / 2, x);
				add(a, b, k * 2 + 1, (l + r) / 2, r, x);

			}
		}
		int power(int n){
			int res = 1;
			while(n >= res) res*=2;
			return res;
		}
	public:
		rangeAddQuery(int n) : n(power(n)), dat(4 * n, op.identity()), lazy(4 * n, op.identity()) {}
		rangeAddQuery(const vector<T> &v) : n(power(v.size())), dat(4 * n), lazy(4 * n, op.identity()){
			copy(begin(v), end(v), begin(dat) + n);
			for(int i = n - 1; i > 0; i--) dat[i] = op(dat[2 * i], dat[2 * i + 1]);
		}
		T query(int a, int b){ return query(a,b,1,0,n); }
		void add(int s, int t, T x){ add(s, t, 1, 0, n, x); }
		T get(int a){ return query(a, a + 1); };
		void out(){
			rep(i,n * 2){ cout << dat[i + 1] << ' '; } cout << endl;
		}
};

int main(){
	int n, k;
	//range(i,2,1000001){ n = 1000000; k = i;
	cin >> n >> k;
	k--;

	rangeAddQuery<RAQ> seg(n);
	seg.add(0,1,1);
	rep(i,n){
		if(i - k >= 0){
			seg.add(i, i + 1, -seg.get(i - k));
		}
		seg.add(i + 1, n + 1, seg.get(i));
		//rep(i,n){ cout << seg.get(i) <<  ' '; } cout << endl;
	}
	//if(seg.get(n - 1) < 0) cout << k + 1  << endl;

	assert(seg.get(n - 1) >= 0);
	cout << seg.get(n - 1) % M << endl;
	//}
}
