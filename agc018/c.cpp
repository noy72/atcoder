#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

#define int long long
const int INF = (1LL << 60);

struct Monoid{
	using T = pair<int, int>; //モノイドの台集合の型
	T operator()(const T &a, const T &b) { return a.first > b.first ? a : b; } //二項演算
	static constexpr T identity() { return make_pair(-INF,-INF); } //単位元
};

template<class Monoid>
class SegTree{ //SegTree<Monoid> seg(n);
	private:
		using T = typename Monoid::T; //台集合の型をエイリアス
		Monoid op; //演算の関数オブジェクト
		const int n; //列の長さ
		vector<T> t; //内部二分木

		void prop_to(int i) { //ノードiに伝搬
			t[i] = op(t[2 * i], t[2 * i + 1]);
		}

	public:
		SegTree(int n) : n(n), t(2 * n, op.identity()) {} //単位元で埋める初期化
		SegTree(const vector<T> &v) : n(v.size()), t(2 * n){ //配列を用いて初期化
			copy(begin(v), end(v), begin(t) + n);
			for(int i = n - 1; i > -0; i--) prop_to(i);
		}

		void set(int i, const T &x){
			t[i += n] = x; 
			while(i >>= 1) prop_to(i);
		}

		void add(int i, const int &x){
			pair<int, int> g = get(i);
			g.first += x;
			set(i, g);
		}

		T get(int i) { return t[i + n]; } //列のi番目を返す

		T query(int l, int r){
			T accl = op.identity(), accr = op.identity();
			for(l += n, r += n; l < r; l >>= 1, r >>= 1){
				if(l & 1) accl = op(accl, t[l++]);
				if(r & 1) accr = op(t[r-1], accr);
			}
			return op(accl, accr);
		}
};

signed main(){
	int x, y, z;
	cin >> x >> y >> z;

	int n = x + y + z;

	SegTree<Monoid> sx(n), sy(n), sz(n);
	vector<int> t(n); //1x, 2y, 3z
	vector<int> a(n), b(n), c(n);
	rep(i,x){
		cin >> a[i] >> b[i] >> c[i];
		sx.set(i, make_pair(a[i] - a[i],i));
		sy.set(i, make_pair(b[i] - a[i],i));
		sz.set(i, make_pair(c[i] - a[i],i));
		t[i] = 1;
	}
	range(i,x,y + x){
		cin >> a[i] >> b[i] >> c[i];
		sx.set(i, make_pair(a[i] - b[i],i));
		sy.set(i, make_pair(b[i] - b[i],i));
		sz.set(i, make_pair(c[i] - b[i],i));
		t[i] = 2;
	}
	range(i,x + y,n){
		cin >> a[i] >> b[i] >> c[i];
		sx.set(i, make_pair(a[i] - c[i],i));
		sy.set(i, make_pair(b[i] - c[i],i));
		sz.set(i, make_pair(c[i] - c[i],i));
		t[i] = 3;
	}
	//ちゃんと考えよう

	while(true){
		int maxi, idx;
		tie(maxi, idx) = sx.query(0,n);

		int tmaxi, tidx;
		if(t[idx] == 2){
			tie(tmaxi, tidx) = sy.query(0,n);
		}else if(t[idx] == 3){
			tie(tmaxi, tidx) = sz.query(0,n);
		}else{
			assert(false);
		}

		if(maxi + tmaxi <= 0) break;
		sx.add(idx, -maxi);
		sy.add(idx, -maxi);
		sz.add(idx, -maxi);
		sx.add(tidx, -tmaxi);
		sy.add(tidx, -tmaxi);
		sz.add(tidx, -tmaxi);
		swap(t[idx], t[tidx]);
	}
	while(true){
		int maxi, idx;
		tie(maxi, idx) = sy.query(0,n);

		int tmaxi, tidx;
		if(t[idx] == 1){
			tie(tmaxi, tidx) = sx.query(0,n);
		}else if(t[idx] == 3){
			tie(tmaxi, tidx) = sz.query(0,n);
		}else{
			assert(false);
		}

		if(maxi + tmaxi <= 0) break;
		sx.add(idx, -maxi);
		sy.add(idx, -maxi);
		sz.add(idx, -maxi);
		sx.add(tidx, -tmaxi);
		sy.add(tidx, -tmaxi);
		sz.add(tidx, -tmaxi);
		swap(t[idx], t[tidx]);
	}
	while(true){
		int maxi, idx;
		tie(maxi, idx) = sz.query(0,n);

		int tmaxi, tidx;
		if(t[idx] == 1){
			tie(tmaxi, tidx) = sx.query(0,n);
		}else if(t[idx] == 2){
			tie(tmaxi, tidx) = sy.query(0,n);
		}else{
			assert(false);
		}

		if(maxi + tmaxi <= 0) break;
		sx.add(idx, -maxi);
		sy.add(idx, -maxi);
		sz.add(idx, -maxi);
		sx.add(tidx, -tmaxi);
		sy.add(tidx, -tmaxi);
		sz.add(tidx, -tmaxi);
		swap(t[idx], t[tidx]);
	}

	int ans = 0;
	rep(i,n){
		if(t[i] == 1) ans += a[i];
		else if(t[i] == 2) ans += b[i];
		else if(t[i] == 3) ans += c[i];
	}
	cout << ans << endl;
}
