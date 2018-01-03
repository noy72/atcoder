#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

struct Monoid{
	using T = int; //モノイドの台集合の型
	T operator()(const T &a, const T &b) { return min(a,b); } //二項演算
	static constexpr T identity() { return INF; } //単位元
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

		void add(int i, const T &x){
			set(i, get(i) * x);
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

vector<int> p, idx;

pair<int, int> minimumIdx(int l, int r, SegTree<Monoid>& even, SegTree<Monoid>& odd){
	if(l >= r) return make_pair(-1,-1);
	int L, R;
	if(l % 2){
		L = idx[odd.query(l, r - 1)]; //閉区間
		R = idx[even.query(L,r)]; // 閉区間
	}else{
		L = idx[even.query(l,r - 1)]; // 閉区間
		R = idx[odd.query(L, r)]; //閉区間
	}
	return make_pair(L,R);
}

pair<int, int> minimum(int l, int r, SegTree<Monoid>& even, SegTree<Monoid>& odd){
	if(l >= r) return make_pair(-1,-1);
	int L, R;
	if(l % 2){
		L = odd.query(l, r - 1); //閉区間
		R = even.query(L,r); // 閉区間
	}else{
		L = even.query(l,r - 1); // 閉区間
		R = odd.query(L, r); //閉区間
	}
	return make_pair(L,R);
}

list<pair<int, int>> bfs(int n, SegTree<Monoid>& even, SegTree<Monoid>& odd){
	typedef pair<int,pair<int, int>> P;
	priority_queue<P, vector<P>, greater<P>> q;

	q.push(make_pair(0, make_pair(0, n)));
	list<pair<int, int>> res;

	while(not q.empty()){
		P t = q.top(); q.pop();

		int l, r;
		tie(l, r) = t.second;
		//cout << l << ' ' << r << endl;

		if(l >= r){
			assert(false);
		}
		if(r - l == 2){
			res.emplace_back(make_pair(p[l], p[l + 1]));
			continue;
		}

		int L, R;
		tie(L, R) = minimumIdx(l, r, even, odd);
		res.emplace_back(make_pair(p[L], p[R]));
		//cout << L << ' ' << R << endl;

		int mini = minimum(l, L, even, odd).first;
		if(mini != -1) q.push(make_pair(mini, make_pair(l, L)));

		mini = minimum(L + 1, R, even, odd).first;
		if(mini != -1) q.push(make_pair(mini, make_pair(L + 1, R)));

		mini = minimum(R + 1, r, even, odd).first;
		if(mini != -1) q.push(make_pair(mini, make_pair(R + 1, r)));

	}

	return res;
}

int main(){
	int n;
	cin >> n;

	p = vector<int>(n);
	idx = vector<int>(n + 1);
	rep(i,n){
		cin >> p[i];
		idx[p[i]] = i;
	}

	SegTree<Monoid> even(n), odd(n);
	rep(i,n){
		if(i % 2){
			odd.set(i, p[i]);
		}else{
			even.set(i, p[i]);
		}
	}
	list<pair<int, int>> ans = bfs(n,even,odd);
	for(auto it = ans.begin(); it != ans.end(); it++){
		if(it != ans.begin()) cout << ' ';
		cout << it->first << ' ' << it->second;
	}
	cout << endl;
}
